vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    std::vector<int> result (a.size(),0);

    for(int i = 0 ;i<a.size();++i){
        result[i] = a[d+i];
    }
    
    for(int i = 0 ; i<d; ++i){
        result[n-d+i]=a[i];
    }

return result;
}