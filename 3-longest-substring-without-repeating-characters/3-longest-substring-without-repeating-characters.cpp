class Solution {
public:
    int lengthOfLongestSubstring(string s) 
{
int n = s.size();
if(n==0) return 0;
if(n==1) return 1;

int ans_l = 0;
int i=0,j=1;

while(j<n)
{
	for(int k=i; k<j; k++)
	{
		if(s[k] == s[j])
		{
            //cout<<k<<"  "<<j<<"  BREAK"<<endl;
			i = k+1;
			break;	
		}
        //cout<<k<<"  "<<j<<endl;
	}
    
	ans_l = max(ans_l, j-i+1);
	j++;
}
return ans_l;
}
};