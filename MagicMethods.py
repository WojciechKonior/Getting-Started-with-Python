class Book:
    def __init__(self, title, author, price):
        super().__init__()
        self.title = title
        self.author = author
        self.price = price

    def __str__(self):
        return f"The Book '{self.title}' by {self.author} consts {self.price}"

    def __repr__(self):
        return f"title={self.title}, author={self.author}, price={self.price}"

    def __eq__(self, book):
        if(not isinstance(book, Book)):
            raise ValueError(f"Cannot compare {type(self)} with {type(book)}")
        return (self.price == book.price and
                self.title == book.title and
                self.author == book.author)

    def __gt__(self, book):
        if not isinstance(book, Book):
            raise ValueError(f"cannot compare {type(self)} with {type(book)}")
        return self.price > book.price

    def __ge__(self, book):
        if not isinstance(book, Book):
            raise ValueError(f"cannot compare {type(self)} with {type(book)}")
        return self.price >= book.price

    def __lt__(self, book):
        if not isinstance(book, Book):
            raise ValueError(f"cannot compare {type(self)} with {type(book)}")
        return self.price < book.price

    def __le__(self, book):
        if not isinstance(book, Book):
            raise ValueError(f"cannot compare {type(self)} with {type(book)}")
        return self.price <= book.price


b1 = Book("Quo Vadis", "Sienkiewicz", 40.3)
b2 = Book("Faraon", "Prus", 4.3)
b3 = Book("Quo Vadis", "Sienkiewicz", 43.3)
b4 = Book("Faraon", "Prus", 45.3)
b5 = Book("Quo Vadis", "Sienkiewicz", 48.3)
b6 = Book("Faraon", "Prus", 30.3)

print(str(b1))
print(repr(b1))

books = [b1, b2, b3, b4, b5, b6]
books.sort()

print([book.title for book in books])

print(b1==b2)
print(b1==40)

print(b1>b2)
