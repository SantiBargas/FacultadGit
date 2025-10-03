/*
* Trabajo Pr�ctico de Computaci�n Gr�fica
*               FICH-UNL
* Implementaci�n de Screen Space Ambient Occlusion
* Alvez, Rodrigo
* Saurin, Lucas
* 
* Se tom� como base c�digo de LearnOpenGL.com
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "utils/shader.h"
#include "utils/camera.h"
#include "utils/model.h"
#include "utils/filesystem.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"

#include <iostream>
#include <random>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void renderQuad();

// ventana settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// SSAO
bool SSAO = false, zPressed = false, ssaoSmooth = true, kPressed = false;
int samplesNum = 16; float ssaoRadius = 0.5; float ssaoBias = 0.01; float ssaoIntensity = 1.0;
std::vector<glm::vec3> GenerateSamples(int n = 64);
std::vector<glm::vec3> GenerateRotationNoise();

// DEBUG shader flags
bool DEBUG_Pos = false, unoPressed = false, DEBUG_Normal = false, dosPressed = false, DEBUG_SSAO = false, tresPressed = false, DEBUG_Color = false, cuatroPressed = false;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

// models setting
int currentModel = 0; bool oPressed = false;
std::vector<std::string> models = { "suzanne", "backpack", "deforme", "superficie", "superficie2" };
bool rotateModel = true; float modelAngle = 0.f; bool rPressed = false;

// imgui
bool Combo(const char* label, int* current_item, const std::vector<std::string>& items);

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // window
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "SSAO", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // ---------- imgui interface ----------
    ImGuiContext *imgui_context = ImGui::CreateContext();
    ImGui::SetCurrentContext(imgui_context); // si no es el 1er context, el create no lo define como current
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();

    // glad
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // cargar shaders
    Shader shaderGeometryPass("gbuffer.vert", "gbuffer.frag");
    Shader shaderLightingPass("def_lighting_shader.vert", "def_lighting_shader.frag");
    Shader shaderSSAOPass("ssao_lighting_shader.vert", "ssao_lighting_shader.frag");
    Shader shaderSSAO("ssao_shader.vert", "ssao_shader.frag");
    Shader shaderPos("gPos_shader.vert", "gPos_shader.frag");
    Shader shaderNormal("gNormal_shader.vert", "gNormal_shader.frag");
    Shader shaderColor("gColor_shader.vert", "gColor_shader.frag");
    Shader shaderSSAOViewer("ssaoViewer_shader.vert", "ssaoViewer_shader.frag");

    // load models (Assimp es bastante lento)
    std::cout << "Loading models..." << std::endl;
    Model suzanne(FileSystem::getPath("models/suzanne/suzanne.obj"));
    std::cout << "Loading backpack..." << std::endl;
    Model backpack(FileSystem::getPath("models/backpack/backpack.obj"));
    std::cout << "Loading deforme..." << std::endl;
    Model deforme(FileSystem::getPath("models/deforme/deforme.obj"));
    std::cout << "Loading superficie..." << std::endl;
    Model superficie(FileSystem::getPath("models/superficie/superficie.obj"));
    std::cout << "Loading superficie2..." << std::endl;
    Model superficie2(FileSystem::getPath("models/superficie2/superficie2.obj"));
    std::cout << "Models loaded." << std::endl;

    // model matrix
    glm::vec3 objectPosition(0.0, 0.0, 0.0);
    glm::mat4 model = glm::mat4(1.0f);
    shaderGeometryPass.use();
    model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(0.1f));
    model = glm::translate(model, objectPosition);
    shaderGeometryPass.setMat4("model", model);

    // g-buffer
    unsigned int gBuffer;
    glGenFramebuffers(1, &gBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
    unsigned int gPosition, gNormal, gAlbedo;

        // position buffer
    glGenTextures(1, &gPosition);
    glBindTexture(GL_TEXTURE_2D, gPosition);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gPosition, 0);

        // normal buffer
    glGenTextures(1, &gNormal);
    glBindTexture(GL_TEXTURE_2D, gNormal);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gNormal, 0);
   
        // color + specular color buffer (en caso del modelo tener una textura para la especular)
    glGenTextures(1, &gAlbedo);
    glBindTexture(GL_TEXTURE_2D, gAlbedo);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, gAlbedo, 0);
   
        // decimos como vamos a enlazar los color-buffer para renderizar. Para este framebuffer
    unsigned int attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
    glDrawBuffers(3, attachments);
    
        // create and attach depth buffer (renderbuffer)
    unsigned int rboDepth;
    glGenRenderbuffers(1, &rboDepth);
    glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCR_WIDTH, SCR_HEIGHT);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
    
    // finally check if framebuffer is complete
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "Framebuffer not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    //                ----->    SSAO BUFFER    <-----
    // -----------------------------------------------------
    unsigned int ssaoFBO;
    glGenFramebuffers(1, &ssaoFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, ssaoFBO);

    unsigned int ssaoColorBuffer;
        // SSAO buffer
    glGenTextures(1, &ssaoColorBuffer);
    glBindTexture(GL_TEXTURE_2D, ssaoColorBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, SCR_WIDTH, SCR_HEIGHT, 0, GL_RED, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ssaoColorBuffer, 0);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "SSAO Framebuffer not complete!" << std::endl;

    
        // muestras (samples)
    std::vector<glm::vec3> samples = GenerateSamples(64);
        // vectores rotacion y textura
    std::vector<glm::vec3> rotationNoise = GenerateRotationNoise();
    unsigned int noiseTexture; glGenTextures(1, &noiseTexture);
    glBindTexture(GL_TEXTURE_2D, noiseTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, 4, 4, 0, GL_RGB, GL_FLOAT, &rotationNoise[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // -----------------------------------------------------

    // lighting info
    // -------------
    const unsigned int NR_LIGHTS = 1;
    glm::vec3 lightPosition(-1.f,1.f,4.f);
    glm::vec3 lightColor(1.f,1.f,1.f);

    // shader configuration
    // --------------------
    
    shaderLightingPass.use();
    shaderLightingPass.setInt("gPosition", 0);
    shaderLightingPass.setInt("gNormal", 1);
    shaderLightingPass.setInt("gAlbedo", 2);
    shaderLightingPass.setInt("ssao", 3);

    shaderSSAO.use();
    shaderSSAO.setInt("gPosition", 0);
    shaderSSAO.setInt("gNormal", 1);
    shaderSSAO.setInt("gAlbedo", 2);
    shaderSSAO.setInt("ssao", 3);

    shaderSSAOPass.use();
    shaderSSAOPass.setInt("gPosition", 0);
    shaderSSAOPass.setInt("gNormal", 1);
    shaderSSAOPass.setInt("texNoise", 2);

            // DEBUG gPos, gNormal y SSAOviewer shaders
    shaderPos.use();
    shaderPos.setInt("gPosition", 0);
    shaderPos.setInt("gNormal", 1);
    shaderPos.setInt("gAlbedo", 2);

    shaderNormal.use();
    shaderNormal.setInt("gPosition", 0);
    shaderNormal.setInt("gNormal", 1);
    shaderNormal.setInt("gAlbedo", 2);

    shaderColor.use();
    shaderColor.setInt("gPosition", 0);
    shaderColor.setInt("gNormal", 1);
    shaderColor.setInt("gAlbedo", 2);

    shaderSSAOViewer.use();
    shaderSSAOViewer.setInt("gPosition", 0);
    shaderSSAOViewer.setInt("gNormal", 1);
    shaderSSAOViewer.setInt("gAlbedo", 2);

    // ----------      ----------

    glClearColor(0.35f, 0.35f, 0.55f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        auto currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        processInput(window);

        // parametros para SSAO
        shaderSSAOPass.use();
        shaderSSAOPass.setInt("samplesNum", samplesNum);
        shaderSSAOPass.setFloat("radius", ssaoRadius);
        shaderSSAOPass.setFloat("bias", ssaoBias);
        shaderSSAOPass.setFloat("intensity", ssaoIntensity);
        shaderSSAOPass.setBool("ssaoSmooth", ssaoSmooth);

        // render
        // ------
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 1. geometry pass: render scene's geometry/color data into gbuffer
        // -----------------------------------------------------------------
        glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 50.0f);
            glm::mat4 view = camera.GetViewMatrix();
            glm::mat4 model = glm::mat4(1.0f);
            shaderGeometryPass.use();
            shaderGeometryPass.setMat4("projection", projection);
            shaderGeometryPass.setMat4("view", view);
        
            model = glm::rotate(glm::mat4(1.f), .2f*glm::radians(modelAngle), glm::vec3{ 0.f,1.f,0.f });
            shaderGeometryPass.setMat4("model", model);

            // model
            if (currentModel == 0) {
                model = glm::scale(model, glm::vec3(0.5f));
                shaderGeometryPass.setMat4("model", model);
                suzanne.Draw(shaderGeometryPass);
            }
            else if (currentModel == 1) {
                model = glm::scale(model, glm::vec3(0.5f));
                shaderGeometryPass.setMat4("model", model);
                backpack.Draw(shaderGeometryPass);
            }
            else if ( currentModel == 2 ){
                model = glm::scale(model, glm::vec3(0.07f));
                shaderGeometryPass.setMat4("model", model);
                deforme.Draw(shaderGeometryPass);
            }
            else if ( currentModel == 3 ){
                model = glm::scale(model, glm::vec3(0.1f));
                shaderGeometryPass.setMat4("model", model);
                superficie.Draw(shaderGeometryPass);
            }
            else if ( currentModel == 4 ){
                model = glm::scale(model, glm::vec3(0.1f));
                shaderGeometryPass.setMat4("model", model);
                superficie2.Draw(shaderGeometryPass);
            }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        
        // ---------- SSAO ----------
        // mandar la informacion del gBuffer al SSAO framebuffer para calcular la oclusion
        glBindFramebuffer(GL_FRAMEBUFFER, ssaoFBO);
            glClear(GL_COLOR_BUFFER_BIT);
            shaderSSAOPass.use();
            // Send samples
            for (unsigned int i = 0; i < 64; ++i)
                shaderSSAOPass.setVec3("samples[" + std::to_string(i) + "]", samples[i]);
            shaderSSAOPass.setMat4("projection", projection);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, gPosition);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, gNormal);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, noiseTexture);
            renderQuad();
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // ----------      ----------

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // 2. lighting pass: calculate lighting by iterating over a screen filled quad pixel-by-pixel using the gbuffer's content.
        // -----------------------------------------------------------------------------------------------------------------------
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // send light relevant uniforms
        glm::vec3 lightPosView = glm::vec3(camera.GetViewMatrix() * glm::vec4(lightPosition, 1.0));

        if (SSAO) {
            shaderSSAO.use();
            shaderSSAO.setVec3("light.Position", lightPosView);
            shaderSSAO.setVec3("light.Color", lightColor);
        }else if (DEBUG_Pos) {
            shaderPos.use();
            shaderPos.setVec3("light.Position", lightPosView);
            shaderPos.setVec3("light.Color", lightColor);
        }else if (DEBUG_Normal) {
            shaderNormal.use();
            shaderNormal.setVec3("light.Position", lightPosView);
            shaderNormal.setVec3("light.Color", lightColor);
        }else if (DEBUG_Color) {
            shaderColor.use();
            shaderColor.setVec3("light.Position", lightPosView);
            shaderColor.setVec3("light.Color", lightColor);
        }
        else if (DEBUG_SSAO) {
            shaderSSAOViewer.use();
            shaderSSAOViewer.setVec3("light.Position", lightPosView);
            shaderSSAOViewer.setVec3("light.Color", lightColor);
        }else {
            shaderLightingPass.use();                   // shaderlightingpass es igual a shaderSSAO pero no usa la oclusion
            shaderLightingPass.setVec3("light.Position", lightPosView);
            shaderLightingPass.setVec3("light.Color", lightColor);
        }
            // activar las texturas del gbuffer + ssao-buffer
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, gPosition);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, gNormal);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, gAlbedo);
        glActiveTexture(GL_TEXTURE3); // add extra SSAO texture to lighting pass
        glBindTexture(GL_TEXTURE_2D, ssaoColorBuffer);
        renderQuad();
        
        // FINALMENTE renderizar el quad
        renderQuad();

        // ---------- ImGui ----------
        ImGui::SetCurrentContext(imgui_context);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("SSAO");

        Combo(".obj (O)", &currentModel, models);
        ImGui::Checkbox("Rotate (R)", &rotateModel);
        ImGui::Checkbox("gPositions shading (1)", &DEBUG_Pos);
        ImGui::Checkbox("gNormals shading (2)", &DEBUG_Normal);
        ImGui::Checkbox("gColor shading (3)", &DEBUG_Color);
        //ImGui::Checkbox("occlusion shading (4)", &DEBUG_SSAO);    No muestra la escala de grises esperaria, no encuentro el error
        ImGui::Checkbox("SSAO (Z)", &SSAO);
        ImGui::Checkbox("Smooth (K)", &ssaoSmooth);
        ImGui::SliderFloat("SSAO intensity", &ssaoIntensity, 0.1f, 9.f);
        ImGui::SliderFloat("SSAO radius", &ssaoRadius, 0.1f, 5.f);
        ImGui::SliderFloat("SSAO bias", &ssaoBias, 0.0f, 1.f);
        ImGui::SliderInt("SSAO samples", &samplesNum, 1, 64);
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // ---------- ImGui ----------

        // rotacion del modelo
        if (rotateModel) modelAngle += 1.f + deltaTime;

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// renderQuad() renders a 1x1 XY quad in NDC
// -----------------------------------------
unsigned int quadVAO = 0;
unsigned int quadVBO;
void renderQuad()
{
    if (quadVAO == 0)
    {
        float quadVertices[] = {
            // positions        // texture Coords
            -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
             1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
             1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        };
        // setup plane VAO
        glGenVertexArrays(1, &quadVAO);
        glGenBuffers(1, &quadVBO);
        glBindVertexArray(quadVAO);
        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    }
    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}

// inputs
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if (!rPressed && glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)      // rotate
        rPressed = true;
    if (rPressed && glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE) {
        rotateModel = !rotateModel;
        rPressed = false;
    }
    if (!oPressed && glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)                   // model
        oPressed = true;
    if (oPressed && glfwGetKey(window, GLFW_KEY_O) == GLFW_RELEASE) {
        ++currentModel;
        if (currentModel >= 5) currentModel = 0;
        oPressed = false;
    }
    if (!zPressed && glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)                   // SSAO
        zPressed = true;
    if (zPressed && glfwGetKey(window, GLFW_KEY_Z) == GLFW_RELEASE) {
        SSAO = !SSAO;
        zPressed = false;
    }
    if (!unoPressed && glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)                   // SSAO
        unoPressed = true;
    if (unoPressed && glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE) {
        DEBUG_Pos = !DEBUG_Pos;
        unoPressed = false;
    }
    if (!dosPressed && glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)                   // SSAO
        dosPressed = true;
    if (dosPressed && glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE) {
        DEBUG_Normal = !DEBUG_Normal;
        dosPressed = false;
    }
    if (!tresPressed && glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)                   // SSAO
        tresPressed = true;
    if (tresPressed && glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE) {
        DEBUG_Color = !DEBUG_Color;
        tresPressed = false;
    }
    if (!cuatroPressed && glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)                   // SSAO
        cuatroPressed = true;
    if (cuatroPressed && glfwGetKey(window, GLFW_KEY_4) == GLFW_RELEASE) {
        DEBUG_SSAO = !DEBUG_SSAO;
        cuatroPressed = false;
    }
    if (!kPressed && glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)                   // SSAO
        kPressed = true;
    if (kPressed && glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE) {
        ssaoSmooth = !ssaoSmooth;
        kPressed = false;
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

bool mouseButtonPressed = false;

// input: mouse button
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        if (!mouseButtonPressed) {
            mouseButtonPressed = true;
            firstMouse = true;
        }
    }else
        mouseButtonPressed = false;
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    if (mouseButtonPressed) {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);
        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        camera.ProcessMouseMovement(xoffset, yoffset);
    }
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

// ImGui auxiliar
bool Combo(const char* label, int* current_item, const std::vector<std::string>& items) {
    return ImGui::Combo(label, current_item,
        [](void* data, int idx, const char** out_text) {
            *out_text = (*reinterpret_cast<const std::vector<std::string>*>(data))[idx].c_str(); return true;
        },
        (void*)&items, items.size(), -1);
}

/*
* Genera un "Kernel" (asi le dice learnopengl) de muestras (samples) que se usar�n para hacer un offset
* a la posici�n en view-space del fragmento en una semiesfera orientada hacia la normal del fragmento.
*/
std::vector<glm::vec3> GenerateSamples(int n) {
    std::uniform_real_distribution<float> randomFloats(0.0, 1.0);   // genera flotantes aleatorios en una distribucion uniforme
    std::default_random_engine generator;       // genera numero pseudo-aleatorios
    std::vector<glm::vec3> samples;
    for (int i = 0; i < n; ++i) {
        glm::vec3 sample(
            randomFloats(generator) * 2.0 - 1.0,    // x random entre -1 y 1
            randomFloats(generator) * 2.0 - 1.0,    // y random entre -1 y 1
            randomFloats(generator));   // se supone que la normal de la superficie apunta a z
        sample = glm::normalize(sample);
        sample *= randomFloats(generator);  // una longitud aleatoria entre 0 y 1 (estarian acotados en la semiesfera)
        // ac� podr�amos acomodarlos m�s cerca del origen, pero meh
        samples.push_back(sample);
    }
    return samples;
}

/*
* Genera una matriz de 4x4 con vectores de rotaci�n pseudo aleatorios
*/
std::vector<glm::vec3> GenerateRotationNoise() {
    std::uniform_real_distribution<float> randomFloats(0.0, 360.0);   // genera flotantes aleatorios en una distribucion uniforme
    std::default_random_engine generator;       // genera numero pseudo-aleatorios
    std::vector<glm::vec3> angles;
    for (int i = 0; i < 16; ++i) {
        glm::vec3 rotation(
            randomFloats(generator) * 2.0 - 1.0,
            randomFloats(generator) * 2.0 - 1.0,
            0.f);
        angles.push_back(rotation);
    }
    return angles;
}