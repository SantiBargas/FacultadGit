module ALU(
	input wire [31:0] srcA, srcB,
	input wire [2:0] ALUControl,
	output reg [31:0] result
);

	always @(*) begin
		case (ALUControl)
			3'b 000 : result = srcA + srcB; 						//add
			3'b 001 : result = srcA - srcB; 						//subtract
			3'b 010 : result = srcA & srcB; 						//and
			3'b 011 : result = srcA | srcB; 						//or
			3'b 101 : result =	(srcA < srcB) ? 32'b1 : 32'b0;		//SLT
			default: result = 32'b0;
		endcase
	end
endmodule
