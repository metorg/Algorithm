#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>


using namespace std;
int n,num;
int mcnt = 0;
int avg = 0;
int visit[8002];
vector<int> v;
vector<int> cnt;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		avg += num;
		visit[num + 4000] += 1;
		if (mcnt < visit[num + 4000]) {
			mcnt = visit[num + 4000];
		}
		v.push_back(num);
	}
	for (int i = 0; i <=8000; i++) {
		if (mcnt == visit[i]) {
			cnt.push_back(i-4000);
		}
	}
	sort(cnt.begin(), cnt.end());
	sort(v.begin(), v.end());


	cout << round((float)avg / n)<<'\n';
	cout << v[v.size()/2]<<'\n';
	if (cnt.size() > 1) cout << cnt[1]<<'\n';
	else cout << cnt[0] << '\n';	
	cout << v.back()-v.front();
}
