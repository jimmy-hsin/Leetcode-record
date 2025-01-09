#include <stdio.h>

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(), n=nums2.size();
    //ensure nums1 is longer than nums2
    if(m<n)
        return findMedianSortedArrays(nums2,nums1);
  
//total 為在median 之前應該要有的元素數量(這些元素都小於median)
    int total=(m+n-1)/2;
    bool even=(m+n+1)%2;
  
//如果有一個已經空了，那回傳另一個vector的中間元素
    if(n==0){
        if(even)
            return (double)(nums1[total]+nums1[total+1])/2;
        return nums1[total];
    }
//如果nums2的開頭比nums1的結尾還大，所有element 已經sorted
    if(nums2[0]>=nums1.back()){
        if(!even)   return nums1[total];
        int n2=(total+1==m)?nums2[0]:nums1[total+1];
        return  (double)(nums1[total]+n2)/2;
    }
    
//用x1，x2來存整個集合中的中間兩個數
    int x1=0, x2=0;
    for(int i=0;i<=total;i++){
      //因為我們要讓兩個中間數的前面要有total個元素，在array 1裡選到nums[i]時，前面有i個元素
        x1=nums1[i];
      //剩下的total-i，我們要用array2來補
        int j=total-i;
      //如果total-i 大於等於array的整體元素個數
        if(j>=n){  
            if(j==n && x1>=nums2.back()){  //可以把所有array2的元素納入median前面的情況
                x2=nums1[i+1];  //我們可以選擇在array1中x1 的後一個數
                break;
            }   
            else    continue;   //不然的話，這個選擇不成立，選下一個
        }
      //正常情況下，在array2中選擇第total-i個元素
        x2=nums2[j];
      //如果x1前面有元素，或x2前面有元素，且我們選到的數比這兩者之一小的話，選擇不成立，跳過換下一個
        if(i!=0 && x2<nums1[i-1])   continue;
        if(j!=0 && x1<nums2[j-1])   continue;
      
      // 如果我們選對切割點了，但兩者的後一個元素(a)比其中一個還要小的話，代表這個a比他還靠近中間，要把其中之一替換成a
        if(i!=m-1 && x2>nums1[i+1])
            x2=nums1[i+1];
        if(j!=n-1 && x1>nums2[j+1])
            x1=nums2[j+1];
        break; 
    }
  
    if(even)
        return (double) (x1+x2)/2;
    return min(x1,x2);
}
