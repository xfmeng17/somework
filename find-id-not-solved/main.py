"""
Windows script
1. Read file names from ~~/leetcode/c++/*,
put id=123 from name like 123_xxx.cpp into idArr.
2. Read id from dplist.txt (stores all dp problmes)
and id from dplocked.txt (stores id of problems that
locked).
3. Output diff ids that I should rewrite those problem
with c++
"""

import os

files = os.listdir('D:\git\leetcode\c++')
idSolvedList = []
for name in files:
    arr = name.split('_')
    if len(arr) >= 2:
        idSolvedList.append(arr[0])
# print(idArr)

idList = []
with open('dplist.txt', 'r') as f:
    for line in f:
        arr = line.split()
        if len(arr) <= 1:
            idList.append(arr[0])
# print(idList)
idSolvedSet = set(idSolvedList)

idLocked = []
with open('dplocked.txt', 'r') as f:
    for line in f:
        idLocked.append(line.strip())
#print(idLocked)
idLockedSet = set(idLocked)

idDiff = []
for id in idList:
    if (not id in idSolvedSet) and (not id in idLockedSet):
        idDiff.append(id)
print(idDiff)

with open('dpdiff.txt', 'w') as f:
    for x in idDiff:
        f.write("%s\n" % x)
