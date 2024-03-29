volatile int counter=0;

void main(void)
{
    
    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    //RCC_AHB1ENR |= 0x1;//read modify write method. 
    //below is bit band way of doing same as line above
    
    *((unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4)))= 0x1;//type cast to pointer, write to it by dereferencing. Bit banding to write directly to the bit.

    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    //GPIOA_MODER |= 0x400;
    
    *((unsigned int*)((0x42000000) + (0x20000 * 32) + (10 * 4)))= 0x1;//Bit banding method to set GPIO to output mode

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR |= GPIOA;
    *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4)))= 0x1;//Turn on LED with bit banding method
        
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    //GPIOA_ODR &= ~GPIOA;
    *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4)))= 0x0;//Turn off LED with bit banding method

    }
}