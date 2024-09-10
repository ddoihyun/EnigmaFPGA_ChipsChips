`timescale 1ns / 1ps

module Turning_Function_2(
    input [4:0] data_in,
    input [4:0] counter1, counter2,
    output [4:0] data_out
);

    // �߰� ��ȣ ����
    wire [4:0] sum_counterdiff_data, sum_result, counter_diff;
    wire borrow_out, carry_out;
    wire carry_or_borrow;
    wire [4:0] mux_6_or_0, mux_add_or_sub;
    wire [4:0] final_sum, final_sub;
    wire unused;

    // Counter1�� Counter2�� ���� ���
    Binary_5bit_Subtractor Counter_Difference (
        .A(counter1),
        .B(counter2),
        .Borrow_in(1'b0),
        .Borrow_out(borrow_out),
        .Y(counter_diff) 
    );

    // data_in�� Counter_Difference ����� �� ���
    Binary_5bit_Adder CounterDiff_DataAdder ( 
        .A(data_in),
        .B(counter_diff),
        .C_in(1'b0),
        .C_out(carry_out),
        .Y(sum_counterdiff_data)
    );

    // borrow_out�� carry_out�� XOR ����
    assign borrow_xor_carry = borrow_out ^ carry_out;

    // mux�� ���� ��� (0 �Ǵ� 6) ���
    assign mux_6_or_0 = ( (sum_counterdiff_data > 5'd25) | borrow_xor_carry == 1'b1 ) ? 5'd6 : 5'd0; 

    // ���� �� ���
    Binary_5bit_Adder Adder ( 
        .A(sum_counterdiff_data),
        .B(mux_6_or_0),
        .C_in(1'b0),
        .C_out(unused),
        .Y(final_sum)
    );

    // ���� �� ���
    Binary_5bit_Subtractor Subtractor ( 
        .A(sum_counterdiff_data),
        .B(mux_6_or_0),
        .Borrow_in(1'b0),
        .Borrow_out(unused),
        .Y(final_sub) 
    );

    // ���� ��� ����
    assign data_out = (borrow_out == 1'b1) ? final_sub : final_sum;



endmodule
