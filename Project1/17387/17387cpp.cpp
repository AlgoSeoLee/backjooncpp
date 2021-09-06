//https://www.acmicpc.net/problem/17387
//발표

#include <iostream>

using namespace std;
typedef long long LL;

struct coordinate {
    LL x;
    LL y;

    void read() { cin >> x >> y; }
};

// A---B---C 순서대로 한 직선에 나열이 되어 있는지 확인하는 함수
bool isLined(coordinate A, coordinate B, coordinate C) {
    if (A.x < B.x) {
        return B.x < C.x;
    }
    else if (B.x < A.x) {
        return C.x < B.x;
    }
    else {
        if (A.y < B.y) {
            return B.y < C.y;
        }
        else if (B.y < A.y) {
            return C.y < B.y;
        }
    }
}

int CCW(coordinate A, coordinate B, coordinate C) {
    // temp 에 대한 연산을 나누는 이유 : 연산 과정에서 Overflow가 발생할 수 있으므로
    LL temp = (A.x * B.y) + (B.x * C.y) + (C.x * A.y);
    temp -= (A.x * C.y) + (B.x * A.y) + (C.x * B.y);

    // CCW의 값이 양수인지, 0 인지, 음수인지만 알면 되므로 아래와 같이 return 을 하였다.
    if (temp > 0) { 
        return 1; 
    }
    else if (!temp) {
        return 0;
    }
    else 
        return -1;
}

bool isOverlapped(coordinate A, coordinate B, coordinate C, coordinate D) {
    int ans1 = CCW(A, B, C) * CCW(A, B, D); // 선분AB를 기준으로 점 C, 점 D 를 체크하는 부분
    int ans2 = CCW(C, D, A) * CCW(C, D, B); // 선분CD를 기준으로 점 A, 점 B 를 체크하는 부분

    if (!ans1 && !ans2) {    // 네 점이 모두 같은 선 상에 있을 때
                            // A--B 의 거리보다 A--C, A--D의 거리가 더 멀거나
                            // B--A 의 거리보다 B--C, B--D의 거리가 더 멀면 교점이 없는 경우이므로 false를 return
        if ((isLined(A, B, C) && isLined(A, B, D)) || (isLined(B, A, C) && isLined(B, A, D))) {
            return false;
        }
        else 
            return true;    // 그렇지 않은 경우는 겹치는 부분이 존재하는 경우이므로 true를 return
    }
    else 
        return (ans1 <= 0) && (ans2 <= 0); // 위에서 설명이 된 조건에 부합하면 1, 부합하지 않으면 0을 return
}

int main() {
    coordinate A, B, C, D;

    A.read(); B.read();
    C.read(); D.read();

    if (isOverlapped(A, B, C, D)) {
        cout << "1";
    }
    else 
        cout << "0";
}