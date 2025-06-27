class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> res;
    string b;
private:
 void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            res.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps=mpp[word];
     
        for (int i = 0; i < word.size(); i++) {
            string temp = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (mpp.find(temp) != mpp.end() &&mpp[temp]==steps-1) {
                  seq.push_back(temp);
                  dfs(temp,seq);
                  seq.pop_back();
                }
            }
        }
    }

public:

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return res;
        queue<string> q;
        b=beginWord;
        mpp[beginWord] = 1;
           st.erase(beginWord);
        q.push({beginWord});
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word==endWord) break;
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.find(temp) != st.end()) {
                        q.push(temp);
                        st.erase(temp);
                        mpp[temp] = steps + 1;
                    }
                }
            }
        }
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord,seq);
        return res;
    }
};