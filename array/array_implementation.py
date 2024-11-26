class MyArray:
    def __init__(self, capacity):
        self.arr = []
        self.capacity = capacity

    
    def append(self, value):
        self.arr.append(value)

    
    def appendArray(self, list):
        for i in list:
            self.arr.append(i)


    def insert(self, index, value):
        i = len(self.arr)

        self.arr.append(None)
        while (i >= index):
            self.arr[i+1] = self.arr[i]
            i -= 1

        self.arr[index] = value


    def remove(self, index):
        i = index
        self.arr.append(None)
        while (i < len(self.arr)):
            self.arr[i] = self.arr[i+1]
            i += 1

    def iterate(self):
        print(self.arr)


if __name__ == "__main__":
    arrayTest = MyArray(10)
    arrayTest.appendArray([20,10,20,32,1,4,5,2,3,3,21])
    arrayTest.iterate()
    arrayTest.remove(1)
    arrayTest.iterate()

        