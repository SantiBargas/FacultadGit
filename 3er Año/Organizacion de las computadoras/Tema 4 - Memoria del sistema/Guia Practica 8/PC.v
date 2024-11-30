module PC (
    input wire clk,
    input wire [15:0] pcnext,
    output reg [15:0] pc
);

always @(posedge clk) begin
    pc <= pcnext;
end
    
endmodule