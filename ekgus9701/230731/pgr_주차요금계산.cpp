#include <string>
#include <vector>
#include<cmath>
#include<map>
#include<sstream>

using namespace std;

int cal_time(string in, string out){
    int h1=stoi(in.substr(0,2));
    int m1=stoi(in.substr(3,2));
    
    int h2=stoi(out.substr(0,2));
    int m2=stoi(out.substr(3,2));
    
    int diff=(h2-h1)*60+m2-m1; //시간 계산
    
    return diff;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m; //차량번호가 작은 자동차부터 배열에 담아야해서 map 사용
    
    stringstream ss;
    
    for(auto record: records){
        ss.str(record); //stringstream의 값을 record 로 바꿈
        
        string time, cnum, inout;
        ss>>time>>cnum>>inout;
        
        m[cnum].push_back(time);
        ss.clear();
    }
    
    for(auto iter: m){
        if(iter.second.size()%2!=0){ //in,out의 총 개수가 홀수라면 -> out이 없는거니까 
            iter.second.push_back("23:59");
        }
        
        vector<string> info = iter.second;
        int total=0;
        
         for(int i=0; i<info.size()-1; i+=2) {
            total += cal_time(info[i], info[i+1]);
        }
        
        int price=fees[1];
        
        if(total>fees[0]){ //기본시간보다 오래있었으면 
            price+=ceil((total-fees[0])/(double)fees[2])*fees[3];
        }
        
        answer.push_back(price);
    }
    return answer;
    
}
