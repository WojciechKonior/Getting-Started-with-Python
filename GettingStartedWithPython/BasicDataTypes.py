a = int(10.55)
b = float(10.65)
print(a, round(b))

# casting from hex bin and oct
c = int('101', 2)
d = int('ff', 16)
e = int('77', 8)

print(c, d, e)

# decimal module
print(1.2 - 1.0)
from decimal import Decimal, getcontext

print(getcontext())
getcontext().prec = 2
print(getcontext())
print(Decimal(Decimal(1.2) - Decimal(1.0)))

# bool
print(bool(0), bool(1), bool(0.0), bool(-1.0), bool(0j), bool(1j))
print(bool("True"), bool("False"), bool(""), bool([]), bool({}), bool(()), bool(None))

s = "Wojciech Konior"
print(s[8:])
print(s[2:8])
print(s[-8:])

import math
print(f"{math.pi:.6f}")
print("Pi is {}".format(math.pi))

print(bin(231))
print(bytes(231))
print(bytes('443', 'utf-8').decode('utf-8'))