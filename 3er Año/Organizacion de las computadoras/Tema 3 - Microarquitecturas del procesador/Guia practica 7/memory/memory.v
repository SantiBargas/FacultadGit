module memory(
    input wire clk, we_s,
    input wire [15:0] pc_s,addrData_s,
    input wire [31:0] dataWrite_s,
    output wire [31:0] instruccion_s,dataRead_s
);

IM memoria_instrucciones(
    .addr(pc_s),
    .instruccion(instruccion_s)
);

DM memoria_datos(
    .clk(clk),
    .we(we_s),
    .addr(addrData_s),
    .wdata(dataWrite_s),
    .rd(dataRead_s)
);

endmodule
