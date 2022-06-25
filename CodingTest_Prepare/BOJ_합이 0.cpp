#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int N,num;
vector<int> v;
long long answer = 0;

int main(){

	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-2; i++) {
		int left = i + 1;
		int right = v.size() - 1;
		int sum = v[i];
		if (v[i] > 0)break;
		while (left < right) {
			if (sum + v[left] + v[right] == 0) {
				if (v[left] ==v[right]) {
					answer += ((right - left + 1) * (right - left))/2;
					break;
				}
				else {
					int cnt = 0;
					int cnt2 = 0;
					int c_left = left;
					int c_right = right;

					while (1) {
						if (v[left] != v[c_left]) {
							break;
						}
						else {
							left++; 
							cnt++;
						}
					}
					while (1) {
						if (v[right] != v[c_right]) {
							break;
						}
						else {
							right--;
							cnt2++;
						}
					}
					answer += (cnt * cnt2);
				}
				
			}
			else if (sum + v[left] + v[right] < 0)left++;
			else if (sum + v[left] + v[right] > 0)right--;
		}
	}
	cout << answer;

}
