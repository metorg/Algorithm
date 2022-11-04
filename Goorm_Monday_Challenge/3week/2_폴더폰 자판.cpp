#include <bits/stdc++.h>
using namespace std;
int main() {
	
	vector<vector<int>> v={{'1','.',',','?','!'},{'2','A','B','C'},{'3','D','E','F'},{'4','G','H','I'},
												 {'5','J','K','L'},{'6','M','N','O'},{'7','P','Q','R','S'},{'8','T','U','V'},																	{'9','W','X','Y','Z'}};
	int n,prev_num;
	char num;
	string s;
	int cnt=1;
	
	cin>>n;
	cin>>num;
	prev_num=num-'0';
	
		
	for(int i=1;i<n;i++){
		cin>>num;
		if(prev_num!=num-'0'){		
			s.push_back(v[prev_num-1][(cnt-1)%v[prev_num-1].size()]);
			prev_num=num-'0';
			cnt=1;
		}
		else{
			cnt++;
		}
	}
	
	s.push_back(v[(num-'0')-1][(cnt-1)%v[(num-'0')-1].size()]);
	
	cout<<s;
	return 0;
}
