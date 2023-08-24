class Book:
  BOOK_TYPES = ("HARDCOVER", "PAPERBACK", "EBOOK")
  __booklist = None

  @staticmethod
  def getbooklist():
    if Book.__booklist == None:
      Book.__booklist = []
    return Book.__booklist

  @classmethod
  def getbooktypes(cls):
    return cls.BOOK_TYPES
  
  def __init__(self, title author, pages, price, booktype):
    self.title = title
    self.pages = pages
    self.author = author
    self.price = price
    self.__secret = "secret"
    if(not booktype in Book.BOOK_TYPES):
      raise ValueError(f"{booktype} is not a valid book type")
    else:
      self.booktype = booktype

  def getprice(self):
    if hasattr(self, "_discount"):
      return self.price - (self.price * self._discount)
    else:
      return self.price

  def setdiscount(self, amount):
    self._discount = amount

  def setTitle(self, newtitle):
    self.title = newtitle

class Newspaper:
  def __init__(self, name):
    self.name = name

b1 = Book("Trylogia", "Siekniewicz", 1000, 40.99, "HARDCOVER")
b2 = Book("Quo Vadis", "Sienkiewicz", 400, 50.99, "PAPERBACK")
n1 = Newspaper("Newsweek")

print(b1)
print(b1.title)
print(b1.getprice())
b1.setdiscount(10)
print(b1.getprice())
print(b2._Book__secret)

print("Book types: ", Book.getbooktypes())

print(type(b1))
print(type(n1))
print(type(b1)==type(b2))
print(type(b1)==type(n1))

print(isinstance(b1, Book))
print(isinstance(n1, Newspaper))
print(isinstance(n1, Book))
print(isinstance(n1, object))

thebooks = Book.getbooklist()
thebooks.append(b1)
thebooks.append(b2)
