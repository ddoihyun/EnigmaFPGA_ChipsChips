`timescale 1ns / 1ps

module Full_Subtractor (x, y, z, B, D);

input x, y, z;  // �ǰ���(x), ����(y), �����Է�(z)
output D, B;    // ����(Difference), ���� ���(Borrow)

    wire net1, net2, net3;

    assign net1 = x^y;                        // �ӽ� ����
    assign net2 = (~x & y) | ((~x ^ y) & z);  // ���� ��� ���

    assign D = net1^z; // ���� ����
    assign B = net2;   // ���� ���

endmodule
