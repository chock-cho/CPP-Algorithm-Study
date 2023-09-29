1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
typedef pair<int,int> pi;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> cost(n+1, -1);
    vector<int> adj[MAX];

    for(auto r: roads){
        adj[r[0]].push_back(r[1]);
        adj[r[1]].push_back(r[0]);
    }

    queue<pi> q;    // 페어 큐 선언
    q.push({destination, 0}); // 시작점 선언
    cost[destination] = 0; 

    while(!q.empty()){
        pi t = q.front();
        int curNode = t.first;
        int curCost = t.second;
        q.pop();

        for(auto nxtNode : adj[curNode]) {
            if(cost[nxtNode] == -1 || cost[nxtNode] > curCost + 1){
                q.push({nxtNode, curCost + 1});
                cost[nxtNode] = curCost + 1;
            }
        }
    }
    for(auto x : sources){
        answer.push_back(cost[x]);
    }
    return answer;
}
