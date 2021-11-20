#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    int num = 1, temp;
    
    for (int i = 0; i < progresses.size(); i++) {
        temp = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) temp++;
        time.push_back(temp);
    }
    
    temp = time[0];
    for (int i = 1; i < progresses.size(); i++) {
        if (temp >= time[i]) num++;
        else {
            answer.push_back(num);
            num = 1;
            temp = time[i];
        }
    }
    answer.push_back(num);
    
    return answer;
}
