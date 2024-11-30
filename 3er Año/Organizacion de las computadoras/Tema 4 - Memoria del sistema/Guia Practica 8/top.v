module top (
    input wire clk,rst,
    input wire [31:0] ent,
    output wire [31:0] sal
);


wire  we_s;
wire [15:0] pc_s,addrData_s;
wire [31:0] dataWrite_s;
wire [31:0] instruccion_s,dataRead_s;

RV32i rv(
    .clk(clk),
    .rst(rst),
    .instruccion_s(instruccion_s),
    .dataRead_s(dataRead_s),
    .MemWrite_s(we_s),
    .pc_s(pc_s),
    .addrData_s(addrData_s),
    .dataWrite_s(dataWrite_s)
);

memoria mem (
    .clk(clk),
    .we_s(we_s),
    .pc_s(pc_s),
    .addrData_s(addrData_s),
    .dataWrite_s(dataWrite_s),
    .instruccion_s(instruccion_s),
    .dataRead_s(dataRead_s)
);

assign sal= dataRead_s;

endmodule