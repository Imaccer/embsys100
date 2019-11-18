#include<assert.h>
#include"stack.h"


int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 43;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(-1 == result1);
    assert(43 == testInt);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_push(10);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(10 == testInt);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 42;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);                                    
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(3 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(2 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(1 == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 42;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(-1 == stack_push(4));

    assert(0 == stack_pop(&testInt));
    assert(3 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(2 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(1 == testInt);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retrieve all
    // ***********************************************************************
    // Arrange:
    testInt = 42;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(3 == testInt);
    
    assert(0 == stack_push(4));
    
    assert(0 == stack_pop(&testInt));
    assert(4 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(2 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(1 == testInt);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testInt = 42;
    stack_init();
    
    // Act:
    assert(0 == stack_push(1));
    assert(0 == stack_push(2));
    assert(0 == stack_push(3));
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(3 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(2 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(1 == testInt);

    assert(0 == stack_push(4));
    assert(0 == stack_push(5));
    assert(0 == stack_push(6));

    assert(0 == stack_pop(&testInt));
    assert(6 == testInt);
   
    assert(0 == stack_pop(&testInt));
    assert(5 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(4 == testInt);

    return 0;
}
