#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>


using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int target, int sum, int idx) {
    if (idx >= numbers.size()) {
        if (sum == target) ans++;
        return;
    }

    dfs(numbers, target, sum + numbers[idx], idx + 1);
    dfs(numbers, target, sum - numbers[idx], idx + 1);

}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans;
}