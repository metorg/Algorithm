#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n,num;
	long long sum=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		sum*=num;
	}
	cout<<sum;
}
