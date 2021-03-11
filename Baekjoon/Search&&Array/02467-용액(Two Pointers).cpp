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

using namespace std;

int solution_num;
int solution[100001];


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> solution_num;
	
	for (int i = 0;i < solution_num;i++) {
		cin >> solution[i];
	}

	int start = 0;
	int end = solution_num - 1;
	int min = abs(solution[start]+solution[end]);
	int min_start = solution[start];
	int min_end = solution[end];
	
	while (start < end) {
		int result = (solution[end] + solution[start]);
		
		if (abs(result) < min) {
			min = abs(result);
			min_start = solution[start];
			min_end = solution[end];
		}
		
		if (result > 0) end -= 1;	
		else start += 1;

	cout << min_start << ' ' << min_end;

}