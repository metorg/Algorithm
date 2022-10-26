#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int n;
	string my_name,name;
	int answer=0;
	
	cin>>n>>my_name;
	for(int i=0;i<n;i++){
		cin>>name;
		int cnt=0;
		for(int j=0;j<name.length();j++){
			
			if(my_name[cnt]==name[j]){
				cnt++;
				if(cnt==my_name.length()){
					answer++;
					break;
				}
			}			
			else{
				if(my_name[0]==name[j])cnt=1;
				else cnt=0;
			}
		}
		
	}	
	cout<<answer;
}
