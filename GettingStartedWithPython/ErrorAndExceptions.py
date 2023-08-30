def causeError():
    return 1/0

def callCauseError():
    return causeError()

# print(callCauseError())
try:
    callCauseError()
except Exception as e:
    print(type(e))
