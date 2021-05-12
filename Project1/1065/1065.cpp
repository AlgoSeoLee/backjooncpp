#include <iostream>
using namespace std;

bool h(int x) {
    if (x < 100)
        return true;
    int a, b, c;
    a = x / 100;
    b = x % 100 / 10;
    c = x % 10;
    if (a - b == b - c){
        return true;
    }
    else
    {
        return false;
    }

}

int main(void) {
    int N, count = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (h(i))
            count++;
    }
    cout << count;
}