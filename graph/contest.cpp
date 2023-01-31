#include <iostream>
#include <string>

int levenshteinDistance(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + std::min(dp[i][j - 1],
                                       std::min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m][n];
}

std::string findOriginalWord(std::string message) {
    int n = message.length();
    int m = n / 3;
    std::string originalWord = message.substr(0, m);
    int minDistance = levenshteinDistance(originalWord, message.substr(m, m));

    for (int i = 1; i <= 2; i++) {
        std::string temp = message.substr(i*m, m);
        int distance = levenshteinDistance(temp, message.substr(0, m));
        if (distance < minDistance) {
            minDistance = distance;
            originalWord = temp;
        }
    }
    return originalWord;
}

int main() {
    std::string message ;
    std::cin>>message;
    std::cout << findOriginalWord(message) << std::endl;
    return 0;
}
