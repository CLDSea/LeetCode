// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// 只会存在一个有效答案

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/two-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution //哈希表
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int size=nums.size();
        map<int,int> hashmap;
        for(int i=0;i<size;i++)
        {
            if(hashmap.find(target-nums[i])!=hashmap.end())
            {
                return vector<int>({i,hashmap[target-nums[i]]});
            }            
            hashmap[nums[i]]=i;
        }
        return vector<int>();
    }
    
    // vector<int> twoSum(vector<int>& nums, int target) 
    // {
    //     int size=nums.size();
    //     for(int i=0;i<size-1;i++)
    //     {
    //         for(int j=i+1;j<size;j++)
    //         {
    //             if(nums[i]+nums[j]==target)
    //             {
    //                 return vector<int>({i,j});
    //             }
    //         }
    //     }
    //     return vector<int>();
    // }
};

int main()
{
    Solution s;
    vector<int>nums={2,7,11,15};
    int target=9;

    // vector<int>nums={3,2,4};
    // int target=6;

    // vector<int>nums={3,3};
    // int target=6;

    vector<int> res = s.twoSum(nums, target);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}