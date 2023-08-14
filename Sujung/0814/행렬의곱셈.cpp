#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 행렬의 곱셈
    // 행렬 m1 m2를 곱할 때, n1 by m1 * n2 by m2 := n1 by m2 의 행렬의 값이 나온다는 점을 착안
        int arr1_row= arr1.size();
    int arr1_col = arr1[0].size();
    int arr2_row = arr2.size();
    int arr2_col = arr2[0].size();
    
    vector<vector<int>> answer(arr1_row, vector<int>(arr2_col, 0));
    //assert that arr1_col=arr2_row
    for(int i =0 ; i< arr1_row; i++){
        for(int j = 0; j < arr2_col; j++){
            for(int k = 0; k < arr2_row; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];   
            }
        }
    }
    return answer;
}
