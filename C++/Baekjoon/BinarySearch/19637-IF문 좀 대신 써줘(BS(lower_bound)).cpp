#include<string>
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

using namespace std;
typedef long long ll;

int n, m,num;
string str;
map<int, string> names;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> str >> num;
        names.insert({ num,str });
    }
    map<int, string>::iterator iter;
    for (int i = 0; i < m; i++) {
        cin >> num;
        iter = names.lower_bound(num);
        cout << iter->second << '\n';
    }


}