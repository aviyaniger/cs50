#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // check existance of argument
    if (argc != 2)
    {
        printf("Usage: ./recover <image>\n");
        return 1;
    }

    // check validity of argument
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("file not found\n");
        return 2;
    }
    FILE *g = NULL;
    int count = 0;
    char file_name[40];
    memset(file_name, 0, sizeof(file_name));
    char buffer[512];
    do
    {
        fread(buffer, 512, 1, f);

        // check if new jpg
        if (buffer[0] == '\xFF' && buffer[1] == '\xD8' && buffer[2] == '\xFF' && (buffer[3] & '\xF0') == '\xE0')
        {
            if (g != NULL)
            {
                fclose(g);
                g = NULL;
            }

            // add to count for file name
            sprintf(file_name, "%03i.jpg", count);
            g = fopen(file_name, "a");
            if (g == NULL)
            {
                printf("failed to open %s\n", file_name);
                return 3;
            }
            fwrite(buffer, 512, 1, g);
            printf("count before: %i\n", count);
            count++;
            printf("count after: %i\n", count);
        }
        // ignore data if beginning is not beginning of jpg
        else if (count != 0)
        {
            fwrite(buffer, 512, 1, g);
        }
    }
    while (!feof(f));

    fclose(f);

    return 0;
}



