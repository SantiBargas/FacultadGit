module adder (
    input wire [31:0] a,b,
    output wire [31:0] r
);

assign r = a+b;

endmodule