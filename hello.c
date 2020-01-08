#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //promt user name
    string name = get_string("What is your name?\n");
    
    //greet user
    printf("hello, %s\n", name);
}
