`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/09/05 14:21:26
// Design Name: 
// Module Name: IO_module
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


module IO_module(
    input [5:0] sw,           // 6개의 스위치 입력, sw[5]가 MSB (제어 신호)
    output reg [6:0] seg      // 7세그먼트 디스플레이 출력 (A~G)
);

always @(sw) begin
    if (sw[5] == 1) begin // MSB가 1인 경우
        case (sw[4:0]) // 5개의 입력 스위치를 기반으로 알파벳 선택
        5'b00000: seg = 7'b0001000; // A
        5'b00001: seg = 7'b0000011; // b
        5'b00010: seg = 7'b1000110; // C
        5'b00011: seg = 7'b0100001; // d
        5'b00100: seg = 7'b0000110; // E
        5'b00101: seg = 7'b0001110; // F
        5'b00110: seg = 7'b1000010; // G
        5'b00111: seg = 7'b0001011; // H
        5'b01000: seg = 7'b1111011; // I
        5'b01001: seg = 7'b1110001; // J
        5'b01010: seg = 7'b0001111; // K
        5'b01011: seg = 7'b1000111; // L
        5'b01100: seg = 7'b0101010; // M
        5'b01101: seg = 7'b0101011; // N
        5'b01110: seg = 7'b1000000; // O
        5'b01111: seg = 7'b0001100; // P
        5'b10000: seg = 7'b0011000; // Q
        5'b10001: seg = 7'b0101111; // R
        5'b10010: seg = 7'b0010010; // S
        5'b10011: seg = 7'b0000111; // T
        5'b10100: seg = 7'b1000001; // U
        5'b10101: seg = 7'b1100011; // V
        5'b10110: seg = 7'b1100010; // W
        5'b10111: seg = 7'b0001001; // X
        5'b11000: seg = 7'b0001101; // Y
        5'b11001: seg = 7'b0110110; // Z
        default: seg = 7'b1111111;
        endcase
    end else begin
        seg = 7'b1111111; // MSB가 0인 경우, 표시 안함
    end
end

endmodule
