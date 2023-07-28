#include <string>
#include <vector>
#include <set>
#include <iostream>


using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    
    set<int> s;
    
    int size= elements.size();
    
    for(int i=1; i<=size;i++){ // i : 선택하는 원소의 크기
        
        for(int j=0;j<size;j++){ // j : 덧셈의 시작점
            
            int sum =0;
            for(int k=j;k<j+i;k++){ // j 부터 i 개 만큼 더함 
                sum+=elements[k % size];              
            }
            s.insert(sum);
         
        }
        
    }
    return s.size();
}