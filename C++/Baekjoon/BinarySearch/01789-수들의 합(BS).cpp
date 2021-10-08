#include<string>
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<queue>
#include<stack>

using namespace std;
typedef long long ll;

ll n;

bool check(ll num) {
    return (num * (num + 1)) / 2 > n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    ll start = 1; 
    ll end = sqrt(4294967295 * 2);
    
    while (start <= end) {
       
        ll mid = (start + end) / 2;
        if (check(mid))end = mid - 1;
        else start = mid + 1;

    }
    cout << end;
}