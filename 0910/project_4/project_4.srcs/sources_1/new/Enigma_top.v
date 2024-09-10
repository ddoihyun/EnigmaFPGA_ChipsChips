module Enigma_top(
input [5:0] SW,
input BTNC,
output [4:0] LED,
output [6:0] SEG,
output [7:0] AN
);
    wire [4:0] d_out;
    wire trig = SW[5];
    reg [4:0] count;
    
    MainBlock U0 (
    .key_in(SW[4:0]),
    .TC(count),
    .Clk(trig),
    .rst(BTNC),
    .D_out(d_out)
    );
    
    IO_module U1 (
        .sw({trig, d_out}),           // 6���� ����ġ �Է�, sw[5]�� MSB (���� ��ȣ)
        .seg(SEG)      // 7���׸�Ʈ ���÷��� ��� (A~G)
    );
    
    always @(posedge trig, posedge BTNC) begin
        if(BTNC)
            count <= 0;
        else if(count < 26)
            count <= count  + 1;
        else
            count <= 0;
    end

   assign LED = d_out;
   assign AN = 8'b11111110;
    
endmodule
