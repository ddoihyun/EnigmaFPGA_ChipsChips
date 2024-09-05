`timescale 1ns / 1ps

module Binary_5bit_Modulus(
    input [4:0] data_in,   // 5비트 입력 값 (외부 카운터에서 입력)
    input cin,
    output [4:0] data_out    // 5비트 Mod-26 결과 출력
);

    // Mod-26 cjfl (Data_in이 25 이상이면 0으로 리셋, 그렇지 앟으면 count_in 유지)
    assign data_out = ( (data_in > 5'd25) || cin == 1'b1 ) ? (data_in + 5'd6): data_in; 


endmodule
