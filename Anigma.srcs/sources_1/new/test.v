`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/12 21:13:33
// Design Name: 
// Module Name: test
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


module test(x, A);

input [4:0] x;
output A;

assign A = !x[2]&x[3]&x[4]|x[1]&!x[2]&x[4]|x[1]&x[2]&x[3]&!x[4]|x[0]&!x[1]&!x[2]&!x[4]|x[0]&x[2]&x[4];

endmodule
