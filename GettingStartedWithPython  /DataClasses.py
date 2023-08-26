from dataclasses import dataclass

@dataclass
class Book:
    title: str = "no title"
    author: str = "no author"
    pages: int = 0
    price: float = 0.0

    def __str__(self):
        return f'The book "{self.title}" by {self.author} has {self.pages} pages and costs {self.price}'


b1 = Book("Faraon", "Prus", 300, 30.0)
print(str(b1))
