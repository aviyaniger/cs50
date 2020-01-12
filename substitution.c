#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char convert(char x, char k);

int main(int argc, string argv[])
{
    //check for existence of argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check validity of argument
    int len = strlen(argv[1]);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] < 'A' || argv[1][i] > 'z' || (argv[1][i] > 'Z' && argv[1][i] < 'a'))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j] && i != j)
                {
                    printf("Each character of key must occur only once.\n");
                    return 1;
                }
            }
        }
    }

    //prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int text_len = strlen(plaintext);

    //convert plaintext to ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < text_len; i++)
    {
        int k = (int) tolower(plaintext[i]) - 97;
        printf("%c", convert(plaintext[i], argv[1][k]));
    }
    printf("\n");
    return 0;
}

char convert(char x, char k)
{
    if (x >= 'a' && x <= 'z')
    {
        return tolower(k);
    }
    else if (x >= 'A' && x <= 'Z')
    {
        return toupper(k);
    }
    else
    {
        return x;
    }
}