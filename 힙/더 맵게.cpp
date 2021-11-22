#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int s1, s2;
    priority_queue<int, vector<int>, greater<int>> m;

    for (const auto& i : scoville) m.push(i);
    
    while (m.top() < K) {
        s1 = m.top();
        m.pop();
        if (m.empty()) return -1;
        s2 = m.top();
        m.pop();
        m.push(s1 + s2 * 2);
        answer++;
    }
    
    return answer;
}
