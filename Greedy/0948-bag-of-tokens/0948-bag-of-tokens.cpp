class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left=0, right=tokens.size()-1, score=0;
        while(left<=right) {
            while (left < tokens.size() && power >= tokens[left]) score++, power-=tokens[left++];
            if (right-left>=2 && score >= 1) score--, power+=tokens[right--];
            else break;
        }
        return score;
    }
};