#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
//KEY POINT: 설명이 너무 불친절
string encryption(string s1,string s2) {

	string answer;

	for (int i = 0; i < s2.length(); i++) {
		int shift=0;
		if ('a' <= s1[i] && s1[i] <= 'z') {
			shift=int(s2[i])%26;
			answer.push_back((((s1[i]-'a')+shift)%26)+'a');
		}
		else if ('A' <= s1[i] && s1[i] <= 'Z') {
			shift=int(s2[i])%26;
			answer.push_back((((s1[i]-'A')+shift)%26)+'A');
		}
		
		else answer.push_back(s1[i]);
	}
	return answer;
}

string dencryption(string s1,string s2) {

	string answer;

	for (int i = 0; i < s2.length(); i++) {
		int shift=0;
		if ('a' <= s1[i] && s1[i] <= 'z') {
			shift=int(s2[i])%26;
			
			if(s1[i]-'a'-shift<0)
			answer.push_back(26-((abs((s1[i]-'a')-shift)%26))+'a');
			else{
				answer.push_back((((s1[i]-'a')-shift)%26)+'a');
			}
			
		}
		else if ('A' <= s1[i] && s1[i] <= 'Z') {
			shift=int(s2[i])%26;
			
			if(s1[i]-'A'-shift<0)
			answer.push_back(26-((abs((s1[i]-'A')-shift)%26))+'A');
			else{
				answer.push_back((((s1[i]-'A')-shift)%26)+'A');
			}			
		}
		
		else answer.push_back(s1[i]);
	}
	return answer;
}


int main() {

	int n;
	char token;
	string m,k;

	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
	
		getline(cin,m);
		cin>>token;
		cin.ignore();
		getline(cin,k);
		
		string tmp=k;
		for (int j = tmp.length(); j < m.length(); j++) {
			k.push_back(tmp[j % tmp.length()]);
		}

		if (token == 'E') {
				cout<<encryption(m,k)<<'\n';
		}
		else{
			cout<<dencryption(m,k)<<'\n';
		}
	}

}
