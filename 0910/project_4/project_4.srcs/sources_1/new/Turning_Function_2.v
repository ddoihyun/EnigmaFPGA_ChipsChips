`timescale 1ns / 1ps

module Turning_Function_2(
    input [4:0] data_in,
    input [4:0] counter1, counter2,
    output [4:0] data_out
);

    // 중간 신호 선언
    wire [4:0] sum_counterdiff_data, sum_result, counter_diff;
    wire borrow_out, carry_out;
    wire carry_or_borrow;
    wire [4:0] mux_6_or_0, mux_add_or_sub;
    wire [4:0] final_sum, final_sub;
    wire unused;

    // Counter1와 Counter2의 차이 계산
    Binary_5bit_Subtractor Counter_Difference (
        .A(counter1),
        .B(counter2),
        .Borrow_in(1'b0),
        .Borrow_out(borrow_out),
        .Y(counter_diff) 
    );

    // data_in과 Counter_Difference 결과의 합 계산
    Binary_5bit_Adder CounterDiff_DataAdder ( 
        .A(data_in),
        .B(counter_diff),
        .C_in(1'b0),
        .C_out(carry_out),
        .Y(sum_counterdiff_data)
    );

    // borrow_out과 carry_out의 XOR 연산
    assign borrow_xor_carry = borrow_out ^ carry_out;

    // mux의 선택 결과 (0 또는 6) 계산
    assign mux_6_or_0 = ( (sum_counterdiff_data > 5'd25) | borrow_xor_carry == 1'b1 ) ? 5'd6 : 5'd0; 

    // 최종 합 계산
    Binary_5bit_Adder Adder ( 
        .A(sum_counterdiff_data),
        .B(mux_6_or_0),
        .C_in(1'b0),
        .C_out(unused),
        .Y(final_sum)
    );

    // 최종 차 계산
    Binary_5bit_Subtractor Subtractor ( 
        .A(sum_counterdiff_data),
        .B(mux_6_or_0),
        .Borrow_in(1'b0),
        .Borrow_out(unused),
        .Y(final_sub) 
    );

    // 최종 결과 선택
    assign data_out = (borrow_out == 1'b1) ? final_sub : final_sum;



endmodule
