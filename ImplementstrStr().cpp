/*
Problem: Implement strStr()

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

Solution: Search

Time Compexity: O(n/m)

Space Complexity: O(1)
where n is the string to be searched in and m is the string to be searched.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        string x=string(haystack,strlen(haystack));
        string y=string(needle,strlen(needle));
        if(y=="")return haystack;
        int len=y.size();
        for(int i=0;i+len<=x.size();i++){
            if(x.substr(i,len)==y){
                return &haystack[i];
            }
        }
        return NULL;
    }
};