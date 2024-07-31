/*
2week-트리의 부모 찾기
*/

#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> tree(100001);
int parent[100001];
bool visited[100001];

void dfs(int v) {
  visited[v] = 1;

  for (int i = 0; i < tree[v].size(); i++) {
    int x = tree[v][i];
    if (visited[x] == 0) {
      parent[x] = v;
      dfs(x);
    }
  }
}

int main() {

  cin >> N;
  parent[1] = 1; //트리의 루트

  for (int i = 1; i < N; i++) {
    int node1, node2;
    cin >> node1 >> node2;
    tree[node1].push_back(node2);
    tree[node2].push_back(node1);
  }

  for (int i = 1; i < N; i++) {
    dfs(i);
  }

  for (int i = 2; i <= N; i++) {
    cout << parent[i] << "\n";
  }
}