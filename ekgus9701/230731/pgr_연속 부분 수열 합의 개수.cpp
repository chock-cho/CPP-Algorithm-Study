#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> ans;
    int save=0,temp;
    
    for(int i=0;i<elements.size();i++){
        for(int j=0;j<elements.size();j++){
            save+=elements[j]; //save라는 변수에 각 원소 더하기
            ans.push_back(save); //ans 벡터에 save를 그때그때 저장
            
            // -> 1 저장 1+9 저장 1+9+7 저장 ... 이런 식으로
        }
        save=0;
        
        //가장 앞 원소 삭제 후 맨 뒤에 넣어주기
        temp=elements[0];
        elements.erase(elements.begin()); 
        elements.push_back(temp);

    }
    
   //중복 원소 제거
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    
    answer=ans.size();
    return answer;
}
