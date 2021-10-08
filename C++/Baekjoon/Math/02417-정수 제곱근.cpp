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
ll answer;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    answer = sqrt(n);
    if (answer * answer < n)answer++;

    cout << answer;
    

}