#include<string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int a;
string str;
string str2;
int flag = 0;
void seq(string v) {
	if (flag == 1)return;
	for (int i = 0;i < v.size() / 2;i++) {
		str = v.substr(v.size() - 1 - i, i + 1);
		str2 = v.substr((v.size() - 1 - i) - (i + 1), i + 1);
		if (str.compare(str2) == 0) {

			return;
		}
	}
	if (v.size() == a) {
		cout << v;
		flag = 1;

		return;
	}
	for (int i = 1;i <= 3;i++) {
		seq(v + (char)(i + '0'));
	}
}
int main() {
	cin >> a;
	seq("1");
}