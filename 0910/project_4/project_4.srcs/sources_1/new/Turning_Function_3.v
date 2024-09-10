`timescale 1ns / 1ps

module Turning_Function_3(
    input [4:0] data_in, counter_in,
    output [4:0] data_out
);

    // �߰� ��ȣ ����
    wire borrow_out;
    wire [4:0] counter_diff;
    wire [4:0] mux_6_or_0;
    wire unused;

    // data_in�� counter_in�� ���� ���
    Binary_5bit_Subtractor Counter_Difference (
        .A(data_in),
        .B(counter_in),
        .Borrow_in(1'b0),
        .Borrow_out(borrow_out),
        .Y(counter_diff) 
    );

    // mux�� ���� ��� (0 �Ǵ� 6) ���
    assign mux_6_or_0 = ( counter_diff > 5'd25 || borrow_out == 1'b1 ) ? 5'd6 : 5'd0; 

    // ���� �� ���
    Binary_5bit_Subtractor Final_Difference (
        .A(counter_diff),
        .B(mux_6_or_0),
        .Borrow_in(1'b0),
        .Borrow_out(unused),
        .Y(data_out) 
    );

endmodule
