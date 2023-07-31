#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*
입력 : 주차 요금 정보 fees, 자동차의 입/출차 내역을 담은 문자열 배열 records
출력 : 각 차량별로 지불해야 할 주차 요금
*/

int computeTimeOfUse(string ot, string it) {
    int hourDiff = stoi(ot.substr(0, 2)) - stoi(it.substr(0, 2));
    int minuteDiff = stoi(ot.substr(3, 2)) - stoi(it.substr(3, 2));
    
    return abs(hourDiff * 60 + minuteDiff);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> getIn; // 각 차량의 입차 시간을 담은 map
    map<string, int> timeOfUse; // 각 차량의 주차 이용 시간을 담은 map (자동차 번호, 주차 이용 시간)
    
    // 입출차 내역을 순회하며 입차 시간과 주차 이용 시간을 계산
    for (string record: records) {
        stringstream ss(record);
        string time, carNumber, info;

        // 문자열 record 읽어서 각각의 정보 저장
        ss >> time >> carNumber >> info;
        
        // 입차 내역인 경우
        if (info == "IN") getIn[carNumber].push_back(time);
        else {
            string in_time = getIn[carNumber].back();
            getIn[carNumber].pop_back();
            int time_of_use = computeTimeOfUse(time, in_time);
            timeOfUse[carNumber] += time_of_use;
        }
    }
    
    // 출차 내역이 없는 경우, 출차 시간은 23:59
    for (auto it: getIn) {
        if (!getIn[it.first].empty()) timeOfUse[it.first] += computeTimeOfUse("23:59", getIn[it.first].back());
    }
    
    // 계산된 주차 요금 answer 벡터에 저장
    for (auto it: timeOfUse) {
        if (timeOfUse[it.first] <= fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + ceil((double)(timeOfUse[it.first] - fees[0]) / fees[2]) * fees[3]);
    }
    
    return answer;
}
