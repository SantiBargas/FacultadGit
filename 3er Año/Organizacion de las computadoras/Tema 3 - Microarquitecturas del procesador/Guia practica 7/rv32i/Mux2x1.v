module Mux2x1(
    input wire [31:0] a,b,
    input wire sel,
    output wire [31:0] out
);
assign out = sel? b : a;

endmodule