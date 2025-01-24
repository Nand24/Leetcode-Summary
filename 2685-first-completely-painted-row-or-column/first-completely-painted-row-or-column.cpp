class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> positions;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                positions[mat[i][j]] = {i, j};
            }
        }
        int colcnt = mat[0].size();
        int rowcnt = mat.size();
        vector<int> rowfreq(rowcnt, 0);
        vector<int> colfreq(colcnt, 0);
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            int row = positions[val].first;
            int col = positions[val].second;
            ++rowfreq[row];
            ++colfreq[col];
            if (rowfreq[row] == colcnt || colfreq[col] == rowcnt) {
                return i;
            }
        }

        return -1;
    }
};