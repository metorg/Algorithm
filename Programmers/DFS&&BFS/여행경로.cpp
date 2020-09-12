#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

vector<string> answer;
int visited[10001];
int cnt = 0;


void dfs(vector<vector<string>> tickets, string start, vector<string> str) {


    if (str.size() == tickets.size()) {
        str.push_back(start);
        cnt = 1;
        answer = str;

        return;
    }

    for (int i = 0;i < tickets.size();i++) {
        if (cnt == 1)break;

        if (tickets[i][0] == start && !visited[i]) {
            str.push_back(tickets[i][0]);


            visited[i] = 1;

            dfs(tickets, tickets[i][1], str);
            str.pop_back();
            visited[i] = 0;



        }


    }



}
vector<string> solution(vector<vector<string>> tickets) {
    string start = "ICN";
    sort(tickets.begin(), tickets.end());
    for (int i = 0;i < tickets.size();i++) {

        if (tickets[i][0] == start) {
            answer.push_back(tickets[i][0]);
            visited[i] = 1;

            dfs(tickets, tickets[i][1], answer);
            if (cnt == 1) {
                for (int i = 0;i < answer.size();i++) {
                    cout << answer[i] << ' ';
                }
                return answer;
            }
            answer.pop_back();
            visited[i] = 0;


        }
    }

    return answer;
}