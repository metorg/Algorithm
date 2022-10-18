#include <iostream>
#include <vector>

using namespace std;
int main() {
	
	int n,k,score;
	vector<int> v;
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		double average=0;
		int answer=0;
		cin>>k;
		
		for(int j=0;j<k;j++){
			cin>>score;
			v.push_back(score);
			average+=score;
		}
		for(int j=0;j<v.size();j++){
			if(average/v.size()<=v[j])answer++;
		}
		cout<<answer<<"/"<<v.size()<<'\n';
		v.clear();
	}
	
	return 0;
}
