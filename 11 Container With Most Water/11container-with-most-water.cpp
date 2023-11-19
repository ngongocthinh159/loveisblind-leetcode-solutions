class Solution {
public:
    /*
    Nếu h[i] > h[j] thì area là h[j]*chiều rộng => Nếu move vào sâu mà ta move cột cao hơn thì luôn nhận được diện tích nhỏ hơn vì chiều cao bị block bởi cột ngắn hơn => Luôn move cột ngắn hơn.

    Trường hợp h[i] == h[j], để có thể move vào trong sâu hơn tìm diện tích lớn hơn thì đòi hỏi ta phải tìm đc 2 chiều cao lớn hơn cả h[i] lẫn h[j] (vì lúc này chắc chắn chiều ngang giảm => Cần 2 thanh chiều cao lớn hơn)
    => Ta có thể ignore cả h[i] và h[j]
    */
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l <= r) {
            res = max(res, min(height[l], height[r])*(r - l));
            if (height[l] < height[r]) l++;
            else if (height[r] < height[l]) r--;
            else {l++; r--;}
        }
        return res;
    }
};