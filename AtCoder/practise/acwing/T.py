def add(a, b):return a + b


class O():
    def __init__(self):
        pass
    def add(self, a, b):
        return add(a, b)


e = O()
print(e.add(4, 5))
