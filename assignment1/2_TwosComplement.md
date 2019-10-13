# __2. Two's Complement__
Question: Why use two’s complement to represent negative numbers?

Answer: Two's complement is useful for simplifying the implementation of arithmetic on computer hardware. Two's complement is used to represent negative numbers because it allows the addition of operands without a subtraction circuit or a circuit that detects the sign of the operands. An addition circuit can perform subtraction by taking the two's complement of a number which only requires an additional cycle (or its own adder circuit).

Subtraction is equivalent to the addition of a negative number. 

For example, consider subtracting 20 from 31. Normally this would be expressed as: 31-20. However, we can instead write 31 + (-20).

The first step is to express -20 in two's complement:

    20 in binary: 0b00010100
    Invert:       0b11101011
    Plus 1:       0b11101100

Hence, the two's complement representation of (-20) is: 0b11101100

We can now perform the subtraction operation (or more accurately, addition):

                 Carry row
      0b00011111 (31)  
    + 0b11101100 (-20)  
    

 
