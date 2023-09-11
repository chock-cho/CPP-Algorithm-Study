#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int cnt=0;
    int mok=storey,namoji;
    
    while(true){
        if(mok<=0) break; 
        namoji=mok%10;
        
        mok/=10; // 뒤에서 써야해서 몫을 미리 나눠놓음
        
        //나머지가 5미만, 5일때, 5초과일때로 경우를 나눔 
        
        if(namoji<5){ 
            cnt+=namoji; //나머지번만큼 가면 되기 때문에 나머지를 cnt에 더한다.
            
        }
        
        else if(namoji==5){
           
            if(mok%10>=5){ //앞이 자리수가 5보다 크다면 5를 더해주는게 나음
                cnt+=10-namoji;
                mok+=1;
            }
           
            else{ 
                cnt+=namoji;
            }
        }
        
        else{//5보다 크면 
            cnt+=10-namoji; 
            mok+=1; //앞자리수 1개를 올려줌
        }
        
    }
    return cnt;
}
