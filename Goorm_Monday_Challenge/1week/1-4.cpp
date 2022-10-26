#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
//배열 길이를 초과하는 범위일때를 한번 더 생각해봐야 될것같다.
//소수만 뽑아놓을수 있는 배열을 만드는 방법을 생각해보자.
int prime[100001]={1,1,};

void PrimeNum(){
	for(int i=2;i<=sqrt(100001);i++){
		if(prime[i]==1)continue;
		else{
			for(int j=i*i;j<=100001;j+=i){
				prime[j]=1;
			}
		}
	}
}

int main() {
	
	PrimeNum();
	int n,num,answer=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		if(prime[i]==0)answer+=num;
		
	}
	cout<<answer;
	
	return 0;
}
