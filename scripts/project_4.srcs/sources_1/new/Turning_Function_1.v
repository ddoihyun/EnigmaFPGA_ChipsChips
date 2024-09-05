`timescale 1ns / 1ps

module Turning_Function_1(
    input [4:0] data_in, counter_in,
    output [4:0] data_out
);

wire carry_out;
wire [4:0] sum;

Binary_5bit_Adder Adder ( .A(data_in), .B(counter_in), .C_in(1'b0), .C_out(carry_out), .Y(sum) );
Binary_5bit_Modulus Modulus ( .data_in(sum), .cin(carry_out), .data_out(data_out) );

endmodule
