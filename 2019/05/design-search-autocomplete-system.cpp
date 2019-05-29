#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define PB push_back
#define MP make_pair

using namespace std;

const double eps = 1e-8;

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;

struct cmp {
    bool operator() (const pair<int, string> a, const pair<int, string> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else return a.first > b.first;
    }
};

struct cmp2 {
    bool operator() (const pair<int, string> a, const pair<int, string> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else return a.first < b.first;
    }
};

struct Node{
    char c;
    bool is_sentence = false;
    int time = 0;
    unordered_map<char, Node*> next;
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp > q; // max-queue first -> times, second -> string
    Node(char cc) {
        c = cc;
    };
};

class AutocompleteSystem {
private:
    const unsigned int LIMIT = 3;
    Node* root;
    Node* last = nullptr;
    string inputs = "";
    bool have = false;
    int cur_time = 0;
    void helper(Node* node, string sentence, int i, int time, bool redo = false) {

        int len = sentence.length();
        if (i >= len) return;
        char c = sentence[i];
        // create next node
        if (node->next.find(c) == node->next.end()) {
            node->next[c] = new Node(c);
        }
        if (i == len - 1) {
            node->next[c]->is_sentence = true;
            node->next[c]->time = time;
        }
        // resize the current node's prioriy_queue
        if (redo == false) {
            if (node->next[c]->q.size() >= LIMIT) {
                auto& pa = node->next[c]->q.top();
                if (pa.first < time) {
                    node->next[c]->q.pop();
                    node->next[c]->q.push(make_pair(time, sentence));
                } else if (pa.first == time && pa.second > sentence) {
                    node->next[c]->q.pop();
                    node->next[c]->q.push(make_pair(time, sentence));
                }
            } else {
                node->next[c]->q.push(make_pair(time, sentence));
            }
        } else {
            // TODO
            priority_queue<pair<int, string>, vector<pair<int, string>>, cmp2 > tmp_q; // max-queue first -> times, second -> string
            tmp_q.push(make_pair(time, sentence));
            while (!node->next[c]->q.empty()) {
                auto pa = node->next[c]->q.top();
                node->next[c]->q.pop();
                if (pa.second == sentence) {
                    continue;
                }
                tmp_q.push(pa);
            }
            while (node->next[c]->q.size() < LIMIT && tmp_q.size() > 0) {
                auto pa = tmp_q.top();
                node->next[c]->q.push(tmp_q.top());
                tmp_q.pop();
            }
        }
        helper(node->next[c], sentence, i + 1, time, redo);
    };
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Node('*');
        Node* node = root;
        for (unsigned int i = 0; i < sentences.size(); ++i) {
            string sentence = sentences[i];
            helper(node, sentence, 0, times[i]);
        }
    }

    vector<string> c2vector(priority_queue<pair<int, string>, vector<pair<int, string>>, cmp > q) {
        vector<string> ans{};
        while (!q.empty()) {
            auto pa = q.top();
            q.pop();
            ans.insert(ans.begin(), pa.second);
        }
        return ans;
    }
    vector<string> input(char c) {
        vector<string> ans{};
        if (c == '#') {
            bool redo = false;
            if (have) {
                ++cur_time;
                redo = true;
            } else {
                cur_time = 1;
            }
            helper(root, inputs, 0, cur_time, redo);
            last = nullptr;
            inputs = "";
            have = false;
            cur_time = 0;
            return {};
        } else {
            inputs += c;
            if (last == nullptr) {
                if (root->next.find(c) == root->next.end()) {
                    last = new Node('#');
                    have = false;
                    return {};
                } else {
                    last = root->next[c];
                    have = last->is_sentence;
                    cur_time = last->time;
                    return c2vector(last->q);
                }
            } else {
                if (last->next.find(c) == last->next.end()) {
                    have = false;
                    if (last->c != '#') last = new Node('#');
                    return {};
                } else {
                    last = last->next[c];
                    have = last->is_sentence;
                    cur_time = last->time;
                    return c2vector(last->q);
                }
            }
        }
        return ans;
    }
};
