def someFunc5():
    x = 5
    x_ = id(x)
    someFunc4()
    pass


def someFunc4():
    x = 4
    x_ = id(x)
    someFunc3()
    pass


def someFunc3():
    x = 3
    x_ = id(x)
    someFunc2()
    pass


def someFunc2():
    x = 2
    x_ = id(x)
    someFunc1()
    pass


def someFunc1():
    x = 1
    x_ = id(x)
    someFunc0()
    pass


def someFunc0():
    x = 0
    x_ = id(x)
    pass


someFunc5()
