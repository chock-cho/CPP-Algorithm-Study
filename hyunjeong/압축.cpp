#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    map<string, int> dic;
    vector<int> answer;
    string tmp = "";
    string w = "";
    string c = "";
    int cnt = 27;
    int i = 0;
    
    for (int i = 1; i < 27; i++)
    {
        tmp = 'A' + i - 1;
        dic.emplace(tmp, i);
    }

    while (i <= msg.size())
    {
        c = msg[i];
        if (dic.find(w + c) != dic.end())
            w = w + c;
        else
        {
            answer.push_back(dic.find(w)->second);
            dic.emplace(w + c, cnt++);
            w = c;
        }
        i++;
    }
    return answer;
}
