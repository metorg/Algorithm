#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	int msum = 0;
	int change = 0;
	string ch;
	vector<int> number;
	vector<char> oper;

	cin >> ch;

	if (ch[0] != '-')oper.push_back('+');

	for (int i = 0;i <= ch.length();i++) {
		if ('0' <= ch[i] && ch[i] <= '9') sum = (sum * 10) + (ch[i] - '0');

		else if (ch[i] == '+' || ch[i] == '-') {
			number.push_back(sum);
			oper.push_back(ch[i]);
			sum = 0;
		}
		else number.push_back(sum);
	}

	
	for (int i = 0;i < number.size();i++) {
		if (oper[i] == '-') change = 1;
		if (change == 1)msum += (-number[i]);
		else msum += number[i];
	}	
	cout << msum;
}