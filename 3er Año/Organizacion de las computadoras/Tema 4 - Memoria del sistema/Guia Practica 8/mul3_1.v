module mul3_1 (
    input wire [31:0] a,b,c,
    input wire [1:0] sel,
    output wire [31:0] out
);
    
assign out = sel[1]?  c : (sel[0]? b : a);
endmodule