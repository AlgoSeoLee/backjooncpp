//https://www.acmicpc.net/problem/17387
//��ǥ

#include <iostream>

using namespace std;
typedef long long LL;

struct coordinate {
    LL x;
    LL y;

    void read() { cin >> x >> y; }
};

// A---B---C ������� �� ������ ������ �Ǿ� �ִ��� Ȯ���ϴ� �Լ�
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
    // temp �� ���� ������ ������ ���� : ���� �������� Overflow�� �߻��� �� �����Ƿ�
    LL temp = (A.x * B.y) + (B.x * C.y) + (C.x * A.y);
    temp -= (A.x * C.y) + (B.x * A.y) + (C.x * B.y);

    // CCW�� ���� �������, 0 ����, ���������� �˸� �ǹǷ� �Ʒ��� ���� return �� �Ͽ���.
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
    int ans1 = CCW(A, B, C) * CCW(A, B, D); // ����AB�� �������� �� C, �� D �� üũ�ϴ� �κ�
    int ans2 = CCW(C, D, A) * CCW(C, D, B); // ����CD�� �������� �� A, �� B �� üũ�ϴ� �κ�

    if (!ans1 && !ans2) {    // �� ���� ��� ���� �� �� ���� ��
                            // A--B �� �Ÿ����� A--C, A--D�� �Ÿ��� �� �ְų�
                            // B--A �� �Ÿ����� B--C, B--D�� �Ÿ��� �� �ָ� ������ ���� ����̹Ƿ� false�� return
        if ((isLined(A, B, C) && isLined(A, B, D)) || (isLined(B, A, C) && isLined(B, A, D))) {
            return false;
        }
        else 
            return true;    // �׷��� ���� ���� ��ġ�� �κ��� �����ϴ� ����̹Ƿ� true�� return
    }
    else 
        return (ans1 <= 0) && (ans2 <= 0); // ������ ������ �� ���ǿ� �����ϸ� 1, �������� ������ 0�� return
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