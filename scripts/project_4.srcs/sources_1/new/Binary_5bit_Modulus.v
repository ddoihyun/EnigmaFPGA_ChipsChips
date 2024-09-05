`timescale 1ns / 1ps

module Binary_5bit_Modulus(
    input [4:0] data_in,   // 5��Ʈ �Է� �� (�ܺ� ī���Ϳ��� �Է�)
    input cin,
    output [4:0] data_out    // 5��Ʈ Mod-26 ��� ���
);

    // Mod-26 cjfl (Data_in�� 25 �̻��̸� 0���� ����, �׷��� ������ count_in ����)
    assign data_out = ( (data_in > 5'd25) || cin == 1'b1 ) ? (data_in + 5'd6): data_in; 


endmodule
