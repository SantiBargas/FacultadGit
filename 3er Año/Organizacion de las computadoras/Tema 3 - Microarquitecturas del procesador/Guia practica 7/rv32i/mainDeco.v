module mainDeco(
    input wire [6:0] op,
    input wire zero,
    output wire branch,memWrite,aluSrc,regWrite,resultSrc,pcSrc,
    output wire [1:0] inmSrc,aluOp
);

reg [8:0] signals;
// ALUop[1:0],branch, Resultsrc, Memwrite, Alusrc, Immsrc [1:0], regwrite

//en las x agregue un 0 
always @(*) begin
    case (op)
        7'b0000011: signals <= 9'b000101001; //Carga

        7'b0100011: signals <= 9'b000011010; //9'b000x11001 //Almacenamiento
 
        7'b0110011: signals <= 9'b100000001; //9'b100000xx1 //Operaciones R

        7'b1100011: signals <= 9'b011000100; //9'b011x00100 //Branch

        7'b0010011: signals <= 9'b100100001; // addi (Tipo I)
        7'b1101111: signals <= 9'b100000011; // jal (Tipo J)

        default: signals <= 9'b0; 
    endcase
end

assign aluOp = signals[8:7];
assign branch = signals [6];
assign resultSrc = signals[5];
assign memWrite = signals[4];
assign aluSrc = signals[3];
assign inmSrc = signals[2:1];
assign regWrite = signals[0];
assign pcSrc = zero && branch;

endmodule