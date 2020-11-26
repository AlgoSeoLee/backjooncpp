#include <iostream>
#include <cmath>
using namespace std;

int t, sx, sy, ex, ey;

//(sx,sy)가 (x,y,r)에 둘러 쌓여 있다면 true, 아니면 false
bool checkPoint(int x, int sx, int y, int sy, int r) {
    if (pow((x - sx), 2) + pow((y - sy), 2) < pow(r, 2)) {
        return true;
    }
    return false;
}

int main() {
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> sx >> sy >> ex >> ey;
        int n, x, y, r, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            if (checkPoint(x, sx, y, sy, r) && checkPoint(x, ex, y, ey, r)) {
                continue;
            }
            else if (checkPoint(x, sx, y, sy, r)) {
                cnt++;
            }
            else if (checkPoint(x, ex, y, ey, r)) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}