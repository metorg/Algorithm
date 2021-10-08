#include<string>
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;

int n, m,num;
vector<int> v;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    ll left = 1;
    ll right = v[0];
  
    while (left <= right) {
        ll mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            cnt+=v[i] / mid;
        }
        if (cnt >= m) left=mid+ 1;
        else right=mid - 1;
    }
    cout << right;

}