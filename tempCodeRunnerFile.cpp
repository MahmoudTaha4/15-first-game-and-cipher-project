#include <bits/stdc++.h>
using namespace std;

#define ll	long long

void Cipher(string Message,string Keyword,string& encryptedMessage);
void PrintingEnctyptedMessage(string encryptedMessage);

int main(){
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
        if (Type == 1){
            Cipher(Message,Keyword,encryptedMessage);
            PrintingEnctyptedMessage(encryptedMessage);
        }
    }  
}

void Cipher(string Message,string Keyword,string& encryptedMessage){
    for (int i = 0,j = Keyword.size(); i < Message.size();i++,j++){
        j %= Keyword.size();
        ll alphapet = 0;
        alphapet += int(Message[i]) + int (Keyword[j]);
        alphapet %= 26;
        alphapet += 65;
        encryptedMessage += char(alphapet);
    }
    return;
}

void PrintingEnctyptedMessage(string encryptedMessage){
    cout << "Encrypeted Message : " << encryptedMessage << endl;
}