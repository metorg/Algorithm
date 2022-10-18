#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int n,tracking_number;
	string s;
	double d;
	vector<pair<string,double>> v;
	
	cin>>n>>tracking_number;
	
	for(int i=0;i<n;i++){
		cin>>s>>d;
		v.push_back({s,d});
	}	
	
	sort(v.begin(),v.end());
	
	cout<<fixed;
	cout.precision(2);
	cout<<v[tracking_number-1].first<<' '<<v[tracking_number-1].second;
	
	return 0;
}
