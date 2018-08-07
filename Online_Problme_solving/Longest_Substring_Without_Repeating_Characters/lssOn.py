#!/usr/bin/python
def lengthOfLongestSubstring(s):
    if len(s) == 0:
        return 0
    dic = {}
    max_count = 0
    start_i = 0
    for i, c in enumerate(s, 1):
        if (c in dic) and (dic[c] > start_i):
            start_i = dic[c]
        elif i - start_i > max_count:
            max_count = i - start_i
        dic[c] = i

    return max_count

test = {"asjrgapa", " ", "1564asdq5324"}
for case in test:
    print(lengthOfLongestSubstring(case), case)

