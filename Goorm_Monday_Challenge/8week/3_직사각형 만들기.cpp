#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<long long,int> um;
vector<long long> line;

int n;
long long num;
long long answer=0;
int main() {
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		um[num]++;
		if(um[num]&&um[num]%2==0)line.push_back(num);
	}
	
	sort(line.begin(),line.end());
	
	for(int i=line.size()-2;i>=0;i-=2){
		answer+=(line[i]*line[i+1]);
	}
	
	cout<<answer;
	
	return 0;
}
