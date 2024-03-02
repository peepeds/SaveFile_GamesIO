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
    // Validasi level
    if (user.Level < 1 || user.Level > 99) return false; 

    // Validasi jumlah keterampilan
    if (user.Skills.size() > 5) return false;

    // Validasi nilai keterampilan
    for (const auto& skill : user.Skills) {
        if (skill.second < 1 || skill.second > 10) return false;  
    }

    // Validasi koin
    if (user.Coins < 1 || user.Coins >= 100) return false;
    
    // Validasi kelas karakter
    string targetClass[] = {"Fighter", "Druid", "Monk", "Rogue", "Wizard", "Paladin", "Ranger", "Cleric", "Warlock"};
    bool classValid = false;
    for (const auto& validClass : targetClass) {
        if (user.Class == validClass) {
            classValid = true;
            break;
        }
    }
    if (!classValid) return false;
    
    // Semua validasi terlewati
    return true;
}

void write(const games& user) {
    if (!validation(user)) {
        cout << "Data tidak valid. Tidak dapat menulis ke file." << endl;
        return;
    }
    ofstream outputFile("Data.txt", ios::out | ios::trunc);
    outputFile << user.Level << parameter;
    for (const auto& skill : user.Skills) {
        outputFile << skill.first << ":" << skill.second << "-";
    }
    outputFile << parameter;
    outputFile << user.Coins << parameter;
    outputFile << user.Class << parameter;
    outputFile << endl;
}

int main() {
    struct games user;
    user.Level = 5;
    user.Skills["Attack"] = 5;
    user.Skills["Defend"] = 11;
    user.Skills["Magic"] = 7; // Menambah keterampilan tambahan
    user.Coins = 89.1;
    user.Class = "Paladin";
    
    // Menulis data ke dalam file
    write(user);

    // Membaca data dari file
  
    return 0;
}
