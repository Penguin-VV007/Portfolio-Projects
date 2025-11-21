#include <cs50.h>
#include <stdio.h>

void printrowlp(int height)
{
    int spaces = height - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        spaces--;

        for (int k = i; k < i + 1; k++)
        {
            for (int l = 0; l <= k; l++)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int len;
    do
    {
        len = get_int("Height: \n");
    }
    while (len <= 0);

    printrowlp(len);
}
