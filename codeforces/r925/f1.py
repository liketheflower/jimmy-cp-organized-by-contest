import collections
def solve(C, R):
    nums = []
    for i in range(R):
        nums.append([int(c) for c in input().split()])
    graph = [[] for _ in range(C + 1)]
    for row in nums:
        for j in range(1, C - 1):
            graph[row[j]].append(row[j+1])
    def check():
        ret = []
        indegree = [0]*(C+1)
        for i in range(1, C+1):
            for v in graph[i]:
                indegree[v] += 1
        zero_indegree = [i for i in range(1, C+1) if indegree[i] == 0]
        ret += zero_indegree[:]
        for i in zero_indegree:
            for j in graph[i]:
                indegree[j] -= 1
                if indegree[j] == 0:
                    ret.append(j)
                    zero_indegree.append(j)
        return len(ret) == C
    return check()

    




T = int(input())
while T:
    C, R = [int(c) for c in input().split()]
    ret = solve(C, R)
    print("YES" if ret else "NO")
    T -= 1

