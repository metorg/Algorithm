#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,num;
    int answer = 0;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    int cnt = v.size();

    for (int i = 0; i < v.size(); i++) {
        answer = max(answer,v[i]*cnt--);
    }
    cout << answer;
}
