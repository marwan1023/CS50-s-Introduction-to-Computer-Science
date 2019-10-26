#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Ask you to enter your name
    string answer = get_string("What is your name?\n");
    // Print your name with hello
    printf("hello, %s\n", answer);
}