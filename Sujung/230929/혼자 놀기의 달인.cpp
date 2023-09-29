// 혼자 놀기의 달인.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;

int group[MAX] {0};
int groupCnt = 0;

void DFS(vector<int>& cards, int idx, int groupId){
    groupCnt++;  // 그룹 갯수 세어주기
    group[idx] = groupId;  
    
    if(group[cards[idx] - 1] == 0){
        DFS(cards, cards[idx] - 1, groupId);
    }
}

int solution(vector<int> cards) {
    int groupId = 0;
    
    vector<int> v;  // 그룹 인원 정보를 저장하고 있는 벡터 선언
    
    for(int i = 0; i < cards.size(); i++){
        if(group[i] == 0){
            groupCnt = 0;            // 그룹 갯수
            groupId++;               
            DFS(cards, i, groupId);  // group 화 DFS 진행
            v.push_back(groupCnt);  // 그룹 인원에 해당하는 값 벡터에 밀어넣기
        }
    }
    
    sort(v.begin(), v.end(), greater<>());  // 내림차순 정렬
    
    if(groupId == 1){
      // 그룹이 한 개라면 0 리턴
        return 0;
    }
    else {
      // 그룹이 2개 이상이라면 가장 인원 수가 많은 두 그룹끼리의 곱 리턴
        return v[0] * v[1];
    }
}
