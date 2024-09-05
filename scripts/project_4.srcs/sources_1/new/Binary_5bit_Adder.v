`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/06/08 18:16:50
// Design Name: 
// Module Name: Binary_4bit_Adder
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


`timescale 1ns / 1ps

module Binary_5bit_Adder(A, B, C_in, C_out, Y);

input [4:0] A, B;
input C_in;
output C_out;
output [4:0] Y;

wire C1, C2, C3, C4, C5;

Full_Adder U0( .x(A[0]), .y(B[0]), .z(C_in), .C(C1), .S(Y[0]) );
Full_Adder U1( .x(A[1]), .y(B[1]), .z(C1), .C(C2), .S(Y[1]) );
Full_Adder U2( .x(A[2]), .y(B[2]), .z(C2), .C(C3), .S(Y[2]) );
Full_Adder U3( .x(A[3]), .y(B[3]), .z(C3), .C(C4), .S(Y[3]) );
Full_Adder U4( .x(A[4]), .y(B[4]), .z(C4), .C(C5), .S(Y[4]) );

assign C_out = C5;

endmodule