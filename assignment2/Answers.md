1.a. 536870912 or 0x20000000 or 0b00100000000000000000000000000000
 .b. 0x20000000
 .c. No flags because the result was not negative (N) or zero (Z). 
 
2.a. 0
 .b. Z - this is set as the result is 0
     C - carry condition because adding 1 caused a carry over, i.e., 0xFFFFFFFF in binary is:
       111111111111111111111111111111110 Carry
      0b11111111111111111111111111111111
     +0b00000000000000000000000000000001
     
