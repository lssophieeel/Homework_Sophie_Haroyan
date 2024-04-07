int calculateSum (vector<vector<int>> ar, int index_i, int index_j);

int hourglassSum(std::vector<vector<int>> arr) {
    int max = calculateSum(arr, 0, 0);
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const int currentSum = calculateSum(arr, i, j);
            
            max = max < currentSum ? currentSum : max;
        }        
    }
    
    return max;
}

int calculateSum (vector<vector<int>> ar, int index_i, int index_j) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += ar[index_i,][index_j + i];  
        sum += ar[index_i, + 2][index_j + i];
    }
    sum += ar[index_i, + 1][index_j + 1];
    
    return sum;
}