`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/16 09:36:03
// Design Name: 
// Module Name: Register
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


module Register(
    input [4:0] D,
    input Clk,
    output reg [4:0] Q
    );
    
initial begin
    Q = 5'b00000;
end

always @ (posedge Clk)
    begin 
        Q <= D;
    end

endmodule
