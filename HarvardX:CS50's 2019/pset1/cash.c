#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    // Taking input from user
    float f;
    // Count variable to count no of coins
    int c = 0;
    // Getting the change owed
    do
    {
        f = get_float("Change owed: ");
    }
    while (f < 0);
    // Converting Dollars to Cents
    int cents = round(f * 100);
    // Checking the coins to be used
    while (cents >= 25)
    {
        c = c + 1;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        c = c + 1;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        c = c + 1;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        c = c + 1;
        cents = cents - 1;
    }
    // Print no of coins used
    printf("%i\n", c);
}
