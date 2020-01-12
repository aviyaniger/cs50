#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string x);
int count_words(string x);
int count_sentences(string x);

int main(void)
{
    string text = get_string("Text: ");

    // average letters per 100 words
    float L = round((float) count_letters(text) * 100.00 / (float) count_words(text));

    // average sentences per 100 words
    float S = round((float) count_sentences(text) * 100.00 / (float) count_words(text));

    // find grade
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string x)
{
    int letters = 0;
    int len = strlen(x);
    for (int i = 0; i < len; i++)
    {
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string x)
{
    int words = 1;
    int len = strlen(x);
    for (int i = 0; i < len; i++)
    {
        if (x[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string x)
{
    int sentences = 0;
    int len = strlen(x);
    for (int i = 0; i < len; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}