 std::string longestPalindrome(std::string s) {
        //if s is 0 it returns a blank string, if s is 1 it returns a string with a single character
        if (s.size() < 2)
            return s;
  
        
        int len = s.size(), max_left = 0, max_len = 1, left, right;
  
        //
        for (int start = 0; start < len && len - start > max_len / 2;) {
         
         //set left, right, and start = 0
            left = right = start;
         
           
            //while right is less than the length of the string and char ahead of current index right is the same
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
         
         //now we start from where right left off
            start = right + 1;
         
          //while we are within the bounds of the string and the char on the right side == the char equidistant from the end on the left side 
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
         
         //
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
