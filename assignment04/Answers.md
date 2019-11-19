1. a. See directory /BitBandingLED

   b.  What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?

```assembly
0x800'0046: 0x2001  MOVS  R0, #1
0x800'0048: 0x490e  LDR.N R1, [PC, #0x38]
0x800'004a: 0x6008  STR   R0, R1
```
  c. What were the instructions produced when writing to the GPIOx_ODR bit[5] without using bit banding?

```assembly
0x800'0062: 0x4a0d  LDR.N R2, [PC, #0x34]
0x800'0064: 0x6813  LDR   R3, [R2]
0x800'0066: 0xf053 0x0320 ORRS.W  R3, R3, #32
0x800'006a: 0x6013  STR   R3, [R2]
```

2. a. How does the calling function pass the values to the called function?

  The variables are moved to registers R0-R3 using the MOVS command. If there are more than 4 variables, the additional variables are moved to the stack using the STR.W command.

   b. What extra code did the compiler generate before calling the function with the multiple arguments?

   Code to push register values and the LR value to the stack. These can then be popped after the function has completed to return to the next address after the function call and restore the previous register values.

```assembly
0x800'0048: 0xe92d  0x41fc  PUSH.W  {R2-R8, LR}
```

The compiler also generates the following code to pass the variables to the function being called (as described in (a)) and then branch into the function sum:

```assembly
  0x800'0058: 0xf8cd  0x8000  STR.W   R8, [SP]
  0x800'005c: 0x003b  MOVS  R3, R7
  0x800'005e: 0x0032  MOVS  R2, R6
  0x800'0060: 0x0029  MOVS  R1, R5
  0x800'0062: 0xf000 0xf802  BL sum
```

  c.  What extra code did the compiler generate inside the called function with the multiple list of arguments?

Code to push the certain register values and the LR to the stack.

```assembly
0x800'0054: 0xf05f  0x0804  MOVS.W  R8, [SP]
```
Code to move var0 from R0 to R4 (assume because R0 used in the ADD operations).
```assembly
  0x800'0070: 0x0004  MOVS  R4, R0
```
Code to load var4 from the stack into R5.
```assembly
  0x800'0072: 0x9d06  LDR   R5, [SP, #0x18]
```

  d. Any other observations?

  R0 appears to be the default for the destination register in the ADD operations performed.

  Once each function call is complete, the values placed on the stack at the beginning of the function are popped. The LR value is popped directly into the PC to return back to the appropriate instruction after the function call. For example:

  ```assembly
  0x800'008c: 0xe8bd  0x81f0  POP.W {R4-R8, PC}
  ```

3. See directory /Stack

4. See directory /Endian
