`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/18 14:11:39
// Design Name: 
// Module Name: counter_74163
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module counter_74163(
    input ct,LdN, ClrN, Clk,
    input [4:0] D,
    output reg [4:0] Q
    );
    
    initial begin 
    Q = 5'b00000;
    end
    
    always @ (posedge Clk)
    begin
    if(ClrN == 1) Q <= 5'b0000;
    else if (LdN == 1) Q <= D;
    else if (ct == 1) Q <= Q+1;
    end
endmodule
