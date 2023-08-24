class Book:
  def __init__(self, title author, pages, price):
    self.title = title
    self.pages = pages
    self.author = author
    self.price = price
    self.__secret = "secret"

  def getprice(self):
    if hasattr(self, "_discount"):
      return self.price - (self.price * self._discount)
    else:
      return self.price

  def setdiscount(self, amount):
    self._discount = amount

b1 = Book("Trylogia", "Siekniewicz", 1000, 40.99)
b2 = Book("Quo Vadis", "Sienkiewicz", 400, 50.99)

print(b1)
print(b1.title)
print(b1.getprice())
b1.setdiscount(10)
print(b1.getprice())
print(b2._Book__secret)
