#include <iostream>

//start: 5:28  end: 

int n,k;
int board[1001][1001];
int c_board[1001][1001];
int answer=0;

using namespace std;

int main() {
	
	int n,k;
	int x1,x2,y1,y2;
	
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		board[y1][x1]+=1;
		board[y1][x2]-=1;
		board[y2][x1]-=1;
		board[y2][x2]+=1;
	}	
	for(int i=0;i<1001;i++){
		for(int j=1;j<1001;j++){
			board[i][j]+=board[i][j-1];
		}
	}
	
	
	for(int j=0;j<1001;j++){
		for(int i=1;i<1001;i++){
			board[i][j]+=board[i-1][j];
			
		}
	}
	
	int ans=0;
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			if(board[i][j]==k)ans++;
		}
	}
	cout<<ans;
	
		
}
