module Adder(
	input wire[31:0] a, b,
	output reg[31:0] r
);

always @(*) begin
	r = a + b;
end

endmodule