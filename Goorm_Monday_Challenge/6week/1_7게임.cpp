#include <iostream>

using namespace std;

int sevenGame(string s){
	int sum=0;
	int mul=1;
	
	for(int i=0;i<s.length();i++){
		
		if(i%2==0)sum+=s[i]-'0';
		else{
			if(s[i]!='0')mul*=s[i]-'0';
		}	
	}
	return (sum*mul)%10;
}

int main() {

	string s;
	
	for(int i=0;i<5;i++){
		cin>>s;
		cout<<sevenGame(s)<<'\n';
	}
}
