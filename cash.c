#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompt user for dollars and convert to cents
    float dollars;
    int cents;
    do
    {
        dollars = get_float("Change owed: ");
        cents = round(dollars * 100);
    }
    while (dollars < 0);
    //count quarters
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    //count dimes
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    //count nickles
    int nickles = 0;
    while (cents >= 5)
    {
        nickles++;
        cents -= 5;
    }
    //count pennies
    int pennies = 0;
    while (cents > 0)
    {
        pennies++;
        cents -= 1;
    }
    //solution
    int solution = quarters + dimes + nickles + pennies;
    printf("%i\n", solution);
}
