long repeatedString(string s, long n) {
    long count = 0;
    int mn =0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == 'a'){
            count++;
        }
    }
    count*= n/s.size();
    mn = n%s.size();
    for(int i=0; i<mn; ++i){
        if (s[i] == 'a'){
            count++;
        }
    }
    return count;
}