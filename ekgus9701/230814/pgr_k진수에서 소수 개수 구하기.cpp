#include <string>
#include <vector>
#include<iostream>
#include<math.h>

using namespace std;

int answer = 0;

string change(int n,int k){ //k진수로 변환
	string bn = "";
    
    for(int i = n; i > 0; ){
    	bn = to_string(i % k) + bn;
        i /= k;
    }
    
    return bn;
}

void sosu(string s){ 

    bool check=true; //소수인지
    long long a;
    a=stoll(s); //string ll형으로 변환
    
    if(a==1){ //1은 소수가 아니니까
        return;
    }

	for (int i = 2; i <= sqrt(a); i++) {//2~a의 제곱근까지
		if (a%i == 0) {//i가 a의 약수라면 소수가 아니므로
			check=false;
		}
	}

    if(check==true){ //소수인 경우
        answer++;
    
    }
    return;
 
}

int solution(int n, int k) {

    string num=change(n,k); //k진수로 변환
    int pt=0;
    
    if(num.find('0')==string::npos){ //0이 없다면
        sosu(num); //바로 소수인지 판별
    }
    
    else{
        string chk;
        while(true){
            if(pt==num.length()){ 
                if(num[pt-1]!='0'){ //마지막이 0이 아니면
                    sosu(chk);
                }
                break;
            }

            if(num[pt]!='0'){ //수가 0이 아니면
                chk+=num[pt]; //수 합쳐주기
            }
            else{ //수가 0이면
                
                if(chk.size()>0){ 
                    sosu(chk); //앞에서 합친 수 소수 판별
                    chk="";
                }
            }
            pt++;
        }
    }
    
    return answer;
}
