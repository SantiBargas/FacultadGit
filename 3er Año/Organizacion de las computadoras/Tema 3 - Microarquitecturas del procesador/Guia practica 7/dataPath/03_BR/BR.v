/*
3) banco de registros
nombre: BR
ent: a1(5), a2(5), a3(5), wd(32), we
sal: rd1(32), rd2(32)
*/

module BR(
	input wire clk,
	input wire [4:0] a1, a2, a3,	//direcciones de los registros
	input wire [31:0] wd,			//dato a escribir
	input wire we,					//habilitacion de escritura
	output reg [31:0] rd1, rd2		//datos leidos de los registros
	);

reg [31:0] registers [0:31];

// Proceso de lectura
always @(*) begin
    rd1 = registers[a1];              // Leer el registro a1
    rd2 = registers[a2];              // Leer el registro a2
end

// Proceso de escritura
always @(posedge clk) begin
    if (we) begin
        registers[a3] <= wd;          // Escribir el dato wd en el registro a3
    end
end

endmodule