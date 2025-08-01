#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> visited;

        pq.push(make_tuple(a[n - 1] + b[n - 1], n - 1, n - 1));
        visited.insert({n - 1, n - 1});

        vector<int> result;

        while (k-- && !pq.empty()) {
            tuple<int, int, int> top = pq.top();
            pq.pop();

            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);

            result.push_back(sum);

            if (i - 1 >= 0 && visited.find({i - 1, j}) == visited.end()) {
                pq.push(make_tuple(a[i - 1] + b[j], i - 1, j));
                visited.insert({i - 1, j});
            }

            if (j - 1 >= 0 && visited.find({i, j - 1}) == visited.end()) {
                pq.push(make_tuple(a[i] + b[j - 1], i, j - 1));
                visited.insert({i, j - 1});
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    vector<int> a = {1, 4, 2, 3};
    vector<int> b = {2, 5, 1, 6};
    int k = 5;

    vector<int> result = sol.topKSumPairs(a, b, k);

    cout << "Top " << k << " sum pairs are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
