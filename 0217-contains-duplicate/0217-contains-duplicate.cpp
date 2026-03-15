class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Prep the hash set – reserve space so we don’t keep rehashing
        unordered_set<int> seen;
        seen.reserve(nums.size() * 2);          // rough 2× capacity to avoid collisions
        seen.max_load_factor(0.25);             // keep the chain short, like a VIP line

        // Scan and shout the moment we see a repeat
        for (int x : nums) {                    // x = current suspect
            if (seen.count(x)) {                // already in the club?
                return true;                    // early bail – save those CPU cycles
            }
            seen.insert(x);                     // otherwise, let x in and keep going
        }
        // Made it to the end → everybody’s unique
        return false;
    }
};