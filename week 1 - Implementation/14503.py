# 로봇청소기 : https://www.acmicpc.net/problem/14503
import sys
sys.setrecursionlimit(10**8)

n, m = map(int, input().split())
r, c, d = map(int, input().split())
room = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
answer = 0

for _ in range(n):
    room.append(list(map(int, input().split())))


def clean(y, x, dir):
    global answer
    while True:
        if room[y][x] == 0:  # 청소 x
            room[y][x] = 2
            answer += 1
        isclean = False
        for i in range(4):
            ndir = (dir + 3) % 4
            ny = y + dy[ndir]
            nx = x + dx[ndir]
            if 0 <= ny < n and 0 <= nx < m and room[ny][nx] == 0: #그 칸으로 이동
                isclean = True
                y, x, dir = ny, nx, ndir
                break
            dir = ndir
        if not isclean:
            ny = y - dy[dir]
            nx = x - dx[dir]
            if ny < 0 or ny >= n or nx < 0 or nx >= m or room[ny][nx] == 1:  # 벽 만났을 때:
                print(answer)
                return
            y, x = ny, nx

clean(r, c, d)
print(room)