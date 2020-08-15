int Solution::solve(vector <int> &A)
{

    int n = A.size();
    int nge[n],pge[n];
    stack <int> s;
    s.push(0);
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && (A[s.top()]/2)<A[i])
        {
            nge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
     nge[s.top()] = n;
     s.pop();
    }
    s.push(n-1);
    for(int i= n-2;i>-1;i--)
    {
        while(!s.empty() &&  A[s.top()]/2<A[i])
        {
            pge[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        pge[s.top()] = -1;
        s.pop();
    }
    int ans = 0;
  for(int i=0;i<n;i++)
  {
      ans += (nge[i] - i - 1LL)* (i - pge[i] - 1LL);
      ans += nge[i] - i -1;
      ans +=  i - pge[i] - 1;
  }
  return ans;
}
