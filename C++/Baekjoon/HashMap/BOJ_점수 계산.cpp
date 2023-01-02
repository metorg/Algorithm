#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
    
    int num;
    int sum = 0;
    vector<pair<int, int>> v;
    vector<int> answer;

    for (int i = 1; i <= 8; i++) {
        cin >> num;
        v.push_back({ num,i });
    }
    sort(v.begin(), v.end(),greater<pair<int,int>>());
    
    for (int i = 0; i < 5; i++) {
        sum += v[i].first;
        answer.push_back(v[i].second);
    }
    cout << sum << '\n';
    
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

}
