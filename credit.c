#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt user for number
    long number = get_long("Number: ");
    
    //check sum
    long temp = number;
    int last;
    int sum = 0;
    while (temp > 0)
    {
        last = temp % 10;
        sum += last;
        temp = floor(temp / 10);
        if (temp > 0)
        {
            last = temp % 10;
            if ((last * 2) > 9)
            {
                sum += ((last * 2) % 10) + 1;
            }
            else
            {
                sum += last * 2;
            }
            temp = floor(temp / 10);
        }
    }
    string type;
    if (sum % 10 == 0)
    {
        //check type
        if ((number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000))
        {
            type = "AMEX";
        }
        else if ((number >= 4000000000000 && number < 5000000000000) || (number >= 4000000000000000 && number < 5000000000000000))
        {
            type = "VISA";
        }
        else if (number >= 5100000000000000 && number < 5600000000000000)
        {
            type = "MASTERCARD";
        }
        else
        {
            type = "INVALID";
        }
    }
    else 
    {
        type = "INVALID";
    }
    printf("%s\n", type);
}
