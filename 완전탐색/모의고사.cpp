#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int per1[5] = {1, 2, 3, 4, 5};
    int per2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int per3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int person[3] = {0, 0, 0};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == per1[i % 5]) person[0]++;
        if (answers[i] == per2[i % 8]) person[1]++;
        if (answers[i] == per3[i % 10]) person[2]++;
    }
    
    int m = max(person[0], person[1]);
    m = max(m, person[2]);
    
    for (int i = 0; i < 3; i++) {
        if (m == person[i]) answer.push_back(i + 1);
    }
    
    
    return answer;
}
