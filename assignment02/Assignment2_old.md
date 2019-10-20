# __Assignment 2__

1. (a) 0x20000000

 (b). 0x20000000

 (c) No flags because the result was not negative (N) or zero (Z).

2. (a) Changes from -1 to 0 in decimal (0xFFFFFFFF to 0x00000000).

 (b) Z - this is set as the result is 0
     C - carry condition because adding 1 caused a carry over, i.e., 0xFFFFFFFF in binary is:
    ```  
       111111111111111111111111111111110 Carry
      0b11111111111111111111111111111111 (-1 or 0xFFFFFFFF)
     +0b00000000000000000000000000000001 (1 or 0x00000001)
     ___________________________________

      0b00000000000000000000000000000000 (0 or 0x00000000)
     ___________________________________

     ```
     Remember to account for the signed bit at start...what's the condition on the last two carry over digits being different or the same?

3. (a) 0x20000000

    (b) No flags. Explain... Check max range

4. (a) 0 (goes from 4294967295 to 0)

  (b) Z - this is set as the result is 0
      C - carry condition. look up.

5. (a) Global

 (b) No, it is not still visible in the Locals view.

 (c) In the 'Watch 1' view.

 (d) 0x20000000

6. (a) 4

   (b) Initially, the integer variable ```counter``` is declared outside of ```main```. This means it is stored in memory (at address 0x20000000).

   In the first line of ```main``` a pointer of type int is defined:

   ```int *p_int = (int*)0x20000000;```

   This points to the address that ```counter``` is stored at. ```(int*)``` explicitly casts the address to integer type.

   The statement:

   ```++(*p_int)```

   * ```(*p_int)``` returns the value stored at the address that ```p_int``` points to (in this case 0, the value of counter).  
   * ```++``` then increments this value.

   This is repeated 2 more times.

   Then, the statement:

   ```counter++;```

   has the same effect. It directly increments the value of the ```counter``` variable. In total, ```counter``` has been incremented 4 times. As it was initialized to 0, its final value is 4.

7. (a) 0x20000000

  (b) RAM

  (c) 4
