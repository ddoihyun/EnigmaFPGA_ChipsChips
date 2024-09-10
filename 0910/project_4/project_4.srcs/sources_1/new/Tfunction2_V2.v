`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/18 18:31:33
// Design Name: 
// Module Name: Tfunction2_V2
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


module Tfunction2_V2(
    input Clk, ClrN,
    output reg [4:0] D_out,
    output reg of
);
    
    initial begin
        D_out = 5'b00000;
        of = 1'b0;
    end
    
    always @ (posedge Clk) begin
        if(ClrN == 1) begin
            D_out <= 5'b0000;
            of <= 1'b0;
        end else if(D_out >= 5'b11001) begin
            D_out <= D_out - 5'b11001;
            of <= 1'b1;
        end else begin
            D_out <= D_out+1;
            of <= 1'b0;
        end
    end
    
endmodule
