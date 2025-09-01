class Solution {
  public:
    unordered_map<int, int> freq;   
    map<int, set<int>, greater<int>> groups; 

    void add(int x) {
        int oldFreq = freq[x];
        if (oldFreq > 0) {
            groups[oldFreq].erase(x);
            if (groups[oldFreq].empty()) groups.erase(oldFreq);
        }
        freq[x]++;
        groups[freq[x]].insert(x);
    }

    void remove(int x) {
        int oldFreq = freq[x];
        groups[oldFreq].erase(x);
        if (groups[oldFreq].empty()) groups.erase(oldFreq);

        freq[x]--;
        if (freq[x] > 0) {
            groups[freq[x]].insert(x);
        } else {
            freq.erase(x);
        }
    }

    int getMode() {
        auto &s = groups.begin()->second;
        return *s.begin();
    }
    
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            add(arr[i]);
        }
        sum += getMode();

        for (int i = k; i < n; i++) {
            remove(arr[i - k]);
            add(arr[i]);
            sum += getMode();
        }

        return (int)sum;
        
    }
};
