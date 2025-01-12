//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/two-sum/description/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j,indices_added=0;
    int *SumArr=malloc(2*(sizeof(int)));

    for(i=0;i<(numsSize-1);i++)
    {
        if(indices_added) break;
        for(j=(i+1);j<=(numsSize-1);j++)
        {
            if((nums[i]+nums[j])==target) 
            {
                SumArr[0]=i;
                SumArr[1]=j;
                indices_added=1;
                break;
            }
        }
    }
    *returnSize=2;
    return SumArr;
}