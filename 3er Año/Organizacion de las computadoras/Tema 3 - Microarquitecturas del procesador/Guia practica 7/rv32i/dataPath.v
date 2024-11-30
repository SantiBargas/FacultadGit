module dataPath(

input wire clk,pcSRC,aluSrc,BRwe,resultSrc,
input wire [1:0] immSrc,
input wire [2:0] alucontrol,
input wire [31:0] instruccion, ReadData,

output wire zero,
output wire [15:0] pc,
output wire [31:0] ALU_R,rd2

);

wire [15:0] pcnext;

PC pc_s(
    .clk(clk),
    .pcNext(pcnext),
    .pc(pc)
);

wire [31:0] cuatro = 32'b100;
wire [31:0] pc_plus4,pc_target;

Adder adder_pc4(
    .a({16'b0,pc}),
    .b(cuatro),
    .r(pc_plus4)
);

Adder adder_imm(
    .a({16'b0,pc}),
    .b(immNext), 
    .r(pc_target)
);

wire [31:0] pcaux;
Mux2x1 mul_pc(
    .a(pc_plus4),
    .b(pc_target),
    .sel(pcSRC), // pcSRC,
    .out(pcaux)
);

assign pcNext = pcaux[15:0];

wire [31:0] rd1;

BR br_s(
    .clk(clk),
    .we(BRwe), //we o REGWRITE
        .a1(instruccion[19:15]),
    .a2(instruccion[24:20]),
    .a3(instruccion[11:7]),
    .wdata3(writeBR_data),
    .rs1(rd1),
    .rs2(rd2)
);

wire [31:0] immNext;
SE se_s(
    .instruccion(instruccion),
    .immSrc(immSrc),//[1:0] immsrc,
    .immnext(immNext)
);

wire [31:0] srcB;
ALU alu_s(
    .A(rd1),
    .B(srcB),
    .ALUControl(alucontrol),
    .result(ALU_R),
    .zero(zero)
);

Mux2x1 mul_srcB(
    .a(rd2),
    .b(immNext),
    .sel(aluSrc),//aluSrc
    .out(srcB)
);

wire [31:0] writeBR_data;
Mux2x1 mul_alu(
    .a(ALU_R),
    .b(ReadData),
    .sel(resultSrc),//resultSrc
    .out(writeBR_data)
);

endmodule