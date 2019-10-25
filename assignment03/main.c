//GPIOA and RCC register address macros
#define RCC_BASE 0x40023800
#define  RCC_AHB1ENR (*((unsigned int*)(RCC_BASE+0x30)))
#define GPIOA_BASE 0x40020000
#define  GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define  GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//define 1 unit of time for morse (i.e., length of dot)
#define MORSE_UNIT 1000000

//private function declarations
void delay(unsigned int t);
void dot(void);
void dash(void);
void wordspace(void);
void letterspace(void);

int main()
{
    //1. Enable clock to peripheral
    RCC_AHB1ENR = 0x1;

    //2. Set GPIO port to output mode 
    GPIOA_MODER |=0x400;
    
    //3. Blink LD2 to transmit morse message 'IAN'
    while(1)
   {
     // I
     dot();
     dot();
     letterspace();
     //A
     dot();
     dash();
     letterspace();
     //N
     dash();
     dot();
     
     //Gap before word repeated
     wordspace();
   }
  return 0;
}

//Function to invoke a delay of a specified time
void delay(unsigned int t)
{
  while(t)
  {
    t--;
  }
}

//Function to blink a dot to LD2
void dot(void)
{
  GPIOA_ODR |=0x20;//turn on
  delay(MORSE_UNIT);
  GPIOA_ODR &= 0x00;//turn off
  delay(MORSE_UNIT);//Wait for 1 MORSE_UNIT to place space between parts of the same letter
}

//Function to blink a dash to LD2
void dash(void)
{
  GPIOA_ODR |=0x20;//turn on LD2
  delay(3*MORSE_UNIT);//Wait for 3 MORSE_UNITS to signal a dash
  GPIOA_ODR &= 0x00;//turn off
  delay(MORSE_UNIT);//Wait for 1 MORSE_UNIT to place space between parts of the same letter
}

//Function to wait for the space between letters
void letterspace(void)
{
  delay(2*MORSE_UNIT);//Wait for 2 additional MORSE_UNITs between letters for a total wait of 3 MORSE_UNITs
}

//Function to wait for the space between words
void wordspace(void)
{
  delay(6*MORSE_UNIT);//Wait for 6 additional MORSE_UNITs between words for a total wait of 7 MORSE_UNITs
}


