int makeAnagram(string a, string b) { 
    int count = a.size() + b.size(); 
     
    for(int i = 0; i < a.size(); i++) { 
        for(int j = 0; j < b.size(); j++) { 
            if(a[i] == b[j]) { 
                b.erase(j, 1); 
                count -= 2; 
                break; 
            } 
        } 
    }
    
    return count; 
}