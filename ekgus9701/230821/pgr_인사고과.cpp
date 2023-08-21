#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<vector<int>> scores) {
    int answer = 1;
    int score = scores[0][0] + scores[0][1];
    
    // 점수 내림차순 정렬
    auto comp = [](vector<int> v1, vector<int> v2) 
    {
        return (v1[0]+v1[1]) > (v2[0]+v2[1]);
    };
    
    sort(scores.begin()+1, scores.end(), comp);
    
    // 완호 위치 구하기
    for(int i = 1; i < scores.size(); ++i)
    {
        // 완호가 인센티브를 못 받는 경우
        if(scores[0][0] < scores[i][0]&& scores[0][1] < scores[i][1])
            return -1;
        
        int other_score = scores[i][0] + scores[i][1];
        if(score < other_score) //완호보다 다른 사람 점수가 더 높다면
            ++answer;
        else break;
    }
    
    // 완호보다 앞 선 사람들 중 인센티브를 받지 못하는 사람 빼기
    int wanho = answer;
    for(int c = 2; c < wanho; ++c)
    {
        for(int p = 1; p < c; ++p)
        {        
            if(scores[c][0] < scores[p][0]&& scores[c][1] < scores[p][1])
            {
                --answer;
                break;
            }
        }
    }
    
    return answer;
}
