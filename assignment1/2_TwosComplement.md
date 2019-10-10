# __2. Two's Complement__
Question: Why use two’s complement to represent negative numbers?

Answer: Two's complement is useful for simplifying the implementation of arithmetic on computer hardware. Two's complement is used to represent negative numbers because it allows the addition of operands without a subtraction circuit or a circuit that detects the sign of the operands. An addition circuit can perform subtraction by taking the two's complement of a number which only requires an additional cycle (or its own adder circuit).
