dirs = [(0, 1),(0, -1),(1, 0),(-1, 0)]
def solve():
    n = int(input())
    seen = [[False]*210 for _ in range(210)]
    for _ in range(n):
        x, y = [int(c) for c in input().split()]
        seen[x+100][y+100] = True
    def bfs(i, j):
        if visited[i][j]:
            return 
        curr = [(i, j)]
        found = seen[i][j]
        while curr:
            #print(open_list)
            next_level = []
            for i, j in curr:
                for di, dj in dirs_:
                    r, c = i + di, j + dj
                    if r < 0 or c < 0 or r > 201 or c > 201 or visited[r][c]:
                        continue
                    visited[r][c] = True
                    if seen[r][c]:
                        found += 1
                        if found == n:
                            return True
                    next_level.append((r, c))
            curr = next_level
        return False
    for not_use_idx in range(4):
        dirs_ = dirs[:not_use_idx] + dirs[not_use_idx + 1:]
        visited = [[False]*210 for _ in range(210)]
        if bfs(100, 100):
            return True
    return False





T = int(input())
for i in range(T):
    ret = solve()
    print("YES" if ret else "NO")
