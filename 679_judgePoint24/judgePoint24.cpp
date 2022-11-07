//给定一个长度为4的整数数组?cards?。你有 4 张卡片，每张卡片上都包含一个范围在[1, 9] 的数字。您应该使用运算符?['+', '-', '*', '/']?
//和括号?'('?和?')'?将这些卡片上的数字排列成数学表达式，以获得值24。
//
//你须遵守以下规则 :
//
//除法运算符 '/' 表示实数除法，而不是整数除法。
//例如，?4 / (1 - 2 / 3) = 4 / (1 / 3) = 12?。
//每个运算都在两个数字之间。特别是，不能使用 “ - ” 作为一元运算符。
//例如，如果 cards = [1, 1, 1, 1] ，则表达式 “ - 1 - 1 - 1 - 1” 是 不允许 的。
//你不能把数字串在一起
//例如，如果 cards = [1, 2, 1, 2] ，则表达式 “12 + 12” 无效。
//如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false?。
//
// cards.length == 4
// 1 <= cards[i] <= 9
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/24-game
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution
{
public:
    bool judgePoint24(vector<int>& cards)
    {
        //拓展到6位，第5位存放第一次运算结果，第6位存放第二次运算结果
        bool used[6] = { 0 };
        float cards_f[6] = { (float)cards[0], (float)cards[1], (float)cards[2], (float)cards[3] };

        return myjudgePoint24(cards_f, used);
    }

private:
    bool check(float result)//检查浮点运算是否近似±24
    {
        return fabs((fabs(result) - 24)) <= 1e-5;
    }
    bool myjudgePoint24(float* cards, bool* used)
    {
        //遍历
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (!used[i] && !used[j] && cards[i] && cards[j]) //未使用且已初始化
                {
                    //使用
                    used[i] = 1;
                    used[j] = 1;

                    if (!cards[4])//cards[4]未初始化
                    {
                        //遍历5个运算
                        cards[4] = cards[i] + cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[4] = cards[i] * cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[4] = cards[i] - cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[4] = cards[i] / cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[4] = cards[j] / cards[i];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        //回溯
                        cards[4] = 0;
                    }
                    else if (!cards[5])//cards[5]未初始化
                    {
                        //遍历5个运算
                        cards[5] = cards[i] + cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[5] = cards[i] * cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[5] = cards[i] - cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[5] = cards[i] / cards[j];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        cards[5] = cards[j] / cards[i];
                        if (myjudgePoint24(cards, used))
                        {
                            return true;
                        }
                        //回溯
                        cards[5] = 0;
                    }
                    else
                    {
                        //所有数均以运算，与24比较
                        float result;
                        result = cards[i] + cards[j];
                        if (check(result))
                        {
                            return true;
                        }
                        result = cards[i] * cards[j];
                        if (check(result))
                        {
                            return true;
                        }
                        result = cards[i] - cards[j];
                        if (check(result))
                        {
                            return true;
                        }
                        result = cards[i] / cards[j];
                        if (check(result))
                        {
                            return true;
                        }
                        result = cards[j] / cards[i];
                        if (check(result))
                        {
                            return true;
                        }
                    }
                    //回溯
                    used[i] = 0;
                    used[j] = 0;
                }
            }
        }
        //遍历完成，均未返回true
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> cards = { 4, 1, 8, 7 };
    //vector<int> cards = { 1,2,1,2 };

    cout << s.judgePoint24(cards) << endl;
}