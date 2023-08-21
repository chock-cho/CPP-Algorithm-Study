#include <string>
#include <vector>

using namespace std;

/*
<문제설명>
입력: 정수수열 sequence
내용: 연속부분수열에 같은 길이의 펄스수열(-1,1이 번갈아 나오는 수열)을 각 원소끼리 곱하여 연속 펄스 부분 수열 만들기
출력: 연속 펄스 부분 수열의 합 중 가장 큰 것을 return 

3중 반복문 안됨. 부분 누적합 -> dynamic programming으로 풀어야 함 
" 큰 문제를 작은 문제로 쪼개서 그 답을 저장해두고 재활용 "
*/


long long solution(vector<int> sequence) {
    long long answer = -999999999;
    int length = sequence.size(); 
    vector<long long> seq_plus(length); // 1로 시작
    vector<long long> seq_minus(length); // -1로 시작

    
    int mul=1; // 곱하기 연산자

    // 1 & -1로 시작하는 seq 구성
    for(int i=0;i<length;i++){
        seq_plus[i]=sequence[i]*mul;
        mul*=(-1);
        seq_minus[i]=sequence[i]*mul;
    }

    // 수열 길이 1이면 dp 없이 1,-1 적용 후 반환
    if(length==1){
        answer = max(seq_plus[0],seq_minus[0]);
        return answer;
    }

    // dp 배열 선언
    long long dp_plus[length]; long long dp_minus[length];

    // 첫번째 원소 초기화
    dp_plus[0] = seq_plus[0]; 
    dp_minus[0] = seq_minus[0];
    
    /*dp 적용*/  

    // 1, -1 로 시작
    for(int i=1;i<length;i++){
        
        dp_plus[i] = max(dp_plus[i-1]+seq_plus[i],seq_plus[i]);
        dp_minus[i] = max(dp_minus[i-1]+seq_minus[i],seq_minus[i]);

        long long temp = max(dp_minus[i],dp_plus[i]);
        answer = max(answer,temp);
    }
    
    return answer;
}
