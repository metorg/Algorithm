#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

vector<int> pi;
vector<int> answer;
int answer_cnt = 0;
void getPi(string p) {

	int j = 0;
	pi.resize(p.size(), 0);
	
	for (int i = 1; i < p.length(); i++) {
		while ((j > 0) && (p[i] != p[j]))
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
}


void kmp(string s, string p) {
	
	
	getPi(p);
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == p.length() - 1) {
				answer.push_back((i+1)-(p.length()-1));
				answer_cnt++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, p;

	getline(cin,s);
	getline(cin,p);
	kmp(s, p);
	cout << answer_cnt<<'\n';
	for (int i = 0; i < answer.size(); i++) {
		cout<<answer[i]<<' ';
	}

}



