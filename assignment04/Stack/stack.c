#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointers to stack elements for pushing and popping
int* pushPtr;
int* popPtr;

// LIFO Stack is Empty if pushPtr==popPtr;
// LIFO Stack is Full if pushPtr+1 > Address of last element in the stack;

// Initialize internals of the stack
void stack_init(void)
{
    pushPtr = &StackStore[0];
    popPtr = &StackStore[0];
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = '\0';
    }
}

// Push data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (pushPtr == &StackStore[STACK_SIZE])
    {
        // stack is full
        return -1;
    }
    
   *pushPtr = data;
    pushPtr++;
    popPtr=pushPtr-1;
    return 0;
}

// Pop data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (popPtr == &StackStore[0] && pushPtr==&StackStore[0])
    {
        // stack is empty
        return -1;
    }

    *data = *popPtr;
    popPtr--;
    
    if (popPtr == pushPtr-2)
    {
        pushPtr--;
    }
    
    return 0;
}
