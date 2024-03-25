#include <bits/stdc++.h>
using namespace std;

#define ll	long long

void Cipher(string Message,string Keyword,string& ResultMessage);
void DeCipher(string Message,string Keyword,string& ResultMessage);
void PrintResultMessage(string& encryptedMessage);
void GetInput(string& Message,string& Keyword,ll& Type);
void GetType(ll& Type);

int main(){
    while (true){
        ll Type = 0;
        string ResultMessage;
        string Message;
        string Keyword;
        GetType(Type);
        if(Type == 3)
            return 0;

        GetInput(Message,Keyword,Type);
        
        if (Type == 1){
            Cipher(Message,Keyword,ResultMessage);
        }
        else if (Type == 2){
            DeCipher(Message,Keyword,ResultMessage);
        }
        PrintResultMessage(ResultMessage);
    }  
}

void GetType(ll& Type){
    cout << "1-Cipher" << endl << "2-Decipher" << endl << "3-exit" << endl; 
    cout << "Choose the type that you want to get :";
    cin >> Type;
}

void GetInput(string& Message,string& Keyword,ll& Type){
    cout << "Please enter the text :";
    cin.ignore(1, '\n');
    getline(cin,Message);
    cout << "Please enter the keyword :";
    cin >> Keyword;
    return;
}

void Cipher(string Message,string Keyword,string& ResultMessage){
    for (int i = 0,j = Keyword.size(); i < Message.size();i++,j++){
        if (Message[i] == ' ' || (Message[i] >= '0' && Message[i] <= '9')){
            ResultMessage += Message[i];
            continue;
        }
        j %= Keyword.size();
        ll alphapet = int(Message[i]) + int (Keyword[j]);
        alphapet %= 26;
        alphapet += 65;
        ResultMessage += char(alphapet);
    }
}

void DeCipher(string Message,string Keyword,string& ResultMessage){
    for (int i = 0,j = Keyword.size(); i < Message.size();i++,j++){
        if (Message[i] == ' ' || Message[i] >= '0' && Message[i] <= '9'){
            ResultMessage += Message[i];
            continue;
        }
        j %= Keyword.size();
        ll alphapet = (int(Message[i]) - int (Keyword[j]))+26;
        alphapet %= 26;
        alphapet += 65;
        ResultMessage += char(alphapet);
    }
}

void PrintResultMessage(string& ResultMessage){
    cout << "Result Message : " << ResultMessage << endl;
}