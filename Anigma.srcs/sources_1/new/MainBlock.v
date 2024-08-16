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


module MainBlock(ib, ob);

input [4:0] ib;
output [4:0] ob;

wire [4:0] tb1, tb2, tb3, rb1, rb2, rb3;

Turntable1  U1(.x(ib), .A(tb1));
Turntable2  U2(.x(tb1), .A(tb2));
Turntable3  U3(.x(tb2), .A(tb3));
reflextable U4(.x(tb3), .A(rb1));
reverse3    U5(.x(rb1), .A(rb2));
reverse2    U6(.x(rb2), .A(rb3));
reverse1    U7(.x(rb3), .A(ob));

endmodule
