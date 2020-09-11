#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stack>
#include<memory.h>

using namespace std;

string str2, str3, str;
int solution(string s) {
	if (s.length() == 1)return 1;
	int answer = 2e9;
	int cnt = 0;
	for (int i = 1;i <= s.length() / 2;i++) {
		cnt = 1;
		str3 = "";
		str = s.substr(0, i);

		for (int j = i;j < s.length();j += i) {//str 빼고 전부조사
			str2 = s.substr(j, i);
			if (str.compare(str2) == 0) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					str3 += str;
					str = str2;//비교대상을 뒤에껄로 교체
				}
				else {
					str3 = str3 + to_string(cnt) + str;
					str = str2;
					cnt = 1;
				}
			}
			if (s.length() <= j + i) {//substr과 초과시 break 걸어주는 포인트
				if (cnt == 1) {
					str3 = str3 + s.substr(j);//substr(?)는 ?뒤에꺼만추가
					break;
				}
				else {
					str3 = str3 + to_string(cnt) + str;
					break;
				}
			}

		}
		if (answer > str3.length()) {
			answer = str3.length();
		}
	}
	return answer;
}
