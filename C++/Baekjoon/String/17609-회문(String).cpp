#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int n;
string s;
int answer;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> s;
		string tmp;
		int index = -1;

		//전체 회문 조사(전체가 회문이 맞으면 요소 제거해도 회문이므로 바로 0 출력)
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				index = i;
				tmp = s[i];
				break;
			}
		}
				
		if (index == -1) {
			cout << 0 << '\n';
			continue;
		}

		//왼편 요소 제거 회문 조사
		s.erase(index, 1);
		int cnt = 0;
		for (int j = 0; j < s.length() / 2; j++) {
			if (s[j] != s[s.length() - 1 - j]) {
				cnt++;
				break;
			}
		}

		//오른편 요소 제거 회문 조사
		s.insert(index, tmp);		
		s.erase(s.length() - 1 - index, 1);

		for (int j = 0; j < s.length() / 2; j++) {
			if (s[j] != s[s.length() - 1 - j]) {
				cnt++;
				break;
			}
		}
		if (cnt == 2)cout << 2 << '\n';
		else cout << 1 << '\n';
	}

}



