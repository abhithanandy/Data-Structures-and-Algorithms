class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mp;

        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }

        for (auto it : mp) {
            int num = it.first;
            int freq = it.second;

            if (freq == 0)
                continue;

            for (int i = 0; i < groupSize; i++) {
                if (mp[num + i] < freq)
                    return false;

                mp[num + i] -= freq;
            }
        }

        return true;
    }
};