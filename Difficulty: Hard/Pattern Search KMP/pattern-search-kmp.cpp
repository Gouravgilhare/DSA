// Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) {
    // Your code here
    lps[0] = 0;
    int  j = 0;
    for(int i = 1; i< M; i++){
        // int j = lps[i-1];
        while(j>0 && pat[i]!=pat[j])
            j = lps[j-1];
        if(pat[i]==pat[j])j++;
        lps[i]=j;
    }
    
}

// Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) {
    
    int m  = pat.size();
    int n = txt.size();
    int lps[m];
    
    computeLPSArray(pat, m , lps);
    
    int j = 0 ;
        for(int  i = 0 ; i<n ;){
            
            if(txt[i] ==pat[j] ){
                i++;
                j++;
            }
            if(j == m) return true;
            
            else if( i< n  && txt[i] !=pat[j] )
                {
                    if(j!= 0 ){
                        j = lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
    
    
    
    return false;
}