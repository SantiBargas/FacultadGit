module PC(
    input wire clk,
    input wire [15:0] pcNext,
    output reg [15:0] pc
);

always @(posedge clk)
    begin
        pc <= pcNext;
    end
endmodule
