/* K closet Points to Origin - 정렬을 커스텀하여 우선순위 큐 STL을 이용하여 푸는 문제였습니다. */
class distanceCmp {
    // 커스텀 정렬 클래스 생성
public:
    bool operator() (vector<int>& a, vector<int>& b){
        return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, distanceCmp> pq; // 커스텀 정렬 기준 최소 히프 생성
        for(auto p: points) {
            pq.push(p);
        }

        vector<vector<int>> ret;
        while(!pq.empty() && k != 0){
            ret.push_back(pq.top());
            pq.pop();
            k--;
        }
        return ret;
    }
};
