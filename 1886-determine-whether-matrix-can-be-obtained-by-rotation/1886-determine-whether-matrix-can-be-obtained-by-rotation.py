class Solution(object):
    def rotate(self, mat):
        """Rotate the matrix 90 degrees clockwise in-place and return it"""
        n = len(mat)
        # Transpose
        for i in range(n):
            for j in range(i+1, n):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        # Reverse each row
        for i in range(n):
            mat[i].reverse()
        return mat

    def findRotation(self, mat, target):
        """
        :type mat: List[List[int]]
        :type target: List[List[int]]
        :rtype: bool
        """
        for _ in range(4):  # Check 0°, 90°, 180°, 270°
            if mat == target:
                return True
            mat = self.rotate(mat)
        return False