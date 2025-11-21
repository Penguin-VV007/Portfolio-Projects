#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string caesar_algorithm(string a, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = 0;
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]))
            key = key * 10 + argv[1][i] - 48;
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: %s\n", caesar_algorithm(plaintext, key));
}

string caesar_algorithm(string a, int k)
{
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (isupper(a[i]))
            a[i] = (((a[i] - 65) + k) % 26) + 65;
        else if (islower(a[i]))
            a[i] = (((a[i] - 97) + k) % 26) + 97;
    }

    return a;
}
