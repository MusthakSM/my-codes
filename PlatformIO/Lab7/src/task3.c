/*
 *  Lab 7 - EEPROM / LCD / Keypad
 *  Task3
 *  Group 17: 
 *  E/19/244, Hamshica M. 
 *  E/19/247, Musthak S.M.
 *  E/19/249, SMuthukumarana M.P.S.A.
 * 
*/


#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <lcd.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Keypad matrix
unsigned char keypad[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Function to get the key pressed from the keypad matrix
char get_key(void)
{
  DDRD |= ((1<<PD6) | (1<<PD7));// PD6 and PD7 output
  PORTB |= ((1<<PB0) | (1 << PB1)| (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5));// PB0 - PB5 pull-up
  
  for (int row = 0; row < 2; row++)// Loop through the rows
  {
    PORTD = ~(0x40 << row); // ground the current row for PD6 and PD7

    for (int col = 0; col < 4; col++) // Loop through the columns
    {
      if (!(PINB & (0x04 << col))) // read the current column from PB2 - PB5
       {
        _delay_ms(200); // Debouncing delay
        if (!(PINB & (0x04 << col))) // Check again after delay
        {
          return keypad[row][col];// Return the key pressed
        }
      }
    }
  }

  for (int row = 2; row < 4; row++)// Loop through the rows
  {
    PORTB = ~(0x01 << (row - 2)); // ground the current row for PB0 and PB1

    for (int col = 0; col < 4; col++)// Loop through the columns
    {
      if (!(PINB & (0x04 << col))) // read the current column from PB2 - PB5
       {
        _delay_ms(200); // Debouncing delay
        if (!(PINB & (0x04 << col))) // Check again after delay
        {
          return keypad[row][col];// Return the key pressed
        }
      }
    }
  }

  return 'x'; // no key pressed
}


void write_to_eeprom(unsigned int address,  char data)// Function to write the data to EEPROM
{
  // Wait for completion of previous write 
  while(EECR & (1<<EEPE));

  // Set up address and Data Registers
  EEAR = address;
  EEDR = data;

  // Write logical one to EEMPE
  EECR |= (1<<EEMPE);

  // Start eeprom write by setting EEPE 
  EECR |= (1<<EEPE);
}

char read_from_eeprom(unsigned int address)// Function to read the data from EEPROM
{
  // Wait for completion of previous write
  while(EECR & (1<<EEPE));

  // Set up address register
  EEAR = address;

  // Start eeprom read by writing EERE
  EECR |= (1<<EERE);

  // Return data from Data Register
  return EEDR;
}


void caesar_cipher(char *string, int key)// Function to encrypt the string using Caesar Cipher
{
  for(int i=0; i<strlen(string); i++)// Loop through the string
  {
  if(string[i] >= 'a' && string[i] <= 'z')// if the character is lowercase
  {
    string[i] = (string[i] - 'a' + key) % 26 + 'a'; // encrypt the character
  }
  else if(string[i] >= 'A' && string[i] <= 'Z')
  {
    string[i] = (string[i] - 'A' + key) % 26 + 'A';// encrypt the character
  }
  }
}


int main(void)
{
  char input_string[15] = {0};  // to store the string
  char temp[2]; // to store the temporary character
  char key;
  int secret_key ; // secret key to encrypt the string

  DDRD |= 0xC0; // PD6 and PD7 output
  DDRB |= 0x03; // PB0 and PB1 output
  DDRB &= ~((1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5)); // PB2 - PB5 input

  lcd_init(LCD_DISP_ON); // initialize display, cursor off

  while(1)
  {   
    lcd_clrscr(); // clear display and home cursor
    lcd_puts("1. Encrypt\n2. Change key\n");
    _delay_ms(200);

    if ((key = get_key()) == '1')
    {
      lcd_clrscr(); // clear display and home cursor
      lcd_command(LCD_DISP_ON_CURSOR);
      lcd_puts("Enter string:\n");
      while(1)
      {
        key = get_key();
        if (key == '#' || strlen(input_string) == 10)
        {   
          lcd_clrscr(); // clear display and home cursor
          break;
        }
        else if(key != 'x')
        {
          lcd_putc(key);
          temp[0] = key;
          temp[1] = '\0';    // add null character to the end of the string
          strcat(input_string, temp);
          
        }
      
      }

      /* turn off cursor */
      lcd_command(LCD_DISP_ON);
      lcd_puts("Encrypted..!\n");
      secret_key = (read_from_eeprom(0)) - '0'; // read the secret key from the EEPROM
       
      caesar_cipher(input_string, secret_key); // encrypt the string
      lcd_puts(input_string);

      memset(input_string, 0, sizeof(input_string)); // clear the string
      //_delay_ms(3000);
      while (get_key() != '#'); // wait until the user presses x to go back to the main menu

    }

    else if (key == '2')
    {  
      lcd_clrscr(); // clear display and home cursor
      lcd_puts("Enter New Key:\n");

      while (1)
      {
        /* turn on cursor */
        lcd_command(LCD_DISP_ON_CURSOR);
        key = get_key();
        

        if (isdigit(key) && key != 'x')
        {
          
          lcd_putc(key);
          _delay_ms(1500);

          /* turn off cursor */
          lcd_command(LCD_DISP_ON);
          
          write_to_eeprom(0, key); // store the secret key in the EEPROM

          lcd_clrscr(); // clear display and home cursor
          lcd_puts("Key Changed as:");
          lcd_putc(key);
          _delay_ms(3000);
          break;  
          
        }
        else if(!(isdigit(key)) && key != 'x') // if key is not a digit
        {
          lcd_gotoxy(0,1);
          lcd_puts("               ");
          lcd_gotoxy(0,1);
          lcd_puts("Invalid Input!");
          _delay_ms(2000);
          lcd_gotoxy(0,1);
          lcd_puts("               ");
          lcd_gotoxy(0,1);
  
        }
        
      }
      
    }

    else if (key != 'x')
    {   
      lcd_clrscr(); // clear display and home cursor
      lcd_puts("Invalid Input!");
      _delay_ms(1500);
    }

  }
  

  return 0;
}
