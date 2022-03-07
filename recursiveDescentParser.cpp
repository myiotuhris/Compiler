#include <bits/stdc++.h>
using namespace std;
//non terminals in caps 
//terminals in small letter
//e denotes epsilon
//single lettered variables
map<char,list<string>> production_rules;
bool nonTerminal(char x){
    return (x>='A' && x<='Z');
}
stack<char> s;
bool parse(string input,int pos){
    char start=s.top();
    if(start=='$') return (pos==input.length());
    if(!nonTerminal(start) ) return false;
    s.pop();
    
    int original_pos=pos;
    for(auto Y:production_rules[start]){
        cout<<"HERE"<<endl;
        cout<<Y<<" ";
        if(Y=="e") Y="";
        int pop_counter=Y.length();
        for(int i=Y.length()-1;i>=0;i--){
            s.push(Y[i]);
        }
        while(s.top()!='$' && !nonTerminal(s.top()) ){
            if(pos>=input.length()) return false;
            if(s.top()==input[pos]){
                // cout<<"X"<<endl;
                pos++;
                pop_counter--;
                s.pop();
            }
            else{
                // cout<<"Here"<<endl;
                for(int i=0;i<pop_counter;i++) s.pop();
                pop_counter=0;
                pos=original_pos;
                break;
                
            }
        }
        if(parse(input,pos)) {cout<<"Worked\n";return true;}
        else{
            for(int i=0;i<pop_counter;i++) s.pop();
            pos=original_pos;
        }
    }
    return false;
    // if(pos==input.length()) return (s.top()=='$');
    // 
    // for(auto Y:production_rules[start]){
    //     cout<<Y<<endl;
    //     if(Y=="e") Y="";
    //     int pop_counter=Y.length();
    //     for(int i=Y.length()-1;i>=0;i--){
    //         s.push(Y[i]);
    //     }
    //     while(s.top()!='$' && !nonTerminal(s.top()) ){
    //         if(pos>=input.length()) return false;
    //         if(s.top()==input[pos]){
    //             cout<<"X"<<endl;
    //             pos++;
    //             pop_counter--;
    //             s.pop();
    //         }
    //         else{
    //             cout<<"Here"<<endl;
    //             for(int i=0;i<pop_counter;i++) s.pop();
    //             pos=original_pos;
    //             break;
                
    //         }
    //     }
    //     cout<<s.top()<<endl;
    //     if(nonTerminal(s.top())){
    //         char newStart=s.top();
    //         s.pop();
    //         pop_counter--;

    //         if(parse(input,pos,newStart)){
    //             cout<<"Y"<<endl;
    //             return true;
    //         }
    //         else{
    //                 for(int i=0;i<pop_counter;i++) s.pop();
    //                 pos=original_pos;
                    
    //         }
    //     }
    //     else if(s.top()=='$' && pos==input.length()) return true;
 


    // }
    // return false;
}
int main(){
    s.push('$');
    production_rules['S'].push_back("TE");
    production_rules['E'].push_back("+TE");
    production_rules['E'].push_back("e");
    production_rules['T'].push_back("FU");
    production_rules['U'].push_back("*FU");
    production_rules['U'].push_back("e");
    production_rules['F'].push_back("(S)");
    production_rules['F'].push_back("i");
    // production_rules['S'].push_back("cAd");
    // production_rules['A'].push_back("ab");
    // production_rules['A'].push_back("a");
    string input;
    cin>>input;
    s.push('S');
    cout<<parse(input,0);
    return 0;
}