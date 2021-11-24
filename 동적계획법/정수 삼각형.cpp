#include <string>
#include <vector>

using namespace std;

long long dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int i, j;
    
    for (int a = 0; a < triangle.size(); a++) {
        i = a + 1;
        j = 1;
        for (int e = 0; e < triangle[a].size(); e++) {
            dp[i][j] = triangle[a][e];
            if (j != triangle[a].size()){
                i--;
                j++;
            }
        }
        i++;
    }
    
    for (int i = 1; i <= triangle.size(); i++) {
        for (int j = 1; j <= triangle.size() - i + 1; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) dp[i][j] += dp[i - 1][j];
            else dp[i][j] += dp[i][j - 1];
            if (j == triangle.size() - i + 1) {
                if (dp[i][j] > answer) answer = dp[i][j];
            }
        }
    }
    
    return answer;
}
