def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]+nums[j] == target:
                return [i, j]

def twoSum2(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    m = {}
    for i in range(len(nums)):
        t = target - nums[i]
        if t in m:
            return [m[t], i]
        else:
            m[nums[i]] = i

print(twoSum([3,2,4], 6))
print(twoSum2([4, 2, 3, 5, 10], 15))