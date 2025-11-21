#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scorer(string word);

int main(void)
{
    string x = get_string("Player 1: ");
    string y = get_string("Player 2: ");
    if (scorer(x) > scorer(y))
        printf("Player 1 wins!\n");
    else if (scorer(x) < scorer(y))
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int scorer(string word)
{
    int sum = 0;
    for (int i = 0;
         ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) && word[i] != '\0';
         i++)
    {
        if (word[i] == 'A' || word[i] == 'a')
            sum += 1;
        else if (word[i] == 'B' || word[i] == 'b')
            sum += 3;
        else if (word[i] == 'C' || word[i] == 'c')
            sum += 3;
        else if (word[i] == 'D' || word[i] == 'd')
            sum += 2;
        else if (word[i] == 'E' || word[i] == 'e')
            sum += 1;
        else if (word[i] == 'F' || word[i] == 'f')
            sum += 4;
        else if (word[i] == 'G' || word[i] == 'g')
            sum += 2;
        else if (word[i] == 'H' || word[i] == 'h')
            sum += 4;
        else if (word[i] == 'I' || word[i] == 'i')
            sum += 1;
        else if (word[i] == 'J' || word[i] == 'j')
            sum += 8;
        else if (word[i] == 'K' || word[i] == 'k')
            sum += 5;
        else if (word[i] == 'L' || word[i] == 'l')
            sum += 1;
        else if (word[i] == 'M' || word[i] == 'm')
            sum += 3;
        else if (word[i] == 'N' || word[i] == 'n')
            sum += 1;
        else if (word[i] == 'O' || word[i] == 'o')
            sum += 1;
        else if (word[i] == 'P' || word[i] == 'p')
            sum += 3;
        else if (word[i] == 'Q' || word[i] == 'q')
            sum += 10;
        else if (word[i] == 'R' || word[i] == 'r')
            sum += 1;
        else if (word[i] == 'S' || word[i] == 's')
            sum += 1;
        else if (word[i] == 'T' || word[i] == 't')
            sum += 1;
        else if (word[i] == 'U' || word[i] == 'u')
            sum += 1;
        else if (word[i] == 'V' || word[i] == 'v')
            sum += 4;
        else if (word[i] == 'W' || word[i] == 'w')
            sum += 4;
        else if (word[i] == 'X' || word[i] == 'x')
            sum += 8;
        else if (word[i] == 'Y' || word[i] == 'y')
            sum += 4;
        else if (word[i] == 'Z' || word[i] == 'z')
            sum += 10;
        else
            sum += 0;
    }
    return sum;
}
