`timescale 1ns / 1ps
`define DUMPSTR(x) `"x.vcd`"

module SE_tb();

    reg [24:0] inm;    // Entrada inmediata de 25 bits
    reg [1:0] src;     // Selector de instrucción
    wire [31:0] inmExt; // Salida extendida a 32 bits

    // Instanciamos el módulo SE
    SE UUT (
        .inm(inm),
        .src(src),
        .inmExt(inmExt)
    );

    // Bloque inicial de prueba
    initial begin
        $dumpfile(`DUMPSTR(`VCD_OUTPUT));  // Archivo de volcado de la simulación
        $dumpvars(0, SE_tb);               // Volcado de todas las variables

        // Prueba Tipo I
        inm = 25'b0000000000000000000000000; src = 2'b00; #1;
        $display("Tipo I: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        inm = 25'b1000000000000000000000000; src = 2'b00; #1;
        $display("Tipo I: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        // Prueba Tipo S
        inm = 25'b0000000000000000000000000; src = 2'b01; #1;
        $display("Tipo S: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        inm = 25'b1111111111111111111111111; src = 2'b01; #1;
        $display("Tipo S: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        // Prueba Tipo B
        inm = 25'b0000000000000000000000000; src = 2'b10; #1;
        $display("Tipo B: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        inm = 25'b1010101010101010101010101; src = 2'b10; #1;
        $display("Tipo B: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        // Prueba Tipo U
        inm = 25'b0000000000000000000000000; src = 2'b11; #1;
        $display("Tipo U: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        inm = 25'b1111111111111111111111111; src = 2'b11; #1;
        $display("Tipo U: inm = %b, src = %b, inmExt = %b", inm, src, inmExt);

        // Finalizar la simulación
        $finish;
    end

endmodule
