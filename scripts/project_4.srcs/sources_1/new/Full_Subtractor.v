`timescale 1ns / 1ps

module Full_Subtractor (x, y, z, B, D);

input x, y, z;  // 피감수(x), 감수(y), 차용입력(z)
output D, B;    // 차이(Difference), 차용 출력(Borrow)

    wire net1, net2, net3;

    assign net1 = x^y;                        // 임시 차이
    assign net2 = (~x & y) | ((~x ^ y) & z);  // 차용 출력 계산

    assign D = net1^z; // 최종 차이
    assign B = net2;   // 차용 출력

endmodule
