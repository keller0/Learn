def threeSum(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    if len(nums) < 3:
        return []
    nums.sort()
    ans = set()
    for i, v in enumerate(nums[:-2]):
            if i >= 1 and v == nums[i-1]:
                continue
            d = {}
            for x in nums[i+1:]:
                if x not in d:
                    d[-v-x] = 1
                else:
                    ans.add((v, -v-x, x))
    return list(ans)

print(threeSum([1,2,3,4,5,6,-3]))
print(threeSum([-1,0,1,2,-1,-4]))