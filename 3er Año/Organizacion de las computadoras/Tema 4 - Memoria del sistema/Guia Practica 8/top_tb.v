//-------------------------------------------------------------------
//-- PC_tb.v
//-- Testbench
//-------------------------------------------------------------------
//-- Juan Gonzalez (Obijuan)
//-- Jesus Arroyo Torrens
//-- GPL license
//-------------------------------------------------------------------
`default_nettype none
`define DUMPSTR(x) `"x.vcd`"
`timescale 100 ns / 10 ns

module top_tb();

//-- Simulation time: 1us (10 * 100ns)
parameter DURATION = 500;

//-- Clock signal. It is not used in this simulation
reg clk = 0;
always #0.5 clk = ~clk;

//-- PC port
    reg rst;
    reg [31:0] ent;
    wire [31:0] sal;

//-- Instantiate the unit to test
top UUT (
    .clk(clk),
    .rst(rst),
    .ent(ent),
    .sal(sal)
         );


initial begin

  //-- File were to store the simulation results
  $dumpfile(`DUMPSTR(`VCD_OUTPUT));
  $dumpvars(0, top_tb);
  rst=1'b1;
  #1
  rst= 1'b0;

   #(DURATION) $display("End of simulation");
  $finish;
end

endmodule
