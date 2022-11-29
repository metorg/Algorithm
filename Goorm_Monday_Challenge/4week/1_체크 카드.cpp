#include <iostream>
#include <queue>

using namespace std;

//start 3:53  end 4:09 16분 소모
//key point : 입금이 되자마자 예약자 리스트에서 바로 소모 되는 부분 

int balance,m,amount;
queue<int> reservation_list;
string s;

void deposit(int amount){
	balance+=amount;
	return;
}

void pay(int amount){
	if(amount>balance)return;
	else balance-=amount;
	return;
}

void reservation(){
	
	while(!reservation_list.empty()){
		if(reservation_list.front()>balance)return;
		else {
			balance-=reservation_list.front();
			reservation_list.pop();
		}
	}
}

int main() {
	
	cin>>balance>>m;
	
	for(int i=0;i<m;i++){
		cin>>s>>amount;
		
		if(s=="deposit"){
			deposit(amount);
			reservation();
		}
		else if(s=="pay"){
			pay(amount);
		}
		else if(s=="reservation"){
			reservation_list.push(amount);
			reservation();
		}
	}
	cout<<balance;
}
