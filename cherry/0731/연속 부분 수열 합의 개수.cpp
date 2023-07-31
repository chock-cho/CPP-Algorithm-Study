#include <string>
#include <vector>
#include <set>

using namespace std;

/*
입력 : 원형 수열의 원소 elements   
출력 : 원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수
*/

int solution(vector<int> elements) {
    
    vector<int> v = elements; 
    set<int> s(elements.begin(),elements.end()); // 길이가 1인 연속부분수열은 계산됨

    // 수열 회전
    for(int i=1;i<v.size();i++){ 
        
        // i번째 원소부터 시작하는 연속 부분 수열 합 구하기
        for(int j=0;j<v.size();j++){ 

            // v[j]에는 elements[j]부터 elements[j+i]까지의 합이 저장됨
            v[j] += elements[(j+i)%v.size()];
            s.insert(v[j]);
        }
    }

    return s.size();
}
