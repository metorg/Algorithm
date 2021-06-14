#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> gems) {
    
    vector<int> answer;
    unordered_map<string, int> um;

    int start = 0, end = 0;
    int t = 99999;
    set<string> s;

    for (int i = 0; i < gems.size(); i++) {
        s.insert(gems[i]);
    }

    while (1) {
       
        if (s.size() <= um.size()) {
      
            um[gems[start]]--;
            if (um[gems[start]] == 0) {
                um.erase(gems[start]);
            }
            start++;
        }
        
        else if (end == gems.size())break;
        
        else {
            um[gems[end]]++;
            end++;
        }

        if (s.size() == um.size()) {
            if (t > abs(end - start)) {
                answer.clear();
                t = abs(end - start);
                answer.push_back(start+1);
                answer.push_back(end);
            }
        }
    }
    return answer;
}
