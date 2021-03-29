#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "playerList.h"

using namespace std;

void menu();
void initiative();
playerList chars(playerList players);

int main() {
    menu();
    return 0;
}

void menu(){
    playerList players;
    int input = 0;
    while(input != 3) {
        cout << "===============" << endl;
        cout << "1. Run initiative" << endl;
        cout << "2. Load chars" << endl;
        cout << "3. Terminate" << endl;
        cin >> input;
        if(input == 1){
            initiative();
        }else if(input == 2){
            playerList players = chars(players);
        }else if(input == 3){
            break;
        }else{
            cout << "Invalid input" << endl;
        }
    }
}

playerList chars(playerList players){
    fstream file;
    file.open("/res.csv/");
    string input;
    string name;
    int score;
    while(getline(file, input)){
        stringstream ss(input);
        string field;

        int counter = 0;
        while(getline(file,field, ',')){
            if(counter == 0){
                name = field;
            }else if(counter == 1){
                score == stoi(field);
            }
            counter++;
        }

    }
}
