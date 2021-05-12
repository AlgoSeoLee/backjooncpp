//https://www.acmicpc.net/problem/11653
//¹ßÇ¥

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n/2;)
    {
        if (n % i == 0)
        {
            cout << i << '\n';
            n /= i;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
