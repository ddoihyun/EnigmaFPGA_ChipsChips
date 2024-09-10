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
        .sw({trig, d_out}),           // 6개의 스위치 입력, sw[5]가 MSB (제어 신호)
        .seg(SEG)      // 7세그먼트 디스플레이 출력 (A~G)
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
