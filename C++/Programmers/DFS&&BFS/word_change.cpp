#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

int visit[51] = { 0 };
int answer;

void dfs(string begin, string target, vector<string> words) {
    
    int cnt = 0;
    int max = 0;
    int remember = 0;
    if (begin == target) {//시작단어와 목표단어가 같으면 종료한다

        return;
    }
    for (int i = 0;i < words.size();i++) {
        cnt = 0;

        if (!visit[i] && begin != words[i]) {//방문이 없고 시작단어와 벡터단어와 다르면 체크를 시작한다
            for (int j = 0;j < words[i].size();j++) {

                if (begin[j] == words[i][j]) {
                    cnt++;
                }
            }
        }
        if (max <= cnt) {//가장 유사한 단어의 인덱스값과 같은 글자 수를 저장
            max = cnt;
            remember = i;
        }
    }
    
    visit[remember] = 1;//저장된 인덱스값을 방문 체크 후 dfs탐색을 시작한다 
    dfs(words[remember], target, words);
    answer++;
    
    return;
}
int solution(string begin, string target, vector<string> words) {

    for (int i = 0;i < words.size();i++) {//타겟이 벡터 안에 있으면 dfs함수를 사용하고 없으면 0을 반환한다
        if (target == words[i]) {
            dfs(begin, target, words);

            break;
        }
    }
  
    return answer;
}
