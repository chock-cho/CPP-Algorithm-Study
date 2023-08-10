#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    //행렬의 크기 -> arr1의 행, arr2의 열의 크기
    for(int i=0;i<arr1.size();i++){ //행 만들기
        vector<int> v;
        for(int j=0;j<arr2[0].size();j++){ //열 만들기
            int sum=0;
            for(int k=0;k<arr1[0].size();k++){ //계산
                sum+=arr1[i][k]*arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    
    
    return answer;
}
