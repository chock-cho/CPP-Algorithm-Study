#include <string>
#include <vector>
 
using namespace std;
 
int arr[110][110];
 
int min_def(int A, int B) { return A < B ? A : B; }
 
 
int Rotate(int x, int y, int xx, int yy)
{
    int min_num;
    int tmp = arr[x][y];
    min_num = tmp;
    for (int i = x; i < xx; i++) //왼쪽 상하 이동
    {
        min_num = min_def(min_num, arr[i][y]);
        arr[i][y] = arr[i + 1][y];
    }
    for (int i = y; i < yy; i++) //아래쪽 좌우 이동
    {
        min_num = min_def(min_num, arr[xx][i]);
        arr[xx][i] = arr[xx][i + 1];
    }
    for (int i = xx; i > x; i--) //오른쪽 상하 이동
    {
        min_num = min_def(min_num, arr[i][yy]);
        arr[i][yy] = arr[i - 1][yy];
    }
    for (int i = yy; i > y; i--) //위쪽 좌우 이동
    {
        min_num = min_def(min_num, arr[x][i]);
        arr[x][i] = arr[x][i - 1];
    }
    arr[x][y + 1] = tmp;
    return min_num;
}
 
vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    int Num = 1;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = Num++;
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0]-1;
        int y = queries[i][1]-1; 
        int xx = queries[i][2]-1; 
        int yy = queries[i][3]-1;
 
        answer.push_back(Rotate(x, y, xx, yy));
    }
    
    return answer;
}
