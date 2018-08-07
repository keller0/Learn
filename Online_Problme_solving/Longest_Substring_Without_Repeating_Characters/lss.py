#!/usr/bin/python
def lengthOfLongestSubstring(s):
    if len(s) == 0:
        return 0
    mc = 1
    for i in range(len(s)):
        t = {s[i]}
        count = 1
        for cc in s[i+1:]:
            if cc not in t:
                count+=1
                mc = max(mc, count)
                t.add(cc)
            else:
                count = 1
                break

    return mc

test = {"asjrgapa", " ", "1564asdq5324"}
for case in test:
    print(lengthOfLongestSubstring(case), case)
