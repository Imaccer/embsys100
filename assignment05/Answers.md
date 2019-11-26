1. a. The main function first pushes R3-R5 and the LR  onto the stack:
```assembly
  PUSH {R3-R5, LR}
```
It then extends the stack to accommodate the 2 ints and 4 pointers contained in main:
```assembly
  SUB SP, SP, #0x10
```
It then moves the int values and pointer values into the allocated space on the stack.

The final step before calling the swap_pointer function is moving the arguments to registers R0 and R1:
```assembly
  MOVS R1, R5
  MOVS R0, R4
```

   b. R0 contains 0x200003E4 which is the address of the xPtr variable which is currently also on the stack.

  R1 contains 0x200003E0 which is the address of the yPtr variable which is also the location of the SP (i.e., it is at the top of the stack).

   c.

<p align="center">
<img src=SS_1c width="300">
</p>


2. a,b,c,d. Done.

   e.  

   <p align="center">
   <img src=SS_2e.png width="300">
   </p>

3. a,b,c. Done. See assembly file div2Asm.s

  d.

  <p align="center">
  <img src=SS_3d.png width="300">
  </p>

4. a, c. See assembly file swapCharsAsm.s

Note, did not have time to complete Bonus parts this week. 
