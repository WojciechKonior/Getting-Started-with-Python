class Publication:
    def __init__(this, title, price):
        this.title = title
        this.price = price
        pass
    pass

class Periodical(Publication):
    def __init__(this, title, price, period, publisher):
        super().__init__(title, price)
        this.period = period
        this.publisher = publisher

class Book(Publication):
    def __init__(this, title, author, pages, price):
        super().__init__(title, price)
        this.author = author
        this.pages = pages
        pass
    pass

class Magazine(Periodical):
    def __init__(this, title, publisher, price, period):
        super().__init__(title, price, period, publisher)
        pass
    pass

class Newspaper(Periodical):
    def __init__(this, title, publisher, price, period):
        super().__init__(title, price, period, publisher)
        pass
    pass


b1 = Book("Brave New World", "Aldous Huxley", 311, 29.0)
n1 = Newspaper("NY Times", "New York Times Company", 6.0, "Daily")
m1 = Magazine("Scientific American", "Springer Nature", 5.99, "Monthly")

print(b1.author)
print(n1.publisher)
print(b1.price, m1.price, n1.price)
