//https://www.acmicpc.net/problem/10845
//��ǥ

#include <iostream>
using namespace std;

struct Queue {
    int data[10000];
    int begin, end;
    
    Queue() {
        begin = 0;
        end = 0;
    }

    void push(int num)
    {
        data[end] = num;
        end += 1;
    }

    int pop()
    {
        if (empty())
            return -1;
        else
        {
            begin += 1;
            return data[begin - 1];
        }
    }

    int size()
    {
        return end - begin;
    }

    bool empty()
    {
        return (size() == 0) ? 1 : 0;
    }

    int front()
    {
        if (empty())
            return -1;
        else
            return data[begin];
    }

    int back()
    {
        if (empty())
            return -1;
        else
            return data[end - 1];
    }
};

int main(void)
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    Queue q;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        }

        else if (cmd == "pop")
        {
            cout << q.pop() << endl;
        }

        else if (cmd == "size")
        {
            cout << q.size() << endl;
        }

        else if (cmd == "empty")
        {
            cout << q.empty() << endl;
        }

        else if (cmd == "front")
        {
            cout << q.front() << endl;
        }

        else if (cmd == "back")
        {
            cout << q.back() << endl;
        }
    }
}