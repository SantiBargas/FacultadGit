module aludec (
    input wire op_5,f7_5,
    input wire [2:0] f3,
    input wire [1:0] aluOp,
    output wire [2:0] aluCtrl
);

reg [2:0] alu_reg;
always @(*) begin
    case (aluOp)
        2'b00: alu_reg = 3'b000;
        2'b01: alu_reg = 3'b001;
        
        2'b10: begin
            case (f3)
                3'b010: alu_reg = 3'b101;
                3'b110: alu_reg = 3'b011;
                3'b111: alu_reg = 3'b010;

                3'b000:
                if ({op_5,f7_5} == 2'b11) begin
                    alu_reg = 3'b001;
                end else begin
                    alu_reg = 3'b000;
                end

                default: alu_reg = 3'b000;
            endcase
        end

        default: alu_reg = 3'b000;
    endcase
end

assign aluCtrl = alu_reg;

endmodule