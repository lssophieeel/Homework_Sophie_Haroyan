int jumpingOnClouds(vector<int> c) {  int jumps = 0;
    int i = 0;
    while (i < c.size()-1) {
        if (i+2 < c.size() && c[i+2] == 0) {
            i += 2;
        } else {
            i += 1;
        }
        jumps += 1;
    }
  
    return jumps;
}