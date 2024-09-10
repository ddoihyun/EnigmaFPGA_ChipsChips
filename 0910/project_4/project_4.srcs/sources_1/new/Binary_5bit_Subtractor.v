`timescale 1ns / 1ps

module Binary_5bit_Subtractor(A, B, Borrow_in, Borrow_out, Y);

input [4:0] A, B;
input Borrow_in;
output Borrow_out;
output [4:0] Y;

wire B1, B2, B3, B4, B5;

Full_Subtractor U0( .x(A[0]), .y(B[0]), .z(Borrow_in), .B(B1), .D(Y[0]));
Full_Subtractor U1( .x(A[1]), .y(B[1]), .z(B1), .B(B2), .D(Y[1]));
Full_Subtractor U2( .x(A[2]), .y(B[2]), .z(B2), .B(B3), .D(Y[2]));
Full_Subtractor U3( .x(A[3]), .y(B[3]), .z(B3), .B(B4), .D(Y[3]));
Full_Subtractor U4( .x(A[4]), .y(B[4]), .z(B4), .B(B5), .D(Y[4]));

assign Borrow_out = B5;

endmodule
