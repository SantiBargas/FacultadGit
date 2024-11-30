`default_nettype none
`define DUMPSTR(x) `"x.vcd`"
`timescale 100 ns / 10 ns

module PC_tb;

    reg clk;              // Señal de reloj
    reg [31:0] pcNext;    // Próximo valor del contador de programa
    wire [31:0] pc;       // Salida del PC

    // Instancia del módulo PC
    PC uut(
        .clk(clk),
        .pcNext(pcNext),
        .pc(pc)
    );

    // Generador de la señal de reloj
    initial begin
        clk = 0;
        forever #5 clk = ~clk;  // Reloj con periodo de 10 unidades de tiempo
    end

    // Procedimiento de prueba
    initial begin
        // Archivos de volcado para la simulación en VCD
        $dumpfile(`DUMPSTR(`VCD_OUTPUT));
        $dumpvars(0, PC_tb);

        // Inicializa las señales
        pcNext = 32'h00000000;

        // Espera algunos ciclos y prueba varios valores
        #10;
        pcNext = 32'h00000010;  // Prueba con un valor
        #10;
        pcNext = 32'h00000020;  // Prueba con otro valor
        #10;
        pcNext = 32'h000000FF;  // Prueba con otro valor
        #10;
        pcNext = 32'h0000FFFF;  // Prueba con otro valor

        // Termina la simulación
        #50 $display("End of simulation");
        $finish;
    end
endmodule
