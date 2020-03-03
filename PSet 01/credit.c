#include <cs50.h>
#include <stdio.h>

int last_numbers(long long input1, long long input2);
int second_last_numbers(long long input1, long long input2);

// Functions to get the last numbers and second last numbers defined.
int last_numbers(long long cc_number_calculation, long long  digit_count_calculation)
{
    if (digit_count_calculation >= 2)
    {
        // Mod 10 will give the last digit of a number.
        int number1 = (cc_number_calculation % 10);
        digit_count_calculation -= 2;
        return number1;
    }
    else
    {
        return 0;
    }
}

int second_last_numbers(long long cc_number_calculation, long long digit_count_calculation)
{
    if (digit_count_calculation >= 2)
    {
        // Mod 100 will give the last 2 digits of a number. This is then divided by
        // 10 in order to get the second to last digit.
        int number = ((cc_number_calculation % 100) / 10) * 2;
        // This gets the individual digits from a number and adds them together.
        int digit0 = number % 10;
        number = number / 10;
        int digit1 = number % 10;
        number = number / 10;
        int total1 = digit0 + digit1;
        return total1;
    }
    else
    {
        return 0;
    }
}

// Start the program.
int main(void)
{
    // Declares the credit card number variable.
    long long cc_number;
    
    // Asks the user for a credit card number and keeps asking if invalid.
    do
    {
        cc_number = get_long_long("Enter credit card number: ");
    }
    while (cc_number <= 0);
    
    int digit_count = 0;
    long long digit_count_check = cc_number;
    while (digit_count_check != 0)
    {
        digit_count++;
        digit_count_check /= 10;
    }
    
    while (digit_count < 13 || digit_count > 16 || digit_count == 14)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // CALCULATION
    // Variables commom to each calculation are defined here.
    long long cc_number_calculation = cc_number;
    long long digit_count_calculation = digit_count;
    int no1, no2, no3, no4, no5, no6, no7, no8, no9, no10, no11, no12, no13, no14, no15, no16;
    
    no1 = last_numbers(cc_number_calculation, digit_count_calculation);
    no2 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
   
    no3 = last_numbers(cc_number_calculation, digit_count_calculation);
    no4 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
    
    no5 = last_numbers(cc_number_calculation, digit_count_calculation);
    no6 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
    
    no7 = last_numbers(cc_number_calculation, digit_count_calculation);
    no8 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
    
    no9 = last_numbers(cc_number_calculation, digit_count_calculation);
    no10 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
    
    no11 = last_numbers(cc_number_calculation, digit_count_calculation);
    no12 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    cc_number_calculation /= 100;
    
    no13 = last_numbers(cc_number_calculation, digit_count_calculation);
    
    if (digit_count >= 15)
    {
        no14 = second_last_numbers(cc_number_calculation, digit_count_calculation);
        cc_number_calculation /= 100;
        no15 = last_numbers(cc_number_calculation, digit_count_calculation);
    }
    else
    {
        no14 = 0;
        no15 = 0;
    }
    
    // Similar to above it is necessary to check if the card has 16 or more digits.
    if (digit_count >= 16)
    {
        no16 = second_last_numbers(cc_number_calculation, digit_count_calculation);
    }
    else
    {
        no16 = 0;
    }
    // END OF CALCULATION
    
    // Get the totals.
    int total0 = no2 + no4 + no6 + no8 + no10 + no12 + no14 + no16;
    int total1 = no1 + no3 + no5 + no7 + no9 + no11 + no13 + no15;
    int total2 = total0 + total1;
    
    // Get the last digit of the total.
    int totals_last_digit_check = (total2 % 10);
    
    // Check if the last digit of the total equals 0.
    if (totals_last_digit_check != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (digit_count == 15 && no15 == 3 && ((no14 / 2 == 4 || (no14 - 1 + 10) / 2 == 7)))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (digit_count == 16 && (no16 - 1 + 10) / 2 == 5 && no15 >= 1 && no15 <= 5)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((digit_count == 13 && no13 == 4) || (digit_count == 16 && no16 / 2 == 4))
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}