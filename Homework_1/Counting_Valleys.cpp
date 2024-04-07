int countingValleys(int steps, string path) {
    int level = 0;
    int count = 0;
    
    for (int i = 0; i < steps; ++i) {
        if(path[i] == 'U') {
            ++level;            
            if (level == 0) {
                ++count;
            }
        }
        else {
            --level;
        }
    }
    return count;