#include <bits/stdc++.h>
using namespace std;

const int numberOfPlayers = 2;
#define ll	long long

int thereIsWinner(int playersScore[],int currPlayer);
void addScore(int input, int currPlayer, int playersScore[]);
void ChangeCurrPlay(int& currPlayer);
void printCurrPlayerMessage(int& currPlayer, string playersNames[]);
bool isExist(int num, int array[], int arraySize);
void getInput(int& temp,string playersNames[],int currPlayer,int array[], int arraySize);
void DeletOneNum(int array[], int& arraySize, int temp);
void PrintArray(int array[], int arraySize);
void initArray(int array[], int arraySize);


int main(){
    int arraySize = 9;
    int array[arraySize];
    string playersNames[numberOfPlayers] = {"player 2","player 1"};
    int playersScore[numberOfPlayers] = {0,0};
    int currPlayer = 0;
    initArray(array, arraySize);
    PrintArray(array, arraySize);

    while (true){
        int temp;
        int isWinner = thereIsWinner(playersScore,currPlayer);
        if (isWinner == 1){
            cout << endl << playersNames[currPlayer] << " is the winner";
            return 0;
        }
        else if (isWinner == 3){
            cout << endl << "Tie";
            return 0;
        }
        ChangeCurrPlay(currPlayer);
        printCurrPlayerMessage(currPlayer,playersNames);
        getInput(temp,playersNames,currPlayer,array,arraySize);
        addScore(temp,currPlayer,playersScore);
        DeletOneNum(array, arraySize, temp);
        PrintArray(array,arraySize);
    }
}


int thereIsWinner(int playersScore[],int currPlayer){
    if (playersScore[currPlayer] == 15){
        return 1;
    }
    else if (playersScore[0] > 15 && playersScore[1] > 15){
        return 3;
    }
    return 0;
}

void addScore(int input, int currPlayer, int playersScore[]){
    playersScore[currPlayer] += input;
}

void ChangeCurrPlay(int& currPlayer){
    currPlayer++;
    currPlayer %= numberOfPlayers;
}

void printCurrPlayerMessage(int& currPlayer, string playersNames[]){
    cout << endl << playersNames[currPlayer] << " enter number from this previous set :";
}

bool isExist(int num, int array[], int arraySize){
    for (int i = 0; i < arraySize;i++){
        if (num == array[i]){
            return true;
        }
    }
    return false;
}

void getInput(int& temp,string playersNames[],int currPlayer,int array[], int arraySize){
    cin >> temp;
    while (true){
        if (isExist(temp, array, arraySize)){
            break;
        }
        cout << endl << "wrong input from " << playersNames[currPlayer] << " please try again and enter from the set :";
        cin >> temp;
        continue;
    }
}

void DeletOneNum(int array[], int& arraySize, int temp){
    // if the last element will be deleted
    if(array[arraySize - 1] == temp){
        arraySize--;
        return;
    }

    // else
    for (int i = 0; i < arraySize; i++){
        if (array[i] == temp){
            arraySize--;
            for (int j = i; j < arraySize;j++){
                array[j] = array[j+1];
            }
            break;
        }
    }
}

void PrintArray(int array[], int arraySize){
    cout << "[";
    for (int i = 0; i < arraySize;i++){
        cout << array[i];
        if(i != arraySize - 1)
            cout << ", ";
    }
    cout << "]";
}

void initArray(int array[], int arraySize){
    for (int i = 1, j = 0; i <= arraySize;i++,j++){
        array[j] = i;
    }
}