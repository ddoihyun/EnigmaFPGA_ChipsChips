`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/16 09:26:01
// Design Name: 
// Module Name: Tfunction1
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


module Tfunction1(
    input [4:0] D_in,
    input Clk,
    output [4:0] D_out,
    output of
);

wire [4:0] Q, dp;
reg [4:0] set;

Binary_5bit_Adder   U0 (.A(D_in), .B(Q), .Y(dp));

assign of = (dp > 5'b11001) ? 1:0; //overflow 발생여부 확인

initial begin //set값을 0;
    set = 5'b00000;
end

always @ (of) //of의 값이 변할경우 작동
begin 
    if(of)begin
    set <= 5'b00110; //overflow발생시 6
    end else
    begin  
    set <= 5'b00000;
    end
end

Binary_5bit_Adder   U1 (.A(dp), .B(set), .Y(D_out));
Register            U2 (.D(D_out), .Clk(Clk), .Q(Q));

endmodule
