class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 1️⃣  Sort – now any duplicates become side‑by‑side twins
        sort(nums.begin(), nums.end());          // O(n log n)

        // 2️⃣  Scan once and shout the moment we see a pair
        int n = nums.size();                     // just for fun
        for (int i = 0; i < n - 1; ++i) {        // stop before last element
            if (nums[i] == nums[i + 1]) {        // twin found!
                return true;                     // early exit, save CPU
            }
        }
        // 3️⃣  Made it to the end → everybody’s unique
        return false;
    }
};