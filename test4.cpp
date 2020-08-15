int Solution::solve(vector<int> &A, int B) {
        int maxx = 0;
        int k = B;
        for(int i = 0 ; i < A.size() ; i++){
            maxx = max(maxx, A[i]);
        }

        int freq[maxx+1];
        memset(freq, 0, sizeof(freq));

        for(int i=0;i<A.size();i++){
            freq[A[i]]++;
        } 

        int i=0, j=maxx;
        while(i<j){

            if(freq[i] > freq[j]) {

                if(freq[j] <= k){                // perfrom decrement operation
                    freq[j-1] = freq[j-1]+freq[j];
                    k = k-freq[j];
                    j--;
                }
                else{
                    break;
                }
            }
            else
            {
                if(freq[i] <= k){         // perfrom increment operation
                    freq[i+1] = freq[i+1]+freq[i];
                    k = k-freq[i];
                    i++;
                }
                else{
                    break;
                }           
            }
        }
        
        return j-i;
}
