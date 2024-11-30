module DM (
    input wire clk,we,
    input wire [15:0] addr,
    input wire [31:0] wdata,
    output wire [31:0] rd
);

reg [31:0] memoria [(2^16)-1:0];

always @(posedge clk)begin
    if(we) memoria[addr[15:2]] <= wdata;
end

initial begin

end
assign rd = memoria[addr[15:2]];  
    
endmodule