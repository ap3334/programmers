#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> people;

    for (const auto& i : participant) people[i]++;

    for (const auto& i : completion) people[i]--;

    for (const auto& i : people) {
        if (i.second == 1) answer = i.first;
    }

    return answer;
}
