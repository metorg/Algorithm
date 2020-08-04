#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
int main() {
	string a;
	cin >> a;

	if (a[a.size() - 1] == '1') {
		cout << "false";
		return 0;
	}
	for (int i = 1;i < a.size();i++) {
		if (a[i - 1] == '1') {
			if (a[i] == '2') {

			}
			else {
				cout << "false";
				return 0;
			}

		}
	}
	cout << "true";
	return 0;
}