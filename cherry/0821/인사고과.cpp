#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
<문제설명>
입력 : [근무태도점수, 동료평가점수] scores (첫번째꺼가 원호꺼)
출력 : 완호의 석차 (완호가 인센티브를 받지 못하는 경우 -1을 return)
내용
- 어떤 사원의 점수가 다른 임의의 사원보다 두 점수가 모두 낮은 경우가 있다면 인센티브를 받을 수 없음
- 두 점수의 합이 높은 순으로 석차를 내어 석차에 따라 인센티브 차등 지급
- 점수 합이 동일한 경우, 동일한 사원은 동석차
- 동석차의 수 만큼 다음 석차는 건너뜀 

*/

// 점수 "내림차순" 정렬
bool comp (vector<int> v1, vector<int> v2){
    return (v1[0]+v1[1]) > (v2[0]+v2[1]);
}

int solution(vector<vector<int>> scores) {
    int rank = 1;
    int wanho_score = scores[0][0] + scores[0][1];
    

    // 완호 이외의 사원 정렬
    sort(scores.begin()+1, scores.end(), comp);
    
    /* 
    auto comp = [](vector<int> v1, vector<int> v2){
        return (v1[0]+v1[1]) > (v2[0]+v2[1]);
    };
    */

    // 완호 rank 구하기
    for(int i = 1; i < scores.size(); ++i){
      
        // 완호가 인센티브를 못 받는 경우
        if(scores[0][0] < scores[i][0] 
          && scores[0][1] < scores[i][1])
            return -1;
        
        int other_score = scores[i][0] + scores[i][1];
        if(wanho_score < other_score)
            ++rank;
        else break;
    }
    
    // 완호보다 앞 선 사람들 중 인센티브를 받지 못하는 사람 빼기
    int wanho = rank;
    for(int pivot = 2; pivot < wanho; ++pivot){
        for(int cmp = 1; cmp < pivot; ++cmp){        
            
          if(scores[pivot][0] < scores[cmp][0] 
               && scores[pivot][1] < scores[cmp][1]){
                --rank;
                break;
            }
        }
    } 
    return rank;
}


