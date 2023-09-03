#include <string>
#include <vector>

using namespace std;
int emo_plus=0;
int price=0;

int percent[4]={10,20,30,40};

vector<int> v;

void solve(vector<vector<int>> users, vector<int> emoticons){
    
    int plus_tmp=0;
    int price_tmp=0;
    
    
    if(v.size()==emoticons.size()){ //이모티콘 개수만큼 할인율이 들어있다면
        for(int i=0;i<users.size();i++){
            
            int a=0;
            for(int j=0;j<emoticons.size();j++){ 
                if(users[i][0]<=v[j]){
                    a += emoticons[j] * (100-v[j]) / 100; //총 금액 계산
                }
            }
            
            if(a>=users[i][1]){ //이모티콘 플러스 서비스 가입
                plus_tmp++;
            }
            else{ //이모티콘 구매에 사용하는 돈 업데이트
                price_tmp+=a;
            }
        }
        
        if(emo_plus<plus_tmp){ //이모티콘 플러스 가입이 전에 계산했던 거보다 더 많으면 업데이트
            emo_plus=plus_tmp;
            price=price_tmp;
        }
        
        else if(emo_plus == plus_tmp && price < price_tmp) { // 이모티콘 구매에 사용한ㄴ 돈이 더 많다면 업데잍
            price = price_tmp;
        }
        return;
    }
    
    for(int i=0;i<4;i++){ //10,20,30,40 섞으면서 넣어줄 수 있도록
        v.push_back(percent[i]);
        solve(users,emoticons);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    solve(users,emoticons);
    
    answer.push_back(emo_plus);
    answer.push_back(price);
    return answer;
}
