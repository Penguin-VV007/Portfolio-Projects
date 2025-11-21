from cs50 import get_int

while True:
    height = get_int("Height: ")
    if (height < 9 and height > 0):
        break

for _ in range(1, height + 1):
    print(" " * (height - _), end="")
    print("#" * _, end="")
    print("  ", end="")
    print("#" * _)
