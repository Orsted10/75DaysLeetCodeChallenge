class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;   // our “no‑duplicates allowed” club
        for (int x : nums) {       // x = current suspect
            if (seen.count(x))     // already in the club? → duplicate!
                return true;       // bail out early, save the CPU cycles
            seen.insert(x);        // otherwise, let x in and keep scanning
        }
        return false;              // made it through the whole array, all unique
    }
};