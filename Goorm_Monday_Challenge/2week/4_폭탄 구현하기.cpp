#include <iostream>

using namespace std;

int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};

int main() {
	int n,k;
	int x,y;
	
	cin>>n>>k;
	int answer=k;
	
	for(int i=0;i<k;i++){
		cin>>x>>y;
		for(int j=0;j<4;j++){
			int c_x=x+xx[j];
			int c_y=y+yy[j];			
			if(c_x<=0||c_y<=0||c_x>n||c_y>n)continue;
			answer++;
		}
	}
	cout<<answer;
	
}
