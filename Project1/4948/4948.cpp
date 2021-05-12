//https://www.acmicpc.net/problem/4948
//¹ßÇ¥

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//bool isPrime(int n) {
//    if (n <= 1) {
//        return false;
//    }
//    for (int i = 2; i <= sqrt(n); i++) {
//        if ((n % i) == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//int main() {
//    ios::sync_with_stdio(false);
//    int n,N;
//    while (true) {
//        
//        cin >> n;
//        int count = 0;
//        N = 2 * n;
//        if (n == 0) {
//            break;
//        }else {
//            while (n+1 <= N) {
//                if (isPrime(n+1)) {
//                    count++;
//                }
//                n++;
//            }
//            cout << count << "\/";
//        }
//
//    }
//    
//}

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, root, M, N, cnt;
    while (1) {
        cin >> n;
        if (!n)
            break;

        M = n + 1;
        N = n * 2;
        cnt = 0;

        for (int i = M; i <= N; i++) {
            root = sqrt(i);
            if (root == 1 && i != 1) {
                cnt++;
                continue;
            }
            if (i % 2) {
                for (int j = 2; j <= root; j++) {
                    if (i % j==0)
                        break;
                    if (j == root) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}