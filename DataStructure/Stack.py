class Stack:
    def __init__(self, max=-1):
        self.max=max
        self.stk = list()
        self.ptr=0

    def Push(self, x):
        if self.max!=-1 or self.ptr<max:
            self.stk.append(x)
            self.ptr+=1
            return 0
        print("Stack Over Flow")
        return -1

    def Pop(self):
        if self.ptr>0:
            return self.stk.pop()
            self.ptr-=1
        print("Under Flow")
        return None

    def Peek(self):
        if self.ptr>0:
            return self.stk[-1]
        print("Stack is Empty")
        return None

    def Clear(self):
        self.stk = list()

    def Capacity(self):
        if self.max == -1:
            return float("inf")
        return self.max

    def Size(self):
        return self.ptr

    def IsEmpty(self):
        return self.ptr==0

    def IsFull(self):
        return self.max!=-1 and self.ptr>=self.max

    def Search(self, x):
        try:
            return self.stk.index(x)
        except:
            return -1

    def Print(self):
        print(self.stk.reversed())

    def Terminate(self):
        self.max=None
        self.stk=None
