#include <functional>
#include <algorithm>
#include <stdexcept>
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

// Definition for a Node.
class Node {
public:
    int val = 0;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* node) {
        string ans("");
        queue<Node* > q;
        q.push(node);
        int len = q.size(), i = 0;
        while (i < len) {
            auto cur_node= q.front();
            q.pop();
            ans.push_back(cur_node->val);
            ans.push_back(',');
            ans.push_back(cur_node->children.size());
            ans.push_back(',');
            for (auto node : cur_node->children) {
                q.push(node);
            }
            if (i == len - 1) {
                len = q.size();
                i = 0;
            } else {
                ++i;
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        Node* root = nullptr;
        queue<Node*> q;
        
        vector<int> datav{};
        size_t p = data.find(',', 0), lp = 0;
        while (p != string::npos) {
            datav.push_back(atoi(data.substr(lp, p - lp + 1).c_str()));
            lp = p + 1;
            p = data.find(',', lp);
        }

        if (datav.size() < 2) {
            return nullptr;
        }

        vector<Node*> children(datav[1]);
        root = new Node(datav[0], children);
        q.push(root);
        int datav_i = 2, i = 0, len = q.size();

        while (i < len) {
            auto node = q.front();
            q.pop();
            for (unsigned int j = 0; j < node->children.size(); ++i) {
                vector<Node*> sub_children(datav[datav_i + 1]);
                Node* sub_node = new Node(datav[datav_i], sub_children);
                node->children[j] = sub_node;
                q.push(sub_node);
                datav_i += 2;
            }
            if (i == len - 1) {
                i = 0;
                len = q.size();
            } else {
                ++i;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
