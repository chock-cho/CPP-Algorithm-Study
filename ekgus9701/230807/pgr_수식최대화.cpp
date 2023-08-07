#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(long long a, long long b, char oper)
{
    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else if (oper == '*')
        return a * b;
}

long long solution(string expression)
{
    long long max = 0;
    vector<char> oper_list = {'*', '+', '-'}; //연산자 우선순위
    vector<long long> numbers;                //숫자
    vector<char> opers;                       //연산자
    string number = "";

    //연산자와 숫자를 구분하여 vector에 담음
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-')
        {
            opers.push_back(expression[i]); 
            numbers.push_back(stoi(number)); //숫자 push
            number = ""; //다시 초기화
        }
        else
            number += expression[i]; //30같은 경우는 3과 0을 연결해줌
    }
    numbers.push_back(stoi(number)); //마지막 연산자 이후의 숫자를 넣어주기 위해

    //순열을 이용하여 각 연산자를 우선순위에 따라 계산
    do
    {
        vector<long long> tmp_nums = numbers; //복사
        vector<char> tmp_oper = opers;        //복사
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < tmp_oper.size(); j++)
            {
                if (tmp_oper[j] == oper_list[i])
                {
                    tmp_nums[j] = calc(tmp_nums[j], tmp_nums[j + 1], oper_list[i]);
                    tmp_nums.erase(tmp_nums.begin() + j + 1);
                    tmp_oper.erase(tmp_oper.begin() + j);
                    j--;
                }
            }
        }
        //max 값을 연산자 우선순위에 따라 변경될 때마다 바꿔줌
        if (abs(tmp_nums.front()) > max)
            max = abs(tmp_nums.front()); //max 값 변경
    } while (next_permutation(oper_list.begin(), oper_list.end()));

    return max;
}
