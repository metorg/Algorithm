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

int n, m,num,num2;
string str;
vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for(int i=0;i<n;i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < m; i++) {
        cin >> num >> num2;
        cout<<upper_bound(v.begin(),v.end(),num2)-v.begin()<<'\n';
    }
}