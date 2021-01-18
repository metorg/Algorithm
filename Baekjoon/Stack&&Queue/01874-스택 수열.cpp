#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	int num, num2, num3;
	int cnt = 1;
	int count = 0;

	vector<char> v;
	cin >> num;

	for (int i = 0;i < num;i++) {

		cin >> num2;

		while (1) {
			if (cnt <= num2) {
				s.push(cnt);
				cnt++;
				v.push_back('+');
			}
			else break;
		}

		while (!s.empty()) {

			if (s.top() == num2) {

				s.pop();
				count++;
				v.push_back('-');
				break;
			}
			else {

				s.pop();
				v.push_back('-');
			}
		}
	}
	if (count == num) {
		for (auto it : v)
			cout << it << '\n';
	}
	else
		cout << "NO";
}


