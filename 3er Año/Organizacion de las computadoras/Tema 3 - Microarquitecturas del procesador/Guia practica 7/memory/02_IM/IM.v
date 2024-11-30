module IM(
input wire [4:0] addressIM,       // Entrada: Dirección de 5 bits (32 posibles registros)
output reg [31:0] inst  // Salida: Instrucción de 32 bits
);

// Definir la memoria de instrucciones (32 registros de 32 bits)
reg [31:0] memory [0:31];

  // Inicializar la memoria con algunas instrucciones (opcional)
    initial begin
        memory[0] = 32'h00000000;  // Ejemplo de inicialización
        memory[1] = 32'h00000001;  // Puedes definir las instrucciones necesarias
        memory[2] = 32'h00000002;
        // Continúa inicializando según sea necesario...
    end

// Asignación de la salida 'inst' según la dirección 'addressIM'
always @(*) begin
    inst = memory[addressIM];  // Asigna el valor de la memoria correspondiente a la salida
end

endmodule
