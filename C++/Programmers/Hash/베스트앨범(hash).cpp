#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second >b.second;
}

bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> play;
    unordered_map<string, int> total_play;
    vector<pair<string, int>> c_total_play;
    
    for (int i = 0; i < genres.size(); i++) {
        total_play[genres[i]] += plays[i];
        play[genres[i]].push_back({ plays[i],i });
    }
    
    c_total_play.assign(total_play.begin(), total_play.end());
    sort(c_total_play.begin(), c_total_play.end(), compare);
    
    for (auto &it: play) {
        sort(it.second.begin(), it.second.end(),compare2);
    }
    
    for (int i = 0; i < c_total_play.size(); i++) { 
        for (int j = 0; j < play[c_total_play[i].first].size(); j++) {
            if (j == 2)break;
            answer.push_back(play[c_total_play[i].first][j].second);
        }
    }
    return answer;
}