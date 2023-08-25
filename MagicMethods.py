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


b1 = Book("Quo Vadis", "Sienkiewicz", 40.3)
b2 = Book("Faraon", "Prus", 40.3)

print(str(b1))
print(repr(b1))

print(b1==b2)
print(b1==40)

print(b1>b2)
