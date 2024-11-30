module SE (
    input wire [24:0] inm, // Entrada de 25 bits de la instrucción
    input wire [1:0] src,  // Selector de la instrucción (I, S, B, U, J)
    output reg [31:0] inmExt // Salida extendida a 32 bits
);

always @(*) begin
    case (src)
        2'b00: begin // Tipo I
            inmExt = {{20{inm[24]}}, inm[24:13]};
        end
        2'b01: begin // Tipo S
            inmExt = {{20{inm[24]}}, inm[24:18], inm[10:7]};
        end
        2'b10: begin // Tipo B
            inmExt = {{19{inm[24]}}, inm[24], inm[23:18], inm[10:8], inm[7]};
        end
        2'b11: begin // Tipo U
            inmExt = {inm[24:13], 12'b0};
        end
        3'b100: begin // Tipo J
            inmExt = {{11{inm[24]}}, inm[23:14], inm[13], inm[12:8], inm[7:4]};
        end
        default: inmExt = 32'b0;
    endcase
end

endmodule
