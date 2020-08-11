#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	int n;
	vector<int> v;

	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++) {
		cout << v[i] << '\n';
	}

}