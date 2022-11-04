#include<bits/stdc++.h>

using namespace std;
int main() {
	
	int n,num;
	vector<int> v;
	unordered_map<int,int> map;
	int sum=0;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
			cin>>num;
			if(map[abs(num)]==0){
				map[abs(num)]=num;
				sum+=num;
			}
			else{
				sum-=map[abs(num)];
			}
	}
	
	cout<<sum;
	
	return 0;
		
}
