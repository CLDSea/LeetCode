//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//
//只使用数字1到9
//每个数字 最多使用一次 
//返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
//
// 2 <= k <= 9
// 1 <= n <= 60
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/combination-sum-iii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {

        vector<vector<int>> results;//最终结果
        vector<int> res(k);//每种结果临时保存

        mycombinationSum3(k, n, 1, res, results);

        return results;
    }
private:
    void mycombinationSum3(int k, int n, int least, vector<int>& res, vector<vector<int>>& results)
    {
        //剪枝
        //int nums_min = (2 * least - 1 + k) * k / 2;//最小k个和
        //int nums_max = (19 - k) * k / 2;//最大k个和

        //if (n >= nums_min && n <= nums_max)
        if (n >= (2 * least - 1 + k) * k / 2 && n <= (19 - k) * k / 2)
        {
            if (k == 1)
            {
                res[0] = n;
                results.push_back(res);//添加一种结果
            }
            else
            {
                for (int num = least; num <= 9; num++)//回溯
                {
                    res[k - 1] = num;
                    mycombinationSum3(k - 1, n - num, num + 1, res, results);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    int k = 3;
    int n = 7;

    //int k = 3;
    //int n = 9;

    //int k = 4;
    //int n = 1;

    vector<vector<int>> res = s.combinationSum3(k, n);
    int rows = res.size();
    int cols;
    if (rows)
    {
        cols = res[0].size();

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                cout << res[row][col] << " ";
            }
            cout << endl;
        }
    }
}