class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = sorted(candidates)
        ans = []
        def dfs(stack, rem):
            if rem == 0 :
                ans.append(stack)
                return

            for item in candidates:
                if item > rem: break
                if stack and item < stack[-1]: continue
                else:
                    dfs(stack+[item], rem-item)

        dfs([], target)
        return ans


s = Solution()

print(s.combinationSum([2,3,9,6,7], 8))