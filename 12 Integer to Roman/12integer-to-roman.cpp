vector<pair<int,string>> myList =
{{1, "I"},
{4, "IV"},
{5, "V"},
{9, "IX"},
{10, "X"},
{40, "XL"},
{50, "L"},
{90, "XC"},
{100, "C"},
{400, "CD"},
{500, "D"},
{900, "CM"},
{1000, "M"}};
class Solution {
public:
    string intToRoman(int num) {
        int j = (int) myList.size() - 1;
        string res = "";
        while (num) {
            while (myList[j].first > num) j--;
            while (myList[j].first <= num) {
                num -= myList[j].first;
                res += myList[j].second;
            }
        }
        return res;
    }
};