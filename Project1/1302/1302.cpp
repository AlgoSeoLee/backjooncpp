#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int maxNum = 0;
    int num = 0;
    string temp = v[0];
    string result;
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++){
        if (v[i] == temp) {
            num++;
        }
        else{
            if (maxNum < num){
                maxNum = num;
                result = temp;
            }
            temp = v[i];
            num = 1;
        }
    }
    if (maxNum < num) {
        result = temp;
    }
    cout << result << "\n";
    
    return 0;
}