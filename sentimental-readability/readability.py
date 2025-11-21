from cs50 import get_string


def main():
    text = get_string("Text: ")
    if cl_index(text) < 1:
        print(f"Before Grade 1")
    if cl_index(text) >= 1 and cl_index(text) <= 10:
        print(f"Grade {cl_index(text)}")
    if cl_index(text) >= 16:
        print(f"Grade 16+")


def cl_index(text):
    letters = 0
    words = 0
    sentences = 0

    for i in range(len(text)):
        if text[i] == " ":
            words += 1
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            sentences += 1
        if text[i].isalpha():
            letters += 1

    words += 1
    L = (float(letters) / float(words)) * 100
    S = (float(sentences) / float(words)) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)


main()
