#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;


string solution(string S, int K)
{
	string Answer = "";
	stack<char> Stack;
	int Remove_Cnt = 0;
	int Answer_Size = S.length() - K;

	for (int i = 0; i < S.length(); i++)
	{
		char Num = S[i];
		while (Stack.empty() == 0 && Remove_Cnt < K)
		{
			char TopNum = Stack.top();
			if (TopNum < Num)
			{
				Stack.pop();
				Remove_Cnt++;
			}
			else break;
		}
		Stack.push(Num);
	}

	if (Answer_Size != Stack.size()) Stack.pop();
	stack<char> Temp;
	while (Stack.empty() == 0)
	{
		Temp.push(Stack.top());
		Stack.pop();
	}
	while (Temp.empty() == 0)
	{
		Answer = Answer + Temp.top();
		Temp.pop();
	}
	return Answer;
}