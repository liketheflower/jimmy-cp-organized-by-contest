
import heapq
n = int(input())
nums = []
INF = float("inf")
rets = [INF]*(n + 10)
rets[1] = 0
q = [(0, 1)]
heapq.heapify(q)
nums = []
for i in range(n-1):
    a, b, x = [int(c) for c in input().split()]
    # choose a
    nums.append((a, b ,x))
    """
    idx = i + 1
    rets[idx+1] = min(rets[idx+1], rets[idx] + a)
    # choose b
    rets[x] = min(rets[x], rets[idx] + b)
    """
while q:
    cost, idx = heapq.heappop(q)
    #print(cost, idx)
    if idx  < n:
        a, b, x = nums[idx-1]
        new_cost1 = cost + a
        new_cost2 = cost + b
        i1, i2 = idx + 1, x
        if rets[i1] > new_cost1:
            rets[i1] = new_cost1
            heapq.heappush(q, (new_cost1, i1))
        if rets[i2] > new_cost2:
            rets[i2] = new_cost2
            heapq.heappush(q, (new_cost2, i2))
    else:
        break
print(rets[n])
