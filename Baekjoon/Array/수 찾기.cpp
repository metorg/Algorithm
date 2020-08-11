#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
vector<int> s;

int Bsearch(int target) {
	int first = 0;
	int last = s.size() - 1;
	int mid = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		if (s[mid] == target) {
			return 1;
		}
		else if (s[mid] > target) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}

	}
	return 0;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, num2;
	int n, m;

	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> n;
		s.push_back(n);
	}
	sort(s.begin(), s.end());

	cin >> num2;

	for (int i = 0;i < num2;i++) {
		cin >> m;


		cout << Bsearch(m) << '\n';

	}


}