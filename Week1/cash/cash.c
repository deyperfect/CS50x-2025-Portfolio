#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_penny(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // Calculate how many quarters you should give to customer
    int quarters = calculate_quarters(cents);
    // Calculate how many dimes you should give to customer
    int dimes = calculate_dimes(cents);
    // Calculate how many nickels you should give to customer
    int nickels = calculate_nickels(cents);
    // Calculate how many pennies you should give to customer
    int pennies = calculate_penny(cents);

    // Coin Values
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Formula to calculate number of coins needed
    int excess = cents - (quarters * quarter);
    int numberofdimes = excess / dime;
    int numberofnickels = (excess - (numberofdimes * dime)) / nickel;
    int numberofpennies = (excess - (numberofdimes * dime) - (numberofnickels * nickel)) / penny;

    // Print amount of coins
    int coins = quarters + numberofdimes + numberofnickels + numberofpennies;
    {
        printf("%i\n", coins);
    }
}
int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give
    int quarters = (cents / 25);
    return quarters;
}
int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give
    int dimes = (cents / 10);
    return dimes;
}
int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give
    int nickels = (cents / 5);
    return nickels;
}
int calculate_penny(int cents)
{
    // Calculate how many pennies you should give
    int penny = (cents / 1);
    return penny;
}
