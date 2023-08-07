#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> answer;
    int N = elements.size()*2-1;
    vector<int> element(N, 0); // 원형 수열을 구현할 배열 생성
    for(int i = 0; i < N; i++){
        if(i < elements.size()) {
            element[i] = elements[i];
        }
        else {
            element[i] = elements[i-elements.size()];
        }
    }
    // 구간합 psum배열 생성
    vector<int> psum(N, 0);
    psum[0] = element[0];
    for(int i = 1; i < N; i++){
        psum[i] = psum[i-1]+element[i];
    }
    // 길이가 [1, elements.size()]인 구간합 배열의 값 
   for(int i = 1; i <= elements.size(); i++){
       
       for(int x = 1; x < element.size(); x++){
           for(int y = 1; y < element.size(); y++){
               if(i == y - x + 2){
                   answer.insert(psum[y]-psum[x-1]);
                   // 길이 2이면 psum[1]-psum[0] y-x+1, psum[2]-psum[1] 
               }
           }
       }
       
   }
   return answer.size();
}
