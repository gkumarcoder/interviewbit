bool check(int x)
{
  for(int i=2;i*i<=x;i++)
  {
    if(x%i==0)
    {
      return false;
    }
  }
  return true;
}


int Solution::solve(vector<int> &A, int B, int C) {
    int n=A.size();
  int prime[n];
  memset(prime,0,sizeof(prime));
  for(int i=0;i<n;i++)
  {
    if(check(A[i]))
    {
      prime[i]=1;
    }
  }
  int sum=0,flag=0;
  int ans=0;
  for(int i=1;i<(1<<n);i++)
  {
    sum=0;
    flag=0;
    for(int j=0;j<n;j++)
    {
      if(i&(1<<j))
      {
        sum+=A[j];
        if(prime[j])
          flag=1;
      }
    }
    if(sum>=B && sum<=C && flag==1)
    {
      ans++;
    }
  }
  return ans;
}
