import time

def causeError():
    return 1/0

def callCauseError():
    return causeError()

# print(callCauseError())
try:
    callCauseError()
except Exception as e:
    print(type(e))


def handleException(func):
    def wrapper(*args):
        start_time = time.time()

        try:
            time.sleep(0.5)
            print(args)
            func(*args)
        except ZeroDivisionError:
            print("there was a zero-division error")
        except TypeError:
            print("there was a type error")
        except Exception as e:
            print(f"there is one exception {e}")
        finally:
            print(f"the try block tooks {time.time() - start_time} seconds")
    return wrapper

@handleException
def divide(a, b):
    print(a, b)
    return a/b


a = divide(10, 20)

print(a)


@handleException
def raiseSomeError(n):
    raise Exception(n)

raiseSomeError(1)