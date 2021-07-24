//https://www.acmicpc.net/problem/1476

#include <iostream>

using namespace std;

int E, S, M;

int calculateYear(void){
    //Year - E = 15*x
    //Year - S = 28*y
    //Year - M = 19*z
    int result;
    int year = 1;

    while (1){
        if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0){
            result = year;
            break;
        }
        year++;
    }
    return result;
}

int main(){
    cin >> E >> S >> M;
    cout << calculateYear() << endl;

    return 0;

}