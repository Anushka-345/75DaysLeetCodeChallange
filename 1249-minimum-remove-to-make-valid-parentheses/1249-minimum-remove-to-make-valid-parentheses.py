class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Convert string to list because strings are immutable in Python
        s_list = list(s)
        stack = [] # Stores indices of '('
        
        for i, char in enumerate(s_list):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    # Found a match, remove the index from the stack
                    stack.pop()
                else:
                    # No matching '(', mark this ')' for removal
                    s_list[i] = ""
        
        # Any indices left in the stack are '(' without a matching ')'
        while stack:
            s_list[stack.pop()] = ""
            
        return "".join(s_list)