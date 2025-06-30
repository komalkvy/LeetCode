class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();

        
        vector<int> arr(n1+n2,0);

        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                int p1=i+j;
                int p2=i+j+1;

                int a=num2[i]-'0';
                int b=num1[j]-'0';

                int c=a*b;

                // for storing right most digit
                int d=c%10+arr[p2];
                if(d>=10)
                {
                    arr[p2]=d%10;
                    arr[p2-1]+=d/10;
                }
                else{
                    arr[p2]=d;
                }


                // for storing carry (left) digits
                int e=c/10+arr[p1];
                if(e>=10)
                {
                    arr[p1]=e%10;
                    arr[p1-1]+=e/10;
                }
                else{
                    arr[p1]=e;
                }
            }
        }

        int i=0;
        if(arr[0]==0) i=1;
        string ans;

        for(;i<arr.size();i++)
        {
            ans+=char(arr[i]+'0');
            
        }
        if(num1=="0"||num2=="0") return "0";
        return ans;

    }
};