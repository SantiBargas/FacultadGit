module PC(
    input wire clk,
    input wire [31:0] pcNext,
    output reg [31:0] pc
);

always @(posedge clk)
    begin
        pc <= pcNext;
    end
endmodule
