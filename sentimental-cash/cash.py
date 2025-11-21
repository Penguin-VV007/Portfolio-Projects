from cs50 import get_float

while True:
    change = round((get_float("Change Owed: ")) * 100)
    if change >= 0:
        break

count = 0

for i in {25, 10, 5, 1}:
    while change >= i:
        change = change - i
        count += 1
print(f"{count}")
