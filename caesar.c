#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char convert(char x, int k);

int main(int argc, string argv[])
{
    int len = strlen(argv[1]);

    //check for existence of argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check for validity of argument
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    //convert argument to int
    int key = atoi(argv[1]);

    //prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int text_len = strlen(plaintext);

    //convert plaintext to ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < text_len; i++)
    {
        printf("%c", convert(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

char convert(char x, int k)
{
    if (x >= 'a' && x <= 'z')
    {
        int option = (int)x + k;
        while (option > 122)
        {
            option -= 26;
        }
        return (char) option;
    }
    else if (x >= 'A' && x <= 'Z')
    {
        int option = (int)x + k;
        while (option > 90)
        {
            option -= 26;
        }
        return (char) option;
    }
    else
    {
        return x;
    }
}