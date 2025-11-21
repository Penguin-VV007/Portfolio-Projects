#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string a);
int words(string a);
int sentences(string a);
double ColemanLiau_Algorithm(string a);

int main(void)
{
    string text = get_string("Text: ");
    if (ColemanLiau_Algorithm(text) < 2)
        printf("Before Grade 1");
    else if (ColemanLiau_Algorithm(text) == 2)
        printf("Grade 2");
    else if (ColemanLiau_Algorithm(text) == 3)
        printf("Grade 3");
    else if (ColemanLiau_Algorithm(text) == 5)
        printf("Grade 5");
    else if (ColemanLiau_Algorithm(text) == 7)
        printf("Grade 7");
    else if (ColemanLiau_Algorithm(text) == 8)
        printf("Grade 8");
    else if (ColemanLiau_Algorithm(text) == 9)
        printf("Grade 9");
    else if (ColemanLiau_Algorithm(text) == 10)
        printf("Grade 10");
    else if (ColemanLiau_Algorithm(text) >= 16)
        printf("Grade 16+");
    else
        printf("Invalid Input!");

    printf("\n");
}

int letters(string a)
{
    int count = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(a[i]))
            count++;
    }

    return count;
}

int sentences(string a)
{
    int len = strlen(a);
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == '!' || a[i] == '.' || a[i] == '?')
            count++;
    }

    return count;
}

int words(string a)
{
    int len = strlen(a);
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] == 32)
            count++;
    }

    return count + 1;
}

double ColemanLiau_Algorithm(string a)
{
    double L = ((double) letters(a) / (double) words(a)) * 100;
    double S = ((double) sentences(a) / (double) words(a)) * 100;

    double algorithm = (0.0588 * L) - (0.296 * S) - 15.8;
    return round(algorithm);
}
