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

int word_list[10000];

int n, m;
string word;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int remember = 0;
	cin >> n >> m;
	
	for (int i = 0;i < 26;i++) {
		remember += (1 << i);
		
	}
	
	for (int i = 0;i < n;i++) {
		cin >> word;		
		for (int j = 0;j < word.length();j++) {	
			word_list[i] |= (1 << word[j]-'a');		
		}
	}

	
	char alpa;

	for (int i = 0;i < m;i++) {
		int cnt = 0;
		
		cin >>alpa>>alpa;
	
		remember ^= (1 << (alpa - 'a'));
		
		
		for (int j = 0;j < n;j++) {
			if ((word_list[j] & remember) != word_list[j]) continue;
			cnt++;
		}

		cout << cnt<<'\n';
	}
	
}


//비트 마스킹 쓰기전 코드

/*#include <iostream>
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


vector<pair<int, int>> v;
int word_visit[10001][28];
int a, b;
int type;
char alpa;
string word;
int cnt;
int answer;
int main() {

	ios::sync_with_stdio(0);
	cin >> a >> b;
	answer = a;

	for (int i = 0;i < a;i++) {
		cin >> word;
		cnt = 0;
		for (int j = 0;j < word.length();j++) {
			if (word_visit[i][word[j] - 'a'] == 2)continue;
			word_visit[i][word[j] - 'a'] = 2;
			cnt++;
		}
		v.push_back({ cnt,cnt });
	}
	for (int i = 0;i < b;i++) {
		cin >> type >> alpa;
		if (type == 1) {
			for (int j = 0;j < a;j++) {
				if (word_visit[j][alpa - 'a'] == 2) {
					word_visit[j][alpa - 'a'] = 1;
					if (v[j].first == v[j].second) {
						answer -= 1;
						v[j].second -= 1;
					}
					else {
						v[j].second -= 1;
					}

				}
			}
		}
		else {
			for (int j = 0;j < a;j++) {
				if (word_visit[j][alpa - 'a'] == 1) {
					word_visit[j][alpa - 'a'] = 2;
					v[j].second += 1;
					if (v[j].first == v[j].second) {
						answer += 1;
					}
				}
			}
		}

		cout << answer << '\n';
	}

}*/