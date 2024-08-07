#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> maze;
vector<vector<bool>> visited;

int R, C, K;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int result = 0;

// start: (R-1, 0) end: (0, C-1)
void DFS(int x, int y, int dist) {
    
  if (x == 0 && y == C - 1) {
    if (dist == K) {
      result++;
    }
    return;
  }

  visited[x][y] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= R || ny < 0 || ny >= C || maze[nx][ny] == 'T' || visited[nx][ny])
      continue;

    DFS(nx, ny, dist + 1);
  }

  visited[x][y] = false;
}

int main() {
  cin >> R >> C >> K;

  maze.resize(R, vector<char>(C));
  visited.resize(R, vector<bool>(C, false));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> maze[i][j];
    }
  }

  DFS(R - 1, 0, 1);

  cout << result << endl;
}
