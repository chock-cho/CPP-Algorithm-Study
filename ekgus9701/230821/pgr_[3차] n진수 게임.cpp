#include <string>
#include <vector>

using namespace std;
string convert_num(int num, int n){ //n진수로 변환
    char code[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string tmp = "";
    while(num/n!=0){
        tmp = code[num%n] + tmp;
        num = num/n; 
    }
    tmp = code[num%n]+tmp;
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int chk=0;
    string tmp="";
    for(int i=0;i<m*t;i++){ //게임에 참가하는 인원 *미리 구할 숫자의 갯수까지 미리 구해두기
        tmp+=convert_num(i,n);
    }
    
    for(int i=p-1;i<tmp.size();i+=m){
        if(chk<t) //말해야하는 숫자의 개수보다 적게 말했다면
            answer+=tmp[i];
        
        chk++;
    }
    return answer;
}
