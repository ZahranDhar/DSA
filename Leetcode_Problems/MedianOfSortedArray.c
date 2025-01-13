//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int i=0,j=0,k=-1,med1Index,med2Index,sarrSize;
    double med1,med2,PresVal;

    sarrSize=nums1Size+nums2Size;

    med1Index=(sarrSize/2)-1;
    med2Index=sarrSize/2;

    while(k<med2Index)
    {
        if((i<(nums1Size))&&(j<(nums2Size)))
        {
            (nums1[i]<nums2[j])? (PresVal=nums1[i++]):(PresVal=nums2[j++]);
        }
        else if(i<nums1Size) PresVal=nums1[i++];
        else PresVal=nums2[j++];

        k++;

        if(k==med1Index) med1=PresVal;
        if(k==med2Index) med2=PresVal;

    }

    return ((sarrSize%2)!=0)? (med2):((med1+med2)/2.0);
    
}