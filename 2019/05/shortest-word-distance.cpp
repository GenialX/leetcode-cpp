#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int first = -1, second = -1, ans = INT_MAX;
        unordered_set<string> ws{word1, word2};
        for (unsigned int i = 0; i < words.size(); ++i) {
            if (first == -1) {
                if (ws.find(words[i]) != ws.end()) {
                    first = i;
                    second = i;
                }
            } else if (ws.find(words[i]) == ws.end()) {
                ++second;
                continue;
            } else if (words[i] == words[first]) {
                first = i;
                second = i;
            } else{
                second = i;
                ans = min(ans, second - first);
                first = i;
            }
        }
        return ans;
    }
};

int main(int argc, char * argv[]) {
    Solution *s = new Solution();
    vector<string> words{};
    string word1;
    string word2;
    string line;

    getline(cin, line);
    stringstream stringin(line);
    string word;
    while (stringin >> word) {
        words.push_back(word);
    }

    cin>>word1;
    cin>>word2;

    cout<<s->shortestDistance(words, word1, word2);
    return 0;
}
