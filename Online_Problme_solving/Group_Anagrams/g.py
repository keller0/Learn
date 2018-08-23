class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for string in sorted(strs):
            c = tuple(sorted(string))
            d[c] = d.get(c, []) + [string]
        
        return d.values()

s = Solution()
a = ["eat", "tea", "tan", "ate", "nat", "bat"]
print s.groupAnagrams(a)