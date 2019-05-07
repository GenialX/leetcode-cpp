#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void foo(vector<string>& words, string word1, string word2) {}
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
    for (auto& word : words) {
        cout<<word<<" ";
    }
    cout<<endl;
    cout<<word1<<" "<<word2<<endl;

    s->foo(words, word1, word2);
    return 0;
}
