#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        
        int cnt = 0;
        while (1) {
            if (cnt == board.size())break;
            if (board[cnt][moves[i] - 1] != 0) {
                if (!s.empty()) {
                    if (s.top() == board[cnt][moves[i] - 1]) {
                        answer++;
                        s.pop();
                    }
                    else {
                        s.push(board[cnt][moves[i] - 1]);
                    }
                }
                else {
                    s.push(board[cnt][moves[i] - 1]);
                }
                board[cnt][moves[i] - 1] = 0;
                break;
            }
            cnt++;
        }
    }
    return answer * 2;
}
