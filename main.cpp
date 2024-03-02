#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

char parameter = '#';

struct games {
    int Level;
    map<string, int> Skills;
    float Coins;
    string Class;
};

bool validation(const games& user) {
    if (user.Level < 1 || user.Level > 99) return false; 

    if (user.Skills.size() > 5) return false;

    for (const auto& skill : user.Skills) {
        if (skill.second < 1 || skill.second > 10) return false;  
    }

    if (user.Coins < 1 || user.Coins >= 100) return false;
    
    string targetClass[] = {"Fighter", "Druid", "Monk", "Rogue", "Wizard", "Paladin", "Ranger", "Cleric", "Warlock"};
    bool classValid = false;
    for (const auto& validClass : targetClass) {
        if (user.Class == validClass) {
            classValid = true;
            break;
        }
    }
    if (!classValid) return false;
    
    return true;
}

void write(const games& user) {
    if (!validation(user)) {
        cout << "Data is not valid! Not Saving Data to the file." << endl;
        return;
    }
    ofstream outputFile("Data.naonwae", ios::out | ios::trunc);
    outputFile << user.Level << parameter;
    for (const auto& skill : user.Skills) {
        outputFile << skill.first << ":" << skill.second << "-";
    }
    outputFile << parameter;
    outputFile << user.Coins << parameter;
    outputFile << user.Class << parameter;
    outputFile << endl;
}

games parsingParameter(const string& line) {
    games result;

    istringstream iss(line);
    string token;

    // Membaca Level
    getline(iss, token, parameter);
    result.Level = stoi(token);

    // Membaca Skills
    getline(iss, token, parameter);
    istringstream skillsStream(token);
    string skillToken;
    while (getline(skillsStream, skillToken, '-')) {
        istringstream skillPairStream(skillToken);
        string skillName;
        string skillValue;
        getline(skillPairStream, skillName, ':');
        getline(skillPairStream, skillValue);
        result.Skills[skillName] = stoi(skillValue);
    }

    getline(iss, token, parameter);
    result.Coins = stof(token);

    getline(iss, token, parameter);
    result.Class = token;

    return result;
}

games read(){
    ifstream inputFile("Data.naonwae");
    string line;
    if (getline(inputFile, line)) {
        return parsingParameter(line);
    }
    
    return games();
}
void display(const games& data){
    cout << "Latest Valid Data: " << endl;
    cout << "Level: " << data.Level << endl;
    cout << "Skills:" << endl;
    for (const auto& skill : data.Skills) {
        cout << "  " << skill.first << ": " << skill.second << endl;
    }
    cout << "Coins: " << data.Coins << endl;
    cout << "Class: " << data.Class << endl;
}
int main() {
    struct games user;
    user.Level = 5;
    user.Skills["Attack"] = 5;
    user.Skills["Defend"] = 1;
    user.Skills["Magic"] = 7;
    user.Coins = 89.1;
    user.Class = "Paladin";
    
    write(user);

    games data = read();

    display(data);
  
    return 0;
}
