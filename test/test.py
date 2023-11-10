import random

# random BookData
def generate_random_line():
    book_title = " ".join([chr(random.randint(97, 122)) + chr(random.randint(97, 122))
                           + chr(random.randint(97, 122)) + chr(random.randint(97, 122)) for _ in range(random.randint(1, 2))])
    category = str(random.choice([0, 100, 200, 300, 400, 500, 600, 700]))
    author = " ".join([chr(random.randint(65, 90)) + chr(random.randint(97, 122)) for _ in range(random.randint(1, 3))])
    publish_year = str(random.randint(1900, 2400))
    random_number = str(random.randint(0, 1))

    return f"{book_title}\t{category}\t{author}\t{publish_year}\t{random_number}\r\n"

# write in text file
with open("loan_book.txt", "w") as file:
    for _ in range(100):
        file.write(generate_random_line())