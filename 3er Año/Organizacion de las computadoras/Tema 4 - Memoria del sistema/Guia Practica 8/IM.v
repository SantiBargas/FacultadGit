module IM (
    input wire [15:0] addr,
    output wire [31:0] instruccion
);

reg [31:0] memoria [65535:0];//(2^16)-1:0

assign instruccion = memoria[addr];

//Instrucciones: 
initial begin    
/*memoria[0] <= 32'h00002083; //lw x1,(x0)
 memoria[4] <= 32'h00402103; //lw x2,4(x0)
 memoria[8] <= 32'h002081b3; //add x3,x1,x2
 memoria[12] <= 32'h00302423;//sw x3,8(x0)
 memoria[16] <= 32'h00802203;//lw x4,8(x0) */
memoria[4* 0 ] <= 32'h00300413;
memoria[4* 1 ] <= 32'h00100493;
memoria[4* 2 ] <= 32'h01000913;
memoria[4* 3 ] <= 32'h009462b3;
memoria[4* 4 ] <= 32'h00947333;
memoria[4* 5 ] <= 32'h009403b3;
memoria[4* 6 ] <= 32'h40940e33;
memoria[4* 7 ] <= 32'h40848eb3;
memoria[4* 8 ] <= 32'h00942f33;
memoria[4* 9 ] <= 32'h0084afb3;
memoria[4* 10 ] <= 32'h01d4afb3;
memoria[4* 11 ] <= 32'h00100293;
memoria[4* 12 ] <= 32'h00000313;
memoria[4* 13 ] <= 32'h01228863;
memoria[4* 14 ] <= 32'h005282b3;
memoria[4* 15 ] <= 32'h00130313;
memoria[4* 16 ] <= 32'hff5ff06f;
memoria[4* 17 ] <= 32'h000004b3;
memoria[4* 18 ] <= 32'h00000293;
memoria[4* 19 ] <= 32'h00a00313;
memoria[4* 20 ] <= 32'h00628863;
memoria[4* 21 ] <= 32'h008484b3;
memoria[4* 22 ] <= 32'h00128293;
memoria[4* 23 ] <= 32'hff5ff06f;
memoria[4* 24 ] <= 32'h00802023;
memoria[4* 25 ] <= 32'h00902223;
memoria[4* 26 ] <= 32'h01202423;
memoria[4* 27 ] <= 32'h00002283;
memoria[4* 28 ] <= 32'h00402303;
memoria[4* 29 ] <= 32'h00802383;
end
endmodule