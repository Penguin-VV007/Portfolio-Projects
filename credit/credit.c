#include<stdio.h>
#include<cs50.h>

int card_length( long long cno);
bool check_validity (int len);
bool luhns_algorithm (long cr_no);

int main (void)
{
    int i = 0;
   long long credit_no;
    do{
    credit_no = get_long_long("Number: ");
        if (credit_no > 0)
        i=1;
    } while (i == 0);

    if (luhns_algorithm (credit_no) && (card_length (credit_no) == 15) && ((credit_no / 10000000000000 == 34) || (credit_no / 10000000000000 == 37)))
    printf("AMEX\n");
    else if (luhns_algorithm (credit_no) && (card_length (credit_no) == 13) && (credit_no / 1000000000000 == 4))
    printf("VISA\n");
    else if (luhns_algorithm (credit_no) && (card_length (credit_no) == 16) && ((credit_no / 100000000000000 > 50) && (credit_no / 100000000000000 < 56)))
    printf("MASTERCARD\n");
    else if (luhns_algorithm (credit_no) && (card_length (credit_no) == 16) && (credit_no / 1000000000000000 == 4))
    printf("VISA\n");
    else
    printf ("INVALID\n");
}

int card_length (long long cno)
    {
    int len = 0;
    for (len = 0; cno != 0; cno /= 10)
    len++;
    return len;
    }

bool luhns_algorithm (long cr_no)
    {
    int sum = 0;
    for (int i = 0; cr_no != 0; i++)
    {
        if (i % 2 ==0)
        sum = sum + (cr_no % 10);
        else
        {
            int digit_seperator = 2 * (cr_no % 10);
            sum = sum + ((digit_seperator / 10) + (digit_seperator % 10));
        }
        cr_no = cr_no / 10;
    }
    if (sum % 10 == 0)
    return true;
    else
    return false;
    }
