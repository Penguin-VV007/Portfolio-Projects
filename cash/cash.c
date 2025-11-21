#include <cs50.h>
#include <stdio.h>

void changedispenser(int change);

int main(void)
{
    int x;
    do
    {
        x = get_int("Change owed: ");
    }
    while (x <= 0);
    changedispenser(x);
}

void changedispenser(int change)
{
    int count = 0;

    if ((change / 25) > 0)
    {
        while ((change / 25) > 0)
        {
            count++;
            change = change - 25;
        }
    }

    if ((change / 10) > 0)
    {
        while ((change / 10) > 0)
        {
            count++;
            change = change - 10;
        }
    }

    if ((change / 5) > 0)
    {
        while ((change / 5) > 0)
        {
            count++;
            change = change - 5;
        }
    }

    if ((change / 1) > 0)
    {
        while ((change / 1) > 0)
        {
            count++;
            change = change - 1;
        }
    }

    printf("%i\n", count);
}
