// Is str1 subseq of str2 ?
// Is str1 subseq of str2 ?
bool isSubseq(string &str1 , string &str2) { 
    int j = 0;
    for(int i = 0; i < str2.size(); i++) {
        if(str1[j] == str2[i]) j++;
    }
    return (j >= str1.size());
}