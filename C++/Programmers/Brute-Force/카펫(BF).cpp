#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    
    int sum=brown+yellow;    
    
    for(int i=3;i<brown/2;i++){
     
        int c_brown = ((sum/i)*2)+((i-2)*2);
        int c_yellow =(i-2)*((sum/i)-2);
        
        if(c_brown==brown&&c_yellow==yellow){            
            answer.push_back(sum/i);
            answer.push_back(i);
            break;
        }
    }
    return answer;
}