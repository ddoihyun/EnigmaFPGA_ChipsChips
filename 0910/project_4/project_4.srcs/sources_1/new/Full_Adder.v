`timescale 1ns / 1ps


module Full_Adder (x, y, z, C, S);

input x, y, z;
output C, S;

    wire net1, net2, net3;

    assign net1 = x^y;
    assign net2 = x&y;

    assign S = net1^z;
    assign net3 = net1&z;

    assign C = net3 | net2;

endmodule