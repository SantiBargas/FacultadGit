module maindec (
    input wire [6:0] op,
    input wire zero,
    output wire memWrite,aluSrc,regWrite,pcSrc,
    output wire [1:0] inmSrc,aluOp,resultSrc
);
    
wire jump,branch;
reg [10:0] signals;
//regwrite, [1:0] immsrc, alusrc memwrite, [1:0] resultsrc, branch, [1:0] aluop, jump
//en las x agregue un 0 
always @(*) begin
    case (op)
        7'b0000011: signals <= 11'b10010010000;

        7'b0100011: signals <= 11'b00111000000; 

        7'b0110011: signals <= 11'b10000000100; 

        7'b1100011: signals <= 11'b01000001010;

        7'b0010011: signals <= 11'b10010000100;

        7'b1101111: signals <= 11'b11100100001;

        default: signals <= 11'b0; 
    endcase
end

assign jump = signals[0];
assign aluOp = signals[2:1];
assign branch = signals [3];
assign resultSrc = signals[5:4];
assign memWrite = signals[6];
assign aluSrc = signals[7];
assign inmSrc = signals[9:8];
assign regWrite = signals[10];

assign pcSrc = jump || (zero && branch);

endmodule