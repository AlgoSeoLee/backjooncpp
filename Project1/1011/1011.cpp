//https://www.acmicpc.net/problem/1011
//¹ßÇ¥

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int x, y;
        cin >> x >> y;
        long long i = 1;
        while (i * i <= (y - x)) {

            i++;
        }
        i--;
        long long count = (y - x) - (i * i);
        count = (long long)ceil((double)count / (double)i);
        cout << i * 2 - 1 + count << "\n";
    }
    return 0;
}