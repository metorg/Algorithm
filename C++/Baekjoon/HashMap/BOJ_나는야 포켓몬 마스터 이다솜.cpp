#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;
    unordered_map<string, int> um;
    vector<string> name;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        um[s] = i;
        name.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        if ('0' <= s[0] && s[0] <= '9')cout << name[stoi(s) - 1] << '\n';
        else cout << um[s] << '\n';
    }

}
