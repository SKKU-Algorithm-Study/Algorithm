# 컴백홈 : https://www.acmicpc.net/problem/1189
import sys
sys.setrecursionlimit(10 ** 6)
r, c, k = map(int, input().split())
field = [list(input()) for _ in range(r)]
dy = [-1, 0, 1, 0]  # 상 우 하 좌
dx = [0, 1, 0, -1]
ans = 0


def dfs(cur_y, cur_x, dist):
    global ans
    if cur_y == 0 and cur_x == c - 1:  # 종점 도달
        if dist == k:
            ans += 1  # 거리가 k와 일치
        return
    for i in range(4):
        next_y = dy[i] + cur_y
        next_x = dx[i] + cur_x
        if 0 <= next_y < r and 0 <= next_x < c and field[next_y][next_x] == '.':
            field[next_y][next_x] = 1  # set as visited
            dfs(next_y, next_x, dist + 1)
            field[next_y][next_x] = '.'


field[r - 1][0] = 1
dfs(r - 1, 0, 1)
print(ans)
