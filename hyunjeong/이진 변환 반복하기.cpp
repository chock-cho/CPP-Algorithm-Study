#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int a1 = 0;
    int a2 = 0;
    string news = "";
    int conv;
    while(s!="1") {
        news = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] == '0') {
                a2 += 1;
            }else {
                news += s[i];
            }
        }
        conv = news.length();
        a1 += 1;
        if(news == "1") {
            break;
        }else {
            s = "";
            while(conv!=0){
                string ne;
                ne = to_string(conv%2);
                conv /=2;
                s = ne + s;
            }
        }
        
    }
    answer.push_back(a1);
    answer.push_back(a2);
    return answer;
}
