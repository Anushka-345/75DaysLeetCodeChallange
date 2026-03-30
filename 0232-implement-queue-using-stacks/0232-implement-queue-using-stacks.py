class MyQueue(object):

    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack_in.append(x)

    def pop(self):
        """
        :rtype: int
        """
        self.prepare_out()
        return self.stack_out.pop()

    def peek(self):
        """
        :rtype: int
        """
        self.prepare_out()
        return self.stack_out[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.stack_in and not self.stack_out

    def prepare_out(self):
        """
        Helper to transfer elements only when stack_out is empty.
        """
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())