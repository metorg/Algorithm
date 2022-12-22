#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
int main() {
	string alpabet[10]={"ze","qw","as","zx","we","sd","xc","er","df","cv"};
	unordered_map<string,char> stringToInt;
	
	int n;
	string input;
	string answer;
	
	for(int i=0;i<=9;i++)stringToInt[alpabet[i]]=i+'0';
	
	cin>>n>>input;
	for(int i=0;i<input.length()-1;i++){
		if(stringToInt.count(input.substr(i,2)))answer+=stringToInt[input.substr(i,2)];
	}
	
	cout<<answer;
	return 0;
}
