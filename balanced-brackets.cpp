// Solve this problem on LeetCode and copy your code here to submit
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stck.push(s[i]);
            else if (s[i] == '}')
            {
                if (stck.top()!= '{' || stck.empty())
                    return false;
                else
                    stck.pop();
            }
            else if (s[i] == ')')
            {
                if (stck.top()!='(' || stck.empty() )
                    return false;
                else
                    stck.pop();
            }
            else if (s[i] == ']')
            {
                if (stck.empty() || stck.top()!= '[')
                    return false;
                else
                    stck.pop();
            }
        }
        if (stck.empty())
        {
            return true;    
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution s;
    bool valid = s.isValid("{[]}(){");
    cout << valid << endl;
    return 0;
}