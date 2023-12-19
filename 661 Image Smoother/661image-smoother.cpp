class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<pair<int,int>> moves = {{0,-1}, {0,1}, {-1,0}, {-1,-1}, {-1,1}, {1,0}, {1,-1}, {1,1}};
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int sum = img[i][j]; int cnt = 1;
                for (auto move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < img.size() && 0 <= J && J < img[0].size()) {
                        int original = img[I][J] & 255;
                        sum += original; 
                        cnt++;
                    }
                }
                int avg = sum / cnt;
                img[i][j] = (avg << 8) | img[i][j];
            }
        }
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                img[i][j] = img[i][j] >> 8;
            }
        }
        return img;
    }
};