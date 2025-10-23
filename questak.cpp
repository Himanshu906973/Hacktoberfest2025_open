#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
class Solution {
    stack<char> st;
    queue<char> q;
public:
    void pushCharacter(char ch){
        st.push(ch);
    }
    void enqueueCharacter(char ch){
        q.push(ch);
    }
    char popCharacter(){
        char c=st.top();
        st.pop();
        return c;
    }
    char dequeueCharacter(){
        char c=q.front();
        q.pop();
        return c;
    }
};
int main() {  
    string s;
    getline(cin,s);
    Solution obj;
    for(int i=0;i<s.length();i++){
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    bool isPalindrome=true;
    for(int i=0;i<s.length()/2;i++){
        if(obj.popCharacter() != obj.dequeueCharacter()){
            isPalindrome=false;
            break;
        }
    }
    if(isPalindrome){
        cout<<"The word, "<<s<<", is a palindrome."<<endl;
    }else {
        cout<<"The word, "<<s<<", is not a palindrome."<<endl;
    }
    return 0;
}
