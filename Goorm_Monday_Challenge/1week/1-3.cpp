#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	vector<int> v;
	int num;
	for(int i=0;i<4;i++){
		cin>>num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	
	cout<<abs(v[0]-v[3])+abs(v[1]-v[2]);
	
	
	return 0;
}
