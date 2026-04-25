// Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string s, int M, int* lps) {
    // Your code here
    int i=0,j=1;
    lps[0]=0;
    while(j<M){
        if(s[i]==s[j]){
            lps[j]=i+1;
            j++;
            i++;
        }else{
            if(i==0){
                lps[j]=0;
                j++;
            }else{
                i=lps[i-1];
            }
        }
    }
}

// Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) {
    int m=pat.size();
    int n=txt.size();
    int* lps=new int[m];
    computeLPSArray(pat,m,lps);
    int j=0;
    int i=0;
    
    while(i<n && j<m){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }else{
            if(j==0){
                i++;
            }
           else j=lps[j-1];
        }
    }
    return j==m;
    // Your code here
}