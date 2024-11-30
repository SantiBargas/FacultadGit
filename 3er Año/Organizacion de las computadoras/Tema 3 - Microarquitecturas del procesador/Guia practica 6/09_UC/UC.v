module UC(
    input wire f7,
    input wire [2:0] f3,
    input wire [6:0] op,
    input wire zero,
    output wire pcSrc, memWrite, ALUsrc, regWrite,
    output wire [2:0] ALUcontrol,
    output wire [1:0] immSrc, resSrc
);
// Señales internas
wire [1:0] UC_aluOp;
wire branch, jump;

// Instancia del decodificador principal
mainDeco mainDeco_1(
    .op(op),
    .branch(branch),
    .immSrc(immSrc),
    .memWrite(memWrite),
    .resSrc(resSrc),
    .aluSrc(ALUsrc),
    .regWrite(regWrite),
    .aluOp(UC_aluOp)
);

// Señal auxiliar para op[5]
wire UC_op5;
assign UC_op5 = op[5];

// Instancia del decodificador de ALU
aluDeco aluDeco_1(
    .op(UC_op5), 
    .f3(f3),
    .f7(f7),
    .aluOp(UC_aluOp),
    .aluControl(ALUcontrol)
);

// Lógica para determinar pcSrc
assign pcSrc = (zero & branch);

endmodule