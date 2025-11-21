from cs50 import get_string
from math import floor


def main():
    card_no = get_string("Card No.: ")
    if luhns_algorithm(card_no) == True and len(card_no) == 15 and card_no[0] == "3" and (card_no[1] == "4" or card_no[1] == "7"):
        print(f"AMEX")
    elif luhns_algorithm(card_no) == True and (len(card_no) == 13 or len(card_no) == 16) and (card_no[0] == "4"):
        print(f"VISA")
    elif luhns_algorithm(card_no) == True and len(card_no) == 16 and (card_no[0] == "5") and (card_no[1] == "1" or card_no[1] == "2" or card_no[1] == "3" or card_no[1] == "4" or card_no[1] == "5"):
        print(f"MASTERCARD")
    else:
        print(f"INVALID")


def luhns_algorithm(cno):
    sum = 0
    digisep = 0
    for i in range(len(cno)-2, -1, -2):
        sum = sum + floor(((int(cno[i]) * 2) / 10)) + ((int(cno[i]) * 2) % 10)
    for i in range(len(cno)-1, -1, -2):
        sum = sum + int(cno[i])

    if sum % 10 == 0:
        return True
    else:
        return False


main()
