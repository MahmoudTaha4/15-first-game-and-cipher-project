#include <bits/stdc++.h>
using namespace std;

#define ll	long long

void Cipher(string Message,string Keyword);

int main(){
    while (true){
        ll Type = 0;
        string Message;
        string Keyword;
        cout << "1-Cipher" << endl << "2-Decipher" << endl << "3-exit"; 
        cout << endl << "Choose the type that you want to get :";
        cin >> Type;
        if (Type == 1){
            cout << endl << "Please enter the message to cipher :";
            cin >> Message;
            cout << endl << "Please enter the keyword :";
            cin >> Keyword;
            Cipher(Message,Keyword);
        }
    }  
}

void Cipher(string Message,string Keyword){
    while (true){
        string ReapetdKeyword;
        for (int i = 0; i < Keyword.size();i++){
            ReapetdKeyword[i] = Keyword[i];
        }
        cout << ReapetdKeyword;
        break;
    }
}