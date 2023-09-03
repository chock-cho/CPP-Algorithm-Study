#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TREE{
    int Idx;
    int x;
    int y;
    TREE *Left;
    TREE *Right;
};

bool Cmp(TREE A, TREE B)
{
    if (A.y >= B.y) //y좌표가 큰 순서 대로 정렬
    {
        if (A.y == B.y)
        {
            if (A.x < B.x) //x좌표가 큰 순서대로 정렬
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void Make_Binary_Tree(TREE *Root, TREE* Child)
{
    if (Root->x > Child->x) //루트의 x가 child의 x보다 크다면
    {
        if (Root->Left == NULL)
        {
            Root->Left = Child; //root의 left에 child 넣기
            return;
        }
        Make_Binary_Tree(Root->Left, Child);
    }
    else //오른쪽에 넣기
    {
        if (Root->Right == NULL)
        {
            Root->Right = Child;
            return;
        }
        Make_Binary_Tree(Root->Right, Child);
    }
}
 //전위 (위->좌->우)
void PreOrder(TREE *Root, vector<int> &answer)
{
    if (Root == NULL) return;
    answer.push_back(Root->Idx);
    PreOrder(Root->Left, answer);
    PreOrder(Root->Right, answer);
}
 //후위
void PostOrder(TREE *Root, vector<int> &answer)
{
    if (Root == NULL) return;
    PostOrder(Root->Left, answer);
    PostOrder(Root->Right, answer);
    answer.push_back(Root->Idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<TREE> Tree;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int Idx = i + 1;
        Tree.push_back({ Idx, x, y, NULL, NULL });
    }
    sort(Tree.begin(), Tree.end(), Cmp);
    TREE *Root = &Tree[0]; //루트 지정
    for (int i = 1; i < Tree.size(); i++) //이진트리 만들기
        Make_Binary_Tree(Root, &Tree[i]);
    
    vector<int> Pre_V; 
    PreOrder(Root, Pre_V);
    
    vector<int> Post_V;    
    PostOrder(Root, Post_V);
    
    answer.push_back(Pre_V);
    answer.push_back(Post_V);
    
    return answer;
}
