#include <string>
#include <vector>


using namespace std;

/*
입력 : 직사각형 가로의 길이 n (세로의 길이는 3)
출력 : 2x1로 3xn 크기의 직사각형을 채우는 방법의 수
*/

// 항상 짝수개의 길이로만 직사각형을 채울 수 있음
int solution(int n) {
    
    long arr[2501] = {0,};

    arr[0] = 1; // 곱하기 계산을 위한 1
    arr[1] = 3; // 길이 2의 직사각형을 채울수 있는 경우의 수 3
    

    for(int i=2; i<=n/2; i++){  // 길이 4부터 n까지 계산 -> 길이 2를 1로 치환 

        // 가로 길이가 i인 직사각형을 채우는 경우의 수
        for(int j=1; j<=i; j++){ 
            if(j==1){
                arr[i] += 3*arr[i-j]; // 1개+ (i-j그룹 조합) -> 3X(i-j그룹 조합의 경우의 수)
            }
            else{ 
                arr[i] += 2*arr[i-j]; // 1개 이상+ (i-j그룹 조합) -> 2X(i-j그룹 조합의 경우의 수)
            } 
        }
        arr[i] %=1000000007;
    }

    return arr[n/2];
}
