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

    int n, m,num;
    int start, finish;
    vector<int> v = { 0 };
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(v[i] + num);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> start >> finish;
        cout << v[finish] - v[start - 1]<<'\n';
    }
}
