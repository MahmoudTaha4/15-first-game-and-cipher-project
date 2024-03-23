#include <bits/stdc++.h>
using namespace std;

#define ll	long long

void Cipher(string Message,string& reapetedKeyword,string& encryptedMessage);
string MakingReapetKeyword(string Message,string Keyword,string& reapetedKeyword);
void PrintingEnctyptedMessage(string encryptedMessage);

int main(){
    string reapetedKeyword;
    string encryptedMessage;
    while (true){
        ll Type = 0;
        string Message;
        string Keyword;
        cout << "1-Cipher" << endl << "2-Decipher" << endl << "3-exit" << endl; 
        cout << "Choose the type that you want to get :";
        cin >> Type;
        cout << "Please enter the text :";
        cin >> Message;
        cout << "Please enter the keyword :";
        cin >> Keyword;
        MakingReapetKeyword( Message,Keyword,reapetedKeyword);
        if (Type == 1){
            Cipher(Message,reapetedKeyword,encryptedMessage);
            PrintingEnctyptedMessage(encryptedMessage);
        }
    }  
}

void Cipher(string Message,string& reapetedKeyword,string& encryptedMessage){
    for (int i = 0; i < Message.size();i++){
        ll alphapet = 0;
        alphapet += int(Message[i]) + int (reapetedKeyword[i]);
        alphapet %= 26;
        alphapet += 65;
        encryptedMessage += char(alphapet);
    }
    return;
}
// repeated
string MakingReapetKeyword(string Message,string Keyword,string& reapetedKeyword){
    while (true){
        for (int i = 0; i < Keyword.size();i++){
            if (reapetedKeyword.size() == Message.size()){
                return reapetedKeyword;
            }
            reapetedKeyword += Keyword[i];
        }
    }
}

void PrintingEnctyptedMessage(string encryptedMessage){
    cout << "Encrypeted Message : " << encryptedMessage << endl;
}