#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>

using namespace std;

int n;
string str;

void backtracking(string a,int index) {
	if (index == a.length()-1) {
		cout << a<<'\n';
		return;
	}
	for (int i = index; i < a.length(); i++) {
		if (i != index && a[i] == a[index])continue;//중복된 알파벳일때 교환자체를 안해주면됨
		if (a[i] != a[index]) {
			char tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
		backtracking(a,index+1);
	}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		sort(str.begin(), str.end());	
		backtracking(str,0);	
	}

}