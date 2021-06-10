#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int x, y;
	if ((heights[0] * heights[4]) - (heights[1] * heights[3]) == 0) {
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}
	else {
		x = ((heights[2] * heights[4]) - (heights[1] * heights[5])) / ((heights[0] * heights[4]) - (heights[1] * heights[3]));
		y = ((heights[0] * heights[5]) - (heights[2] * heights[3])) / ((heights[0] * heights[4]) - (heights[1] * heights[3]));
		answer.push_back(x);
		answer.push_back(y);
	}
	for (int i = 0;i < answer.size();i++) {
		cout << answer[i]<<' ';
	}
	return answer;
}
int main() {
	vector<int> d;
	int num;
	for (int i = 0;i < 6;i++) {
		cin >> num;
		d.push_back(num);
	}
	
	solution(d);
	
	
}