class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Collect vowels
        for(char ch : s) {
            if(isVowel(ch)) {
                vowels.push_back(ch);
            }
        }

        // Sort vowels according to ASCII
        sort(vowels.begin(), vowels.end());

        // Put sorted vowels back
        int j = 0;

        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};