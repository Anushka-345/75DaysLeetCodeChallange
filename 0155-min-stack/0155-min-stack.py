class MinStack(object):

    def __init__(self):
        # The main stack to store all elements
        self.stack = []
        # The stack to keep track of the minimums
        self.min_stack = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        self.stack.append(val)
        
        # If min_stack is empty, or the new val is <= current min, 
        # push it onto min_stack.
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        """
        :rtype: None
        """
        # If the value being popped is the current minimum, 
        # pop it from min_stack as well.
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_stack[-1]