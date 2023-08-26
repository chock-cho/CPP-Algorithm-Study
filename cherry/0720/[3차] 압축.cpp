#include <string>
#include <vector>
#include <map>

using namespace std;
/*
<문제설명>
LZW 압축
1. 길이가 1인 모든 단어 포함하도록 사전 초기화
2. 사전에서 현재 입력과 일치하는 "가장 긴 문자열 W" 찾기
3. W에 해당하는 사전의 색인번호 출력, 입력에서 W 제거
4. 입력에서 처리되지 않은 다음 글자 남아있음(C) -> W+C에 해당하는 단어 사전에 등록
5. 단계2로 돌아감
*/

// 문자열 데이터 -> int 형으로 매핑 ; map 자료구조 사용
int Num = 1;
map<string, int> Dict;
 
void Make_Default_Dictionary()
{
	for (char C = 'A'; C <= 'Z'; C++){
		string Str = ""; Str += C;
		Dict[Str] = Num++;
	}
}

// 압축하기
void Compression(string str, vector<int> &answer)
{
	string cur = "";
	for (int i = 0; i < str.length(); i++){
		
        cur += str[i];
        
		if (Dict[cur] == 0){
			Dict[cur] = Num++;
			cur = cur.substr(0, cur.length() - 1);
			answer.push_back(Dict[cur]);
			cur = "";
			i--;
		}
	}
	answer.push_back(Dict[cur]);
}

vector<int> solution(string msg) {
    vector<int> answer;
    Make_Default_Dictionary();
    Compression(msg, answer);
    return answer;
}
