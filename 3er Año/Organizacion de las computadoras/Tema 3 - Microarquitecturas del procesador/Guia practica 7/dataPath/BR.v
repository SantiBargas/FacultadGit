module BR(
    input wire clk,we,
    input wire [4:0] a1,a2,a3,
    input wire [31:0] wdata3,
    output wire [31:0] rs1,rs2
);

reg [31:0] memoria [31:0];

always @(posedge clk) begin
    if (we) memoria[a3] <= wdata3;
end

assign rs1 = a1 ? memoria[a1] : 0;
assign rs2 = a2 ? memoria[a2] : 0;
endmodule