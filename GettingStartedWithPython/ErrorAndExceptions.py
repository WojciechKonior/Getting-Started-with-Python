def causeError():
    return 1/0

def callCauseError():
    return causeError()

callCauseError()

