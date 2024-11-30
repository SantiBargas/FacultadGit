`default_nettype none
`define DUMPSTR(x) `"x.vcd`"
`timescale 100 ns / 10 ns

module IM_tb;

    reg [4:0] addressIM;   // Dirección de 5 bits para seleccionar la instrucción
    wire [31:0] inst;      // Salida de la instrucción de 32 bits

    // Instancia del módulo IM
    IM uut (
        .addressIM(addressIM),
        .inst(inst)
    );

    // Procedimiento de prueba
    initial begin
        // Archivos de volcado para la simulación en VCD
        $dumpfile(`DUMPSTR(`VCD_OUTPUT));
        $dumpvars(0, IM_tb);

        // Inicializa la dirección de la memoria de instrucciones
        addressIM = 5'b00000;  // Dirección inicial
        
        // Prueba diferentes direcciones y espera algunos ciclos
        #10;
        addressIM = 5'b00001;  // Probar la dirección 1
        #10;
        addressIM = 5'b00010;  // Probar la dirección 2
        #10;
        addressIM = 5'b00011;  // Probar la dirección 3
        #10;
        addressIM = 5'b00100;  // Probar la dirección 4

        // Termina la simulación
        #50 $display("End of simulation");
        $finish;
    end
endmodule
