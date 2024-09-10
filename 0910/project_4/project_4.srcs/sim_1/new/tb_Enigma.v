`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/29 17:02:57
// Design Name: 
// Module Name: tb_Enigma
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


module tb_Enigma();

reg [4:0] A_in, D_in;
reg Clk, en, rst;
wire [4:0] Y_out;

counter_74163 U0 (.ct(en), .LdN(1'b0), .Clk(Clk), .ClrN(rst), .D(A_in), .Q(Y_out));
wire [4:0] tb1, tb2, tb3, rb1, rb2, rb3, to1, to2, to3, to4, to5, to6, to7, ob;
wire [4:0] result1, result2, result3, final;
wire overflow1, overflow2;

Tfunction1_V2 F0 (.D_in(D_in), .Clk(Clk), .ClrN(rst), .D_out(result1), .of(overflow1));
Tfunction2_V2 F1 (.Clk(overflow1), .ClrN(rst), .D_out(result2), .of(overflow2));
Tfunction2_V2 F2 (.Clk(overflow2), .ClrN(rst), .D_out(result3));

Turning_Function_1 X1 (.data_in(Y_out), .counter_in(result1), .data_out(to1));
Turntable1         U1 (.x(to1), .A(tb1));

Turning_Function_2   X2(.data_in(tb1), .counter1(result2), .counter2(result1), .data_out(to2));
Turntable2  U2(.x(to2), .A(tb2));

Turning_Function_2   X3(.data_in(tb2), .counter1(result3), .counter2(result2), .data_out(to3));
Turntable3  U3(.x(to3), .A(tb3));

Turning_Function_3   X4(.data_in(tb3), .counter_in(result3), .data_out(to4));
reflextable U4(.x(to4), .A(rb1));

Turning_Function_1   X5(.data_in(rb1), .counter_in(result3), .data_out(to5));
reverse3    U5(.x(to5), .A(rb2));

Turning_Function_2   X6(.data_in(rb2), .counter1(result2), .counter2(result3), .data_out(to6));
reverse2    U6(.x(to6), .A(rb3));

Turning_Function_2   X7(.data_in(rb3), .counter1(result1), .counter2(result2), .data_out(to7));
reverse1    U7(.x(to7), .A(ob));

Turning_Function_3   X8(.data_in(ob), .counter_in(result1), .data_out(final));


always @(*) begin
    #10 Clk <= ~Clk;
end

initial begin
    Clk = 1'b1;
    rst = 1'b1;
    A_in = 5'b00000;
    D_in = 5'b01001;
    en = 1'b1;
    #1
    rst = 1'b0;
end

endmodule


