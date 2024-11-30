module SE (
    input wire [31:0] instruccion,
    input wire [1:0] immSrc,
    output wire [31:0] immnext
);
reg [31:0] immnext_reg;
//revisar posiciones del bit del inmediato en las diferentes instrucciones
always @(*)begin
    case (immSrc)
        // I type
        2'b00: immnext_reg = {{20{instruccion[31]}}, instruccion[31:20]};
        // S-type stores
        2'b01: immnext_reg = {{20{instruccion[31]}}, instruccion[31:25],instruccion[11:7]}; 
        // B-type branches
        2'b10: immnext_reg = {{20{instruccion[31]}}, instruccion[7],instruccion[30:25],instruccion[11:8],1'b0};
        // J type (jal)
        2'b11: immnext_reg = {{12{instruccion[31]}}, instruccion[19:12], instruccion[20], instruccion[30:21], 1'b0};
        default: immnext_reg =32'bx; //undefined
    endcase
end
assign immnext = immnext_reg;

endmodule