#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int z_cnt = 0;
int cnt = 0;

string toBinary(int n)
{
    string tmp;
    while (n) {
        if(n%2) tmp="1"+tmp;
        else tmp="0"+tmp;
        n /= 2;
    }
    cout<<tmp<<'\n';
    return tmp;
}
string toBinaryZero(string n) {
    string tmp;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] != '0') {
            tmp += n[i];
        }
        else {
            z_cnt++;
        }
    }
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;

    while (1) {
        if (s == "1")break;
        s = toBinaryZero(s);
        s = toBinary(s.length());
        cnt++;
    }
    answer.push_back(cnt);
    answer.push_back(z_cnt);
    return answer;
}
