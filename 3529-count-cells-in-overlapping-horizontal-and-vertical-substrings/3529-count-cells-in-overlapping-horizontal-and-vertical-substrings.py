class Solution(object):
    def countCells(self, grid, pattern):
        """
        :type grid: List[List[str]]
        :type pattern: str
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        N = m * n
        L = len(pattern)

        def build_lps(p):
            lps = [0] * len(p)
            j = 0
            for i in range(1, len(p)):
                while j > 0 and p[i] != p[j]:
                    j = lps[j - 1]
                if p[i] == p[j]:
                    j += 1
                    lps[i] = j
            return lps

        def mark_matches(text):
            diff = [0] * (len(text) + 1)
            lps = build_lps(pattern)
            j = 0

            for i in range(len(text)):
                while j > 0 and text[i] != pattern[j]:
                    j = lps[j - 1]
                if text[i] == pattern[j]:
                    j += 1
                if j == L:
                    start = i - L + 1
                    diff[start] += 1
                    diff[start + L] -= 1
                    j = lps[j - 1]

            cover = [0] * len(text)
            cur = 0
            for i in range(len(text)):
                cur += diff[i]
                cover[i] = cur > 0
            return cover

        horizontal_text = []
        for i in range(m):
            for j in range(n):
                horizontal_text.append(grid[i][j])

        vertical_text = []
        for j in range(n):
            for i in range(m):
                vertical_text.append(grid[i][j])

        h_cover = mark_matches(horizontal_text)
        v_cover = mark_matches(vertical_text)

        ans = 0
        for i in range(m):
            for j in range(n):
                h_idx = i * n + j
                v_idx = j * m + i
                if h_cover[h_idx] and v_cover[v_idx]:
                    ans += 1

        return ans

