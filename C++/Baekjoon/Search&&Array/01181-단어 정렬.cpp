#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
vector<pair<int, string>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	vector<string> d;
	string input;
	cin >> num;
	vector<pair<int, string>>::iterator iter;
	for (int i = 0;i < num;i++) {
		cin >> input;
		d.push_back(input);

	}
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	for (int i = 0;i < d.size();i++) {
		s.push_back(pair<int, string>(d[i].size(), d[i]));
	}

	sort(s.begin(), s.end());
	for (iter = s.begin();iter != s.end();iter++) {
		cout << iter->second << '\n';
	}

}