void minimumBribes(vector<int> q) {
    int count = 0;    
    for (int i = 0; i < q.size(); ++i) {
        if(q[i] - (i + 1) > 2) {
            std::cout << "Too chaotic" << std::endl;
            return;
        }        
        for (int j = q[i] - 2; j < i; ++j) {
            if(q[j] > q[i]) {
                ++count;
            }
        }      
    }

    cout << count << endl;
}