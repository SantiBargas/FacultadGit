module ALU(
    input wire [31:0] A, B,
    input wire [2:0] ALUControl,
    output wire [31:0] result,
    output wire zero
);

reg [31:0] R;

always @(*) begin
    case (ALUControl)
        3'b000: R = A + B; 
        3'b001: R = A - B;
        3'b010: R = A & B; 
        3'b011: R = A | B;
        3'b101: R = (A < B)? 32'b1 : 32'b0;
        default: R = A + B;
    endcase
end

assign result = R;
assign zero = R? 1'b0:1'b1;

endmodule