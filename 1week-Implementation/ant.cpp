#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h, p, q, t;
  int direction = 1;
  cin >> w >> h >> p >> q >> t;

  while (t > 0) {

    if (p == w && q < h) //현재위치: 오른쪽 벽
    {
      p = p - 1;
      q = q + 1;
      direction = 3;            // go left
    } else if (p > 0 && q == 0) //현재위치: 아래쪽 벽
    {
      p = p - 1;
      q = q + 1;
      direction = 3;             // go left
    } else if (p == 0 && q >= 0) //현재위치: 왼쪽 벽
    {
      p = p + 1;
      q = q + 1;
      direction = 1;            // go right
    } else if (p > 0 && q == h) //현재위치: 위쪽 벽
    {
      p = p - 1;
      q = q - 1;
      direction = 2; // down left
    }

    else {
      switch (direction) {
      case 1:
        p = p + 1;
        q = q + 1;
        break;
      case 2:
        p = p - 1;
        q = q - 1;
        break;
      case 3:
        p = p - 1;
        q = q + 1;
        break;
      }
    }

    t--;
  }
  cout << p << " " << q << "\n";
}
