`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/18 17:37:09
// Design Name: 
// Module Name: Tfunction1_V2
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


module Tfunction1_V2(
    input [4:0] D_in,
    input Clk, ClrN,
    output reg [4:0] D_out,
    output reg of
    );
    
    initial begin
    D_out = 5'b00000;
    of = 1'b0;
    end
    
    always @ (posedge Clk)
    begin
    if(ClrN == 1) //reset
    begin
    D_out <= 5'b0000;
    end
    else if(D_out+D_in >= 5'b11001)
    begin
    D_out <= D_out + 5'b00110 + D_in;
    of <= 1'b1;
    #1 of = 1'b0;
    end
    else
    begin
    D_out <= D_out+D_in;
    end
    end
    
endmodule
