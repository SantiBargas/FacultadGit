module UC (
    input wire [6:0] opcode_s,
    input wire [2:0] f3_s,
    input wire f7_5_s,zero,
    output wire branch_s,
    output wire memWrite_s,
    output wire aluSrc_s,
    output wire regWrite_s,
    output wire resultSrc_s,
    output wire pcSrc_s,
    output wire [1:0] inmSrc_s,
    output wire [2:0] aluCtrl_s
);

wire [1:0] aluOp_s;

mainDeco main_dec(
    .op(opcode_s),
    .zero(zero),
    .branch(branch_s),
    .memWrite(memWrite_s),
    .aluSrc(aluSrc_s),
    .regWrite(regWrite_s),
    .resultSrc(resultSrc_s),
    .pcSrc(pcSrc_s),
    .inmSrc(inmSrc_s),
    .aluOp(aluOp_s)
);

aluDeco alu_dec(
    .op_5(opcode_s[5]), //o opcode_s[4] ?????
    .f7_5(f7_5_s),
    .f3(f3_s),
    .aluOp(aluOp_s),
    .aluCtrl(aluCtrl_s)
);

endmodule