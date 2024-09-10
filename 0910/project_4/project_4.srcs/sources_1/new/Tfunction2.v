`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/18 14:08:24
// Design Name: 
// Module Name: Tfunction2
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


module Tfunction2(
    input Clk,
    output [4:0] D_out,
    output of
    );
    
    reg check;
    
    initial begin
    check = 1'b0;
    end
    
    counter_74163   U0 (.ct(1'b1), .LdN(check), .D(5'b00000), .Clk(Clk), .Q(D_out));
    wire borrow_xor_carry;
    always @ (*)
    begin
    if(D_out >= 5'b11001) check <= 1;
    else check <= 0;
    end
    
endmodule
