int sockMerchant(int n, vector<int> ar) {
    int count=0;
    for (int i = 0; i < ar.size(); ++i) {
        for (int j = i + 1; j < ar.size(); ++j) {
            if (ar[i] == ar[j] && ar[i]>0 && ar[j]>0 ) {
                count++;
                ar[i] = ar[j] = -1; 
            }
        }
    }
  
    return count;
}