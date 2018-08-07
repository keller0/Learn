#!/usr/bin/python

def findMedianSortedArrays(nums1, nums2):
    all = nums1 + nums2
    all.sort()
    l = len(all)
    if l%2:
        return all[int(l/2)]
    else:
        return (all[int(l/2)]+all[int(l/2-1)])/2


a1 = [1,2,3,4]
a2 = [5,6,7,8]
a3 = [2,3]
a4 = [5]
print(findMedianSortedArrays(a1, a2))
print(findMedianSortedArrays(a1, a3))
print(findMedianSortedArrays(a1, a4))