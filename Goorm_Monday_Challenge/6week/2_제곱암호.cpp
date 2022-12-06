#include <iostream>

using namespace std;

int main() {
	
	int n,number;	
	char alpa;
	string answer;
	
	cin>>n;
	
	for(int i=0;i<n/2;i++){
		cin>>alpa>>number;
		answer.push_back((((alpa-'a')+(number*number))%26)+'a');
	}
	
	cout<<answer;
	
	return 0;
}
