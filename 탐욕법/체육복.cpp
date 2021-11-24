#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    
    for (int i = 0; i < n + 2; i++) student.push_back(1);
    for (const auto& i : lost) student[i]--;
    for (const auto& i : reserve) student[i]++;
    
    for (int i = 1; i <= n; i++) {
        if (student[i] == 2 && student[i - 1] == 0) student[i] = student[i - 1] = 1;
        else if (student[i] == 2 && student[i + 1] == 0) student[i] = student[i + 1] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (student[i] > 0) answer++;
    }
    
    return answer;
}
