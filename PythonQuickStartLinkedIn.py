import math
import random

def sum(a, b):
    return a + b

def max(a, b):
    if a>b: return a
    elif b>a: return b
    else: return b

def print_some(pStr = "Wojtek"):
    print(pStr)

class Person():
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def print(self):
        print(f"{self.name}, {self.age}")

if __name__ == '__main__':
    wojtek = Person("Wojtek Konir", 32)
    wojtek.print();
    a = int(10)
    c = bool(True)
    b = str("Hello")
    d = float(10.3)
    print(f"{b} Wojtek {a} {c} {d}")
    print(type(a), type(b), type(c), type(d))
    print(sum(10, 20))
    # dd = input("Podaj liczbe: ")
    # print(dd)
    print(str(max(10, 20)) + "wojtek")
    print_some()
    print_some("wojtek")
    print(math.sqrt(4))
    print(random.random())
    print(random.randint(1, 10))

    f = [1, 3, 2, 1, 5, 7]
    g = ("wotek", "konior", "monika")
    print(random.choice(g))
    print(random.choice(f))
    h = ("wojtek", 1, 3, 'a')

    if (h[0]=="wojtek"): print("hahaha")

    for i in range(1,10):
        print(i)

    for i in range(1, 100, 10):
        print(i)

    for i in ["wojtek ", "konior"]:
        print(i)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
