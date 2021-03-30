#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "playerList.h"

using namespace std;

void menu();
void initiative(playerList players);
playerList addChar(playerList players);
playerList chars(playerList players);

int main() {
    menu();
    return 0;
}

void menu(){
    playerList players;
    int input = 0;
    string charInput;
    while(input != 7) {
        cout << "1. Run initiative" << endl;
        cout << "2. Load chars" << endl;
        cout << "3. Add char" << endl;
        cout << "4. Print list" << endl;
        cout << "5. Clear Memory" << endl;
        cout << "6. Remove Character from Mem" << endl;
        cout << "7. Terminate" << endl;
        cin >> input;
        if(input == 1){
            initiative(players);
        }else if(input == 2){
            players = chars(players);
        }else if(input == 3){
            players = addChar(players);
        }else if(input == 4) {
            players.printList();
        }else if(input == 5) {
            players.emptyList();
        }else if(input == 6) {
            cout << "Name a character" << endl;
            cin >> charInput;
            players.remove(charInput);
        }else if(input == 7) {
            break;
        }else{
            cout << "Invalid Input" << endl;
        }
    }
}

void initiative(playerList players){
    players.genInt();
    players.sort();
    players.printList();
}

playerList addChar(playerList players){
    string name, response;
    int score;
    cout << "Enter character's name: " << endl;
    cin >> name;
    cout << "Enter character's initiative modifier: " << endl;
    cin >> score;
    cout << "Would you like to store this character or only load it? Y/N" << endl;
    cin >> response;
    players.push(name,score);
    if(response == "Y" || response == "y"){
        string output;
        ofstream file;
        output = name;
        output.append(",");
        output.append(to_string(score));
        file.open("Input.csv", std::ios::app);
        file << output << endl;
    }
    return players;
}

playerList chars(playerList players){
    ifstream file;
    file.open("input.csv");
    string line;
    string name;
    int score;
    while(getline(file, line)){
        cout << "Current Line: " << line << endl;
        stringstream ss(line);
        string field;
        int counter = 0;
        while(getline(ss,field, ',')){
            if(counter == 0){
                name = field;
            }else if(counter == 1){
                score = stoi(field);
            }
            counter++;
        }
        players.push(name,score);
    }
    cout << "Currently Loaded" << endl;
    players.printList();
    return players;
}
