#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string.h>
#include<stdio.h>
#include<stack>
#include<memory.h>
#include<unordered_map>
#include<set>
#include<bitset>
#include<string>

#define MAX 300000
using namespace std;

int n;
int visit[MAX] = { 0,0 };


void eratos() {
	int cnt = 0;
	for (int i = 2; i <= MAX; i++)
	{
		if (!visit[i])
		{
			cnt++;
			for (int j = i * 2; j <= MAX; j += i) {
				visit[j] = 1;
			}
		}
		visit[i] = cnt;
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	eratos();

	while (1) {
		cin >> n;
		if (n == 0)break;
		cout << visit[2 * n] - visit[n]<<'\n';
	}

}