class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        beginSet = set([beginWord])
        endSet = set([endWord])
        visited = set([beginWord, endWord])
        step = 1
        letters = 'abcdefghijklmnopqrstuvwxyz'

        while beginSet and endSet:
            if len(beginSet) > len(endSet):
                beginSet, endSet = endSet, beginSet

            nextSet = set()
            step += 1

            for word in beginSet:
                for i in range(len(word)):
                    for ch in letters:
                        newWord = word[:i] + ch + word[i + 1:]

                        if newWord in endSet:
                            return step

                        if newWord in wordSet and newWord not in visited:
                            visited.add(newWord)
                            nextSet.add(newWord)

            beginSet = nextSet

        return 0
