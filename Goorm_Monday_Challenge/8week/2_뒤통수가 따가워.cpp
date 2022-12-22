#include <iostream>
#include <stack>

using namespace std;

int main() {
	int people[100001];
	stack<int> s;
	int n;
	
	cin>>n;
	for(int i=0;i<n;i++)cin>>people[i];
	
	for(int i=0;i<n;i++){
		cout<<s.size()<<' ';
		while(!s.empty()&&s.top()<=people[i])s.pop();
		s.push(people[i]);
	}
	
}
