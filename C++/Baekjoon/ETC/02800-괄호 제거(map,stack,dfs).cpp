#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include<cstring>
#include<stack>

using namespace std;

int visit[200];
int visit2[10];
string st;
vector<pair<int, int>> v;
unordered_map<string, int> um;
vector<string> answer;
void print() {
	
	string tmp = "";
	for (int i = 0; i < st.length(); i++) {
		if (visit[i] == 1)continue;
		
		tmp += st[i];
	}
	if (!um[tmp]) {//중복된 값은 못들어가게 걸러준다
		answer.push_back(tmp);
	}
	um[tmp]++;//중복된 값이 들어갈수 있으니 check하기 위하여 
}

void backtracking(int start) {
	for (int i = start; i < v.size(); i++) {
		
		if(visit2[i]==1)continue;

		visit2[i] = 1;
		visit[v[i].first] = 1;
		visit[v[i].second] = 1;
		print();
		backtracking(i);
		visit2[i] = 0;
		visit[v[i].first] = 0;
		visit[v[i].second] = 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> s;
	
	cin >> st;
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == '(') {
			s.push(i);
		}
		else if (st[i] == ')') {
			v.push_back({ s.top(), i });
			s.pop();
		}
	}
	
	backtracking(0);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	

}