#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

int num;
vector<int> answer_num;
vector<int> tmp;

int main() {
    
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> num;
    
    for (int i = num; i > 0; i--) {
        tmp.push_back(num);
        tmp.push_back(i);
 
        while (tmp[tmp.size()-1]>=0) {
            tmp.push_back(tmp[tmp.size() - 2] - tmp[tmp.size() - 1]);
        }
        tmp.pop_back();
        if (answer_num.size() < tmp.size()) {
            answer_num = tmp;
        }
        tmp.clear();
    }
    cout << answer_num.size() << '\n';
    for (int i = 0; i < answer_num.size(); i++) cout << answer_num[i] << ' ';

}
