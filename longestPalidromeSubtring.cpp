  string longestPalindrome(string s) {
        //if the string is empty return an empty string
    if (s.empty()) return "";
        
        //if the size 1 then return the entire string
    if (s.size() == 1) return s;
        
        //initilize minimum to 0 and maximum to 1
    int min_start = 0, max_len = 1;
        
        //we don't iterate within the for loop 
    for (int i = 0; i < s.size();) {
        
        //if string size - i is less than the half max length then break out of the loop
      if (s.size() - i <= max_len / 2) break;
        
        //I have no idea whats going on here 
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
    }
