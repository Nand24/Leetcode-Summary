class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> available(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string curr = q.front().first;
           int ans = q.front().second;
            if(curr==endWord) return ans;
            q.pop();
            string temp = curr;
            for (int i = 0; i < curr.size(); i++) {
                string temp = curr;
                for (char j = 'a'; j <= 'z'; j++) {
                    temp[i] = j;
                    if (available.find(temp) != available.end()) {
                        q.push({temp, ans + 1});
                        available.erase(temp);
                    }
                }
            }
        }
         return 0;
    }
};