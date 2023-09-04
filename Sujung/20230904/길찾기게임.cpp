/*  이진트리를 만들고, 순회하는 문제   */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int x, y; // NodeInfo 노드들의 좌표가 담겨있음(x,y)
    Node *left;
    Node *right;
};

/* 커스텀 정렬 */ 
bool cmp(Node A, Node B){
    // y좌표가 큰 순서대로 먼저 정렬해주어야
    if(A.y == B.y){
        return A.x < B.x;   // y좌표 같다면, 
                            // x좌표 작은 순서대로 먼저 정렬
    }
    else {
        return A.y > B.y;
    }
}

void setBinaryTree(Node *Parent, Node *node){
    if(Parent->x > node->x){
        // 부모 노드의 x가 자식 노드의 x보다 크면, 해당 노드는 부모노드의 left에 위치하여야 한다.
        if(Parent->left == NULL){ // 비어있으면 Parent 노드의 좌측에 삽입
            Parent->left = node; // node 삽입 연산
            return;
        }
        // 이미 다른 노드가 위치해있다면 그 노드를 부모로 삼아 그 기준으로 BinaryTree를 재귀호출해준다.
        setBinaryTree(Parent->left, node);
    }
    else {
        if(Parent->right == NULL){
            Parent->right = node;
            return;
        }
        setBinaryTree(Parent->right, node);
    }
}

// 전위순회 진행
// 순서: (루트->왼->오)
void preOrder(Node *root, vector<int> &answer){
    answer.push_back(root->data);
    if(root->left != NULL){
        preOrder(root->left, answer);
    }
    if(root->right!= NULL){
        preOrder(root->right, answer);
    }
}
// 후위순회 진행
// 순서: (왼->오->루트)
void postOrder(Node *root, vector<int> &answer){
    if(root->left != NULL){
        postOrder(root->left, answer);
    }
    if(root->right != NULL){
        postOrder(root->right, answer);
    }
    answer.push_back(root->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node> TREE;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int data = i + 1;
        TREE.push_back({data, x, y, NULL, NULL});
    }
    sort(TREE.begin(), TREE.end(), cmp);    // 커스텀 정렬
    
    Node *root = &TREE[0];
    for(int i = 1; i < TREE.size(); i++)
    {
        setBinaryTree(root, &TREE[i]);
    }
    vector<int> v1;
    preOrder(root, v1);
    
    vector<int> v2;
    postOrder(root, v2);
    
    answer.push_back(v1);
    answer.push_back(v2);
    return answer;
}
