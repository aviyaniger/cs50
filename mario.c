#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for number
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //build pyramids
    int space;
    for (int i = 1; i <= height; i++)
    {
        //first spaces
        space = height - i;
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        //first hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //gap
        printf("  ");
        //second hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //second spaces
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
