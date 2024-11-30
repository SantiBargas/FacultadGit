module RV32i (
    input wire clk,
    input wire [31:0] instruccion_s,dataRead_s,
    output wire MemWrite_s,
    output wire [15:0] pc_s,addrData_s,
    output wire [31:0] dataWrite_s
);

wire BRwe,pcSRC,aluSrc,zero,resultSrc;
wire [1:0] immSrc;
wire [2:0] alucontrol;

wire [31:0] aluresult;
dataPath datapath(
    .clk(clk),
    .pcSRC(pcSRC),
    .aluSrc(aluSrc),
    .BRwe(BRwe),
    .resultSrc(resultSrc),
    .immSrc(immSrc),
    .alucontrol(alucontrol),
    .instruccion(instruccion_s),
    .ReadData(dataRead_s),
    .zero(zero),
    .pc(pc_s),
    .ALU_R(aluresult),
    .rd2(dataWrite_s)
);
assign addrData_s = aluresult[15:0];

UC unitControl(
    .opcode_s(instruccion_s[6:0]),
    .f3_s(instruccion_s[14:12]),
    .f7_5_s(instruccion_s[30]),// o instruccion[29]?
    .zero(zero),
    //.branch_s(),// a donde va esto?
    .memWrite_s(MemWrite_s),
    .aluSrc_s(aluSrc),
    .regWrite_s(BRwe),
    .resultSrc_s(resultSrc), 
    .pcSrc_s(pcSRC),
    .inmSrc_s(immSrc),
    .aluCtrl_s(alucontrol)
);

endmodule
