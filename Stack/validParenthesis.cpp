#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool valid(string str);
int main()
{
	string str;
    getline(cin,str);
	if(valid(str) == false){
		cout<<"paranthesis are not balanced"<<endl;
	}
	else{
		cout<<"paranthesis are balanced"<<endl;
	}
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    // code here
    stack<char> schar;
    bool ret = true;
    for(int idx=0;idx<s.size();idx++){
        //cout<<s[idx]<<endl;
        if(s[idx] == '(' ||
            s[idx] == '{' ||
            s[idx] == '['){
                schar.push(s[idx]);
        }
        else if(s[idx] == ')'){
            if(schar.empty() ||
            schar.top() != '('){
                ret = false;
                break;
            }
            schar.pop();
        }
        else if(s[idx] == ']'){
            if(schar.empty() ||
            schar.top() != '['){
                ret = false;
                break;
            }
            schar.pop();
        }
        else if(s[idx] == '}'){
            if(schar.empty() ||
            schar.top() != '{'){
                ret = false;
                break;
            }
            schar.pop();
        }
        
    }
   
    if(!schar.empty()){
        ret = false;
   
    }
    return ret;
}
