# __Assignment 2__

1. (a) 536,870,912

   (b) 0x20000000

   (c) No flags because the result was not negative (N) or zero (Z). There was no overflow (V) or carry over (C).

    int is a signed integer variable which can range from -2,147,483,648 to 2,147,483,647.

    The initial value injected was 0x1FFFFFFF (536,870,911) which is within the allowed range. Incremented this value by 1 gives      0x20000000 (536,870,912) which is still in range. This explains why there are no V or C flags.

2. (a) Changes from -1 to 0 in decimal (0xFFFFFFFF to 0x00000000).

   (b) Z - this is set as the result of the operation is 0

    C - carry condition.

    The carry condition is set to one for any of the following reasons:

    * if the result of an addition is greater than or equal to 2^32

    * if the result of a subtraction is positive or zero

    * as the result of an inline barrel shifter operation in a move or logical instruction.

    0xFFFFFFFF in binary is 0b11111111111111111111111111111111.
    It is a signed int, hence, the MSB indicates the sign. In this case it is a 1, indicating a negative number. Performing the two's    complement transformation gives a decimal value of -1.


      0b11111111111111111111111111111111 (-1 or 0xFFFFFFFF)
      
     +0b00000000000000000000000000000001 (1 or 0x00000001)
     ___________________________________

      0b100000000000000000000000000000000
     ___________________________________

  The result of adding 1 to 0xFFFFFFFF is a 33 bit number in binary and therefore the MSB is dropped as the register can only hold 32   bits. When the MSB is dropped, the returned value is 0. The carried over bit causes the carry condition to be positive, i.e., this is why C=1 in the APSR. Since the returned value is 0, the Z flag is 1.

3. (a) 0x20000000

   (b)  No flags because the result was not negative (N) or zero (Z). There was no overflow (V) or carry over (C).

   In this case, the incremented value of 0x1FFFFFFF+0x00000001=0x20000000 is 536,870,912 in decimal and is still within the range of   the unsigned int (max value is 2^32-1=4,294,967,295). Hence, none of the flags are set in APSR.

4. (a) 0 (goes from 4,294,967,295 to 0)

   (b) Z - this is set as the result is 0
       C - carry condition.

      The carry flag is 1 because the result of adding 1 to 4,294,967,295 is equal to 4,294,967,296=2^32. This satisfies one of the  conditions for the C flag to be set.
      The result of the addition is in binary:

      0b100000000000000000000000000000000

      which is 33 bits and cannot be stored in a 32 bit register. C is flagged and the MSB is dropped which results in a returned value  of 0. Hence, the zero condition is flagged.

5. (a) Global

   (b) No.

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


# __References__
http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/BABEHFEF.html
