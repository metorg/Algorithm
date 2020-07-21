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
    if (begin == target) {//���۴ܾ�� ��ǥ�ܾ ������ �����Ѵ�

        return;
    }
    for (int i = 0;i < words.size();i++) {
        cnt = 0;

        if (!visit[i] && begin != words[i]) {//�湮�� ���� ���۴ܾ�� ���ʹܾ�� �ٸ��� üũ�� �����Ѵ�
            for (int j = 0;j < words[i].size();j++) {

                if (begin[j] == words[i][j]) {
                    cnt++;
                }
            }
        }
        if (max <= cnt) {//���� ������ �ܾ��� �ε������� ���� ���� ���� ����
            max = cnt;
            remember = i;
        }
    }
    
    visit[remember] = 1;//����� �ε������� �湮 üũ �� dfsŽ���� �����Ѵ� 
    dfs(words[remember], target, words);
    answer++;
    
    return;
}
int solution(string begin, string target, vector<string> words) {

    for (int i = 0;i < words.size();i++) {//Ÿ���� ���� �ȿ� ������ dfs�Լ��� ����ϰ� ������ 0�� ��ȯ�Ѵ�
        if (target == words[i]) {
            dfs(begin, target, words);

            break;
        }
    }
  
    return answer;
}
