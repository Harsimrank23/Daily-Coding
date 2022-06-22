// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int s;
        int e;
        int p;
    };
    
    bool static comparator(struct meeting m1,struct meeting m2)
    {
        if(m1.e<m2.e)
            return true;
        else if(m1.e>m2.e)
            return false;
        else if(m1.p<m2.p)
            return true;
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting m[n];
        for(int i=0;i<n;i++)
        {
            m[i].s=start[i];   
            m[i].e=end[i];
            m[i].p=i+1;   
        }
        
        sort(m,m+n,comparator);
        
        int limit=m[0].e;
        int meetings=1;
        
        for(int i=1;i<n;i++)
        {
            if(m[i].s>limit)
            {
                limit=m[i].e;
                meetings++;
            }
        }
        
        return meetings;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends