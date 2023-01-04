#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

unordered_map<int, int> um;
vector<pair<int, int>> modenum;
vector<int> v;
int n,num;
int mean,middle,most_val=0,range;
double sum = 0;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        um[num]++;
        sum += num;
        v.push_back(num);
    }

    for (auto iter = um.begin(); iter != um.end(); iter++) {
        modenum.push_back({ iter->second,iter->first });
    }
    sort(modenum.begin(), modenum.end(), greater<pair<int, int>>());
    sort(v.begin(), v.end());
    mean = round(sum / n);
    middle = v[n / 2];
    range = v[v.size() - 1] - v[0];
    
    for (int i = 1; i < modenum.size(); i++) {
        if (modenum[most_val].first == modenum[i].first) {
            most_val = i;
        }
        else break;
    }
    if (most_val != 0)most_val = modenum[most_val - 1].second;
    else most_val = modenum[0].second;
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
}
