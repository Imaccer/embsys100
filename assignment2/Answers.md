1.a. 0x20000000 or 0b00100000000000000000000000000000
 .b. 0x20000000
 .c. No flags because the result was not negative (N) or zero (Z). 
 
2.a. Changes from -1 to 0 in decimal (0xFFFFFFFF to 0x00000000).
 .b. Z - this is set as the result is 0
     C - carry condition because adding 1 caused a carry over, i.e., 0xFFFFFFFF in binary is:
       111111111111111111111111111111110 Carry
      0b11111111111111111111111111111111 (-1)
     +0b00000000000000000000000000000001
     
     Remember to account for the signed bit at start...what's the condition on the last two carry over digits being different or the same?
     
 3.a. 0x20000000
  .b. No flags. Explain... Check max range
  
 4.a. 0 (goes from 4294967295 to 0)
  .b. Z - this is set as the result is 0
      C - carry condition. look up. 
     
5.a.
 .b. No, it is not still visible in the Locals view. 
 .c. In the 'Watch 1' view.
 .d. 0x20000000
 
6.a. 4
 .b. Explain why counter value changed. Created pointer to counter variable. Incremented he dereferenced pointer 3 times. Incremented the counter value directly once. 
 
 7.a. make sure hello world removed first. may need to create new directory/workspace.