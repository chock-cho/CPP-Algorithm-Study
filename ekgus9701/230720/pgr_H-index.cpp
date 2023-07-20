#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = 0 ; i < citations.size(); i++)
    {
        int H_Index = citations.size() - i; // 현재 논문부터 마지막까지의 논문 개수
        if(citations[i] >= H_Index) //현재 논문의 인용된 횟수보다 H_Index가 작거나 같으면
            return H_Index;
    }
    return answer;
}
