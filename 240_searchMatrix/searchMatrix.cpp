//编写一个高效的算法来搜索mxn矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。
//
//m == matrix.length
//n == matrix[i].length
//1 <= n, m <= 300
//- 109 <= matrix[i][j] <= 109
//每行的所有元素从左到右升序排列
//每列的所有元素从上到下升序排列
//- 109 <= target <= 109
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/search-a-2d-matrix-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        //获取m、n
        //int m = matrix.size()-1;//row
        //int n = matrix[0].size()-1;//col
        //return mySearchMatrix(matrix, 0, 0, m, n, target);

        return mySearchMatrix(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }

private:
    bool mySearchMatrix(vector<vector<int>>& matrix, int m_start, int n_start, int m_end, int n_end, int target)
    {
        //矩阵切片查找
        //矩阵小于等于2x2，无中间值，直接遍历
        if ((m_start <= m_end + 1) && (n_end - n_start <= 1))
        {
            for (int i = m_start; i <= m_end; i++)
            {
                for (int j = n_start; j <= n_end; j++)
                {
                    if (matrix[i][j] == target)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        else
        {
            //取中间元素
            int m_mid = (m_start + m_end) / 2;
            int n_mid = (n_start + n_end) / 2;
            int temp = matrix[m_mid][n_mid];
            if (target == temp)
            {
                return true;
            }
            else if (target < temp)
            {
                //分为两个矩阵
                if (mySearchMatrix(matrix, m_start, n_start, m_end, (n_mid == n_start) ? n_mid : n_mid - 1, target) || mySearchMatrix(matrix, m_start, n_mid, (m_mid == m_start) ? m_mid : m_mid - 1, n_end, target))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                //分为两个矩阵
                if (mySearchMatrix(matrix, m_start, (n_mid == n_end) ? n_mid : n_mid + 1, m_end, n_end, target) || mySearchMatrix(matrix, (m_mid == m_end) ? m_mid : m_mid + 1, n_start, m_end, n_mid, target))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>>matrix =
    {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    //int target = 20;

    cout << s.searchMatrix(matrix, target) << endl;
}