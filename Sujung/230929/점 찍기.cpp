// 점 찍기. cpp
        // 원점으로부터의 최대거리 l := x^2 + y^2 = l^2
        // 주어진 값 : l, x를 for문으로 증가시켜주면 y는 해당 식의 값으로 나옴.
        //  x의 최대 := y좌표가 0일때, y의 최대 := x 좌표가 0일때
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll getY(int &l, int &x){
    // y좌표 구하기
    return sqrt((ll)l*l-(ll)x*x);
}

ll solution(int k, int l) {
    ll answer = 0;
    for(int i = 0; i <= l; i += k){ // scale : k
        answer += floor(getY(l, i)/k)+1;
    }
    return answer;
}
