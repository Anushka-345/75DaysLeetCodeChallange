class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        x = 0  # horizontal position
        y = 0  # vertical position

        for move in moves:
            if move == 'R':
                x += 1
            elif move == 'L':
                x -= 1
            elif move == 'U':
                y += 1
            elif move == 'D':
                y -= 1

        # Robot is back at origin if x and y are both 0
        return x == 0 and y == 0