#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

string s;
string temp;
string max_answer;
string min_answer;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	int cnt = 0;
	int cut = 0;
	for (int i = 0; i < s.length(); i++) {		
		if (s[i] == 'K') {
			if (cnt == 0) {
				max_answer+= "5";
			}
			else {
				temp[0] = '5';
				temp += "0";
				max_answer += temp;
			}
			cnt = 0;
			temp = "";
			cut = 1;
		}
		else if (cnt == 0 && s[i] == 'M') {
			temp = "1";
			cnt++;
		}
		else if (cnt > 0 && s[i] == 'M') {
			temp += "0";
			cut = 0;
		}
	}
	
	if (cut == 0) {
		for (int i = 0; i < temp.length(); i++) {
			temp[i] = '1';
		}
		max_answer += temp;
	}
	else {
		max_answer += temp;
	}
	
	
	temp = "";
	cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'K') {
			min_answer += temp;
			min_answer += '5';
			cnt = 0;
			temp = "";
		}
		else if (cnt == 0 && s[i] == 'M') {
			temp += '1';
			cnt++;
		}
		else if (cnt > 0 && s[i] == 'M') {
			temp += '0';
			
		}
	}
	min_answer += temp;
	cout << max_answer<<'\n'<<min_answer;

}