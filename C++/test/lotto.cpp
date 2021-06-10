#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
	string a;
	int b = 0;
	int cnt = 0;
	int c = 0;
	getline(cin, a);
	set<int> s;

	for (int i = 0;i < a.size();i++) {

		if (a[i] == ' ') {
			if (c > b) {
				cout << "false";
				return 0;
			}
			s.insert(b);
			c = b;

			b = 0;
		}
		else {
			b = (b * 10) + (a[i] - '0');
		}
		if (b > 45 || b < 0) {
			cout << "false";
			return 0;

		}

	}

	if (s.size() == 6) {
		cout << "true";

	}
	else {
		cout << "false";
	}

}