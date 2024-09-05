`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/06 09:19:09
// Design Name: 
// Module Name: MainBlock
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


module MainBlock(
    input [4:0] key_in, TC,
    input Clk, rst,
    output [4:0] D_out
);


wire [4:0] tb1, tb2, tb3, rb1, rb2, rb3, to1, to2, to3, to4, to5, to6, to7, ob;
wire [4:0] result1, result2, result3;
wire overflow1, overflow2;

Tfunction1_V2       F0(.D_in(TC), .Clk(Clk), .ClrN(rst), .D_out(result1), .of(overflow1));
Tfunction2_V2       F1(.Clk(overflow1), .ClrN(rst), .D_out(result2), .of(overflow2));
Tfunction2_V2       F2(.Clk(overflow2), .ClrN(rst), .D_out(result3));

Turning_Function_1  X1(.data_in(key_in), .counter_in(result1), .data_out(to1));
Turntable1          U1(.x(to1), .A(tb1));

Turning_Function_2  X2(.data_in(tb1), .counter1(result2), .counter2(result1), .data_out(to2));
Turntable2          U2(.x(to2), .A(tb2));

Turning_Function_2  X3(.data_in(tb2), .counter1(result3), .counter2(result2), .data_out(to3));
Turntable3          U3(.x(to3), .A(tb3));

Turning_Function_3  X4(.data_in(tb3), .counter_in(result3), .data_out(to4));
reflextable         U4(.x(to4), .A(rb1));

Turning_Function_1  X5(.data_in(rb1), .counter_in(result3), .data_out(to5));
reverse3            U5(.x(to5), .A(rb2));

Turning_Function_2  X6(.data_in(rb2), .counter1(result2), .counter2(result3), .data_out(to6));
reverse2            U6(.x(to6), .A(rb3));

Turning_Function_2  X7(.data_in(rb3), .counter1(result1), .counter2(result2), .data_out(to7));
reverse1            U7(.x(to7), .A(ob));

Turning_Function_3  X8(.data_in(ob), .counter_in(result1), .data_out(D_out));

endmodule
