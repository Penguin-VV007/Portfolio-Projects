#include <cs50.h>
#include <stdio.h>

void print_pyramid(int height)
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

        printf("  ");

        for (int m = 0; m <= i; m++)
        {
            printf("#");
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

    print_pyramid(len);
}
