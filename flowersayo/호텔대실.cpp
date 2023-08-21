#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int convertTime(const string s)
{
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3));
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int,int>> timeTable;

    for(const auto& v : book_time)
    {
        timeTable.emplace_back(convertTime(v[0]),1);
        timeTable.emplace_back(convertTime(v[1]) + 10,-1);
    }
    sort(timeTable.begin(),timeTable.end()); // 시작시간이 빠른 순서대로 정렬 

    int cur = 0;
    for(const auto& v : timeTable)
    {
        cur += v.second;
        answer = max(answer,cur);
    }

    return answer;
}