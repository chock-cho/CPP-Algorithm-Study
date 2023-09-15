#include <string>
#include <vector>

using namespace std;

/*
<문제설명>
입력 : 집합의 원소의 개수 n, 모든 원소들의 합 sum 
출력 : 최고의 집합을 return -> 오름차순으로 정렬된 1차원 vector (존재하지 않으면 -1)

내용
- 자연수 n개로 이루어진 중복집합 중에 다음 두 조건을 만족하면 최고의 집합이라 칭함
1. 각 원소의 합이 S가 되는 수의 집합
2. 위 조건을 만족하면서 각 원소의 곱이 최대가 되는 집합

예시
{1.8} {2,7} {3,6} {4,5}
-> 각 원소의 곱이 최대인 것은 {4,5} (최고의 집합)
*/

vector<int> solution(int n, int sum) {

    // 집합을 만들 수 없는 경우
    if(n>sum) return {-1};

    /*원소 간의 차이가 최소가 될 때 곱이 최대가 됨*/

    // sum/n 값의 원소로 채워진 집합 생성
    vector<int> answer (n,sum/n);

    for(int idx = sum%n;idx>0;idx--) answer[n-idx]++;

    return answer;
}
