a = int(input())
nums = [int(c) for c in input().split()]
idx = nums.index(-1)
ret = [0]*a
ret[0] = idx + 1
right = {}
person_idx = {}
person_idx[ret[0]]  = 0
for i, num in enumerate(nums, 1):
    right[num] = i

curr = ret[0]
while curr in right:
    idx = person_idx[curr]
    right_person = right[curr]
    person_idx[right_person] = idx + 1
    curr = right_person
for person, loc in person_idx.items():
    ret[loc] = person
print(" ".join(str(r) for r in ret))
