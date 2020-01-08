#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int space;

    //prompt user for number
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //create pyramid
    for (int i = 0; i < height; i++)
    {
        //print spaces
        space = height - i - 1;
        for (int k = 0; k < space; k++)
        {
            printf(" ");
        }
        //prin hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
