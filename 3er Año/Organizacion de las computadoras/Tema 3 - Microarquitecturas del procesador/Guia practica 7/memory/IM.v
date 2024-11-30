module IM(
    input wire [15:0] addr,
    output wire [31:0] instruccion
);

reg [31:0] memoria [(2^16)-1:0];

assign instruccion = memoria[addr];

//Instrucciones: 
initial begin    
 memoria[0] <= 32'hffffffff;
 memoria[1] <= 32'hcccccccc;
 memoria[2] <= 32'h00000000;
end
endmodule


