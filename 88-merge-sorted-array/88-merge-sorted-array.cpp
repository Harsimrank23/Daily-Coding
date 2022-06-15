class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(n==0) return;
        // if(m==0) nums1=nums2;
        int j=m+n-1;
        m--,n--;
        while(m>=0 && n>=0 && j>=0)
        {
            if(nums1[m]>nums2[n])
            {
                nums1[j]=nums1[m];
                m--;
                j--;
            }
            else
            {
                nums1[j]=nums2[n];
                n--;
                j--;
            }
        }
        while(n>=0){
            nums1[j--]=nums2[n--];
        }
    }
};