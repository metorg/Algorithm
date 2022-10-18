#include <iostream>
#include <string>

using namespace std;
int main() {
	
	int n;
	char ch;
	string s;
	int answer=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ch;
		if(s.back()!=ch)answer++;
		s.push_back(ch);
	}
	
	cout<<answer;
	
	return 0;
}
