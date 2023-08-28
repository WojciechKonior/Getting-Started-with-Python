from dataclasses import dataclass, field
import random

def price_func():
    return float(random.randrange(20,40))

@dataclass(frozen=True)
class Book:
    title: str = "no title"
    author: str = "no author"
    pages: int = 0
    price: float = field(default_factory=price_func)

    def __str__(self):
        return f'The book "{self.title}" by {self.author} has {self.pages} pages and costs {self.price}'

    def __post_init__(self):
        self.description = f'The book "{self.title}" by {self.author} has {self.pages} pages and costs {self.price}'


b1 = Book("Faraon", "Prus", 300, 30.0)
print(str(b1))
