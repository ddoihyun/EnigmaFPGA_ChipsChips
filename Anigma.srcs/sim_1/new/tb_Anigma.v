`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/08/06 10:35:35
// Design Name: 
// Module Name: tb_Anigma
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


module tb_Anigma();

reg [4:0] A_in;
wire [4:0] Y_out;

MainBlock DUT(
    .ib(A_in),
    .ob(Y_out)
);



initial begin
    A_in = 5'b00001;
end

endmodule
