#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string,vector<int>> um;
vector<int> answer, score;

void makeCombi(string info){
    int num;
    stringstream ss(info);
    string tmpInfo[4][2]={{"-"},{"-"},{"-"},{"-"}};
    for(int i = 0; i < 4; i++) ss >> tmpInfo[i][1];
    ss >> num;
    score.push_back(num);
    
    for(int i = 0; i < 2; i++) { //-와 문자열 섞어서 16가지조합 만들기
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    string key = tmpInfo[0][i] + tmpInfo[1][j] + tmpInfo[2][k] + tmpInfo[3][l];  
                    um[key].push_back(num);
                }
            }
        }
    }
}

void findPeople(string info){
    stringstream ss(info);
    string tmpInfo[8], key = "";
    
    for(int i = 0; i < 8; i++) ss >> tmpInfo[i]; 
    for(int i = 0; i < 8; i += 2) {
        if(tmpInfo[i] != "-") key += tmpInfo[i]; //-가 아니면 key에 그대로 넣기
        else key += "-"; //key에 -넣기
    }
    
    //lower_bound : 찾으려는 key값보다 같거나 큰 숫자가 배열 몇번째에서 처음 등장하는지
    int idx = lower_bound(um[key].begin(), um[key].end(), (int)stoi(tmpInfo[7])) - um[key].begin();
    answer.push_back(um[key].size() - idx); //idx뒤에있는 애들은 다 (int)stoi(tmpInfo[7]보다 큰 것이기 때문에
}

vector<int> solution(vector<string> info, vector<string> query) {
   for(auto str:info){
       makeCombi(str); //info로 가능한 모든 조합 만들기
      
   }
    
   for(auto iter = um.begin(); iter != um.end(); iter++) {
        sort(iter->second.begin(), iter->second.end()); //점수로 오름차순 sort
    } 
    
    for(auto str:query){
        findPeople(str);
    }
    
    return answer;
}
