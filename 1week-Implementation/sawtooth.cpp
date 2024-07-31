#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int> &gear, int direction) {
  vector<int> newGear(8);
  if (direction == 1) { // 시계 방향
    for (int i = 0; i < 8; ++i) {
      newGear[i] = gear[(i + 7) % 8];
    }
  } else { // 반시계 방향
    for (int i = 0; i < 8; ++i) {
      newGear[i] = gear[(i + 1) % 8];
    }
  }
  return newGear;
}

void rotateGears(vector<vector<int>> &gears, int gearNum, int direction) {
  vector<int> directions(4, 0);
  directions[gearNum] = direction;

  // 왼쪽 톱니바퀴 확인
  for (int i = gearNum; i > 0; --i) {
    if (gears[i][6] != gears[i - 1][2]) {
      directions[i - 1] = -directions[i];
    } else {
      break;
    }
  }

  // 오른쪽 톱니바퀴 확인
  for (int i = gearNum; i < 3; ++i) {
    if (gears[i][2] != gears[i + 1][6]) {
      directions[i + 1] = -directions[i];
    } else {
      break;
    }
  }

  // 모든 톱니바퀴 회전
  for (int i = 0; i < 4; ++i) {
    if (directions[i] != 0) {
      gears[i] = rotate(gears[i], directions[i]);
    }
  }
}

int main() {
  vector<vector<int>> gears(4, vector<int>(8));
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 8; ++j) {
      char c;
      cin >> c;
      gears[i][j] = c - '0';
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int gearNum, direction;
    cin >> gearNum >> direction;
    rotateGears(gears, gearNum - 1, direction);
  }

  int result = 0;
  if (gears[0][0] == 1)
    result += 1;
  if (gears[1][0] == 1)
    result += 2;
  if (gears[2][0] == 1)
    result += 4;
  if (gears[3][0] == 1)
    result += 8;

  cout << result << endl;
  return 0;
}
