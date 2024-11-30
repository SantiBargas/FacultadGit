//-------------------------------------------------------------------
//-- IM_tb.v
//-- Testbench
//-------------------------------------------------------------------
//-- Juan Gonzalez (Obijuan)
//-- Jesus Arroyo Torrens
//-- GPL license
//-------------------------------------------------------------------
`default_nettype none
`define DUMPSTR(x) `"x.vcd`"
`timescale 100 ns / 10 ns

module UC_tb();

//-- Simulation time: 1us (10 * 100ns)
parameter DURATION = 10;

//-- Clock signal. It is not used in this simulation
reg clk = 0;
always #0.5 clk = ~clk;

//-- PC port

    reg [6:0] opcode_test;
    reg [2:0] f3_test;
    reg f7_5_test,zero_test;
    wire branch_test;
    wire memWrite_test;
    wire aluSrc_test;
    wire regWrite_test;
    wire resultSrc_test;
    wire pcSrc_test;
    wire [1:0] inmSrc_test;
    wire [2:0] aluCtrl_test;

//-- Instantiate the unit to test
UC UUT (
  .opcode_s(opcode_test),
  .f3_s(f3_test),
  .f7_5_s(f7_5_test),
  .zero(zero_test),
  .branch_s(branch_test),
  .memWrite_s(memWrite_test),
  .aluSrc_s(aluSrc_test),
  .regWrite_s(regWrite_test),
  .resultSrc_s(resultSrc_test),
  .pcSrc_s(pcSrc_test),
  .inmSrc_s(inmSrc_test),
  .aluCtrl_s(aluCtrl_test)
);


initial begin

  //-- File were to store the simulation results
  $dumpfile(`DUMPSTR(`VCD_OUTPUT));
  $dumpvars(0, UC_tb);
    zero_test=1'b0;
    f3_test = 3'b000;
    f7_5_test =1'b0;
    opcode_test = 7'd3;
    #1
    opcode_test = 7'd35;
    zero_test=1'b1;
    #1
    opcode_test = 7'd51;
    f3_test = 3'b000;
    f7_5_test =1'b1;
    #1
    f3_test = 3'b111;
    #1
    opcode_test = 7'd99;

   #(DURATION) $display("End of simulation");
  $finish;
end

endmodule