// binary search TO: O(n^2), SP:O(n)
class MyCalendar {
public:
    vector<pair<int,int>> is;
    MyCalendar() {}
    int find(pair<int,int> item) {
        int l=0, r=is.size()-1, m;
        while(l<r) {
            m = (l+r)>>1;
            if (is[m].first >= item.first) {
                r=m;
            } else {
                l=m+1;
            }
        }
        return l;
    }
    
    bool book(int start, int end) {
        pair<int,int> item = {start,end};
        if (is.empty()) {
            is.push_back({start,end});
            return true;
        }
        auto p = find(item);
        if (is[p].first < start) {
            if (start < is[p].second) return false;
            is.push_back(item);
            return true;
        } else {
            // [1,2),  [3,5) , [6,10]
            // 2,3
            if (p > 0) {
                if (is[p-1].second > start) return false;
            }
            if (is[p].first < end) return false;
            is.insert(is.begin() + p, item);
        }
        return true;
    }
};

// treemap, TO: O(nlogn), SP: O(n)
class MyCalendar {
public:
    map<int,int> st; // start, end
    MyCalendar() {}
    bool book(int start, int end) {
        auto it = st.lower_bound(start);
        if (it != st.end() && it->first < end) return false;
        if (it != st.begin() && (--it)->second > start) return false;
        st[start]=end;
        return true;
    }
};
