class A:
    def __init__(self):
        super().__init__()
        self.foo = "foo"
        self.name = "class A"


class B:
    def __init__(self):
        super().__init__()
        self.bar = "bar"
        self.name = "class B"


class C(A, B):
    def __init__(self):
        super().__init__()

    def print(self):
        print(self.bar)
        print(self.foo)
        print(self.name)
        


c = C()
c.print()
