#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
    string firstname;
    string surname;
    string gender;
    int age;
    int group;
    vector<string> sports;
    vector<string> clubs;
};

struct Activity {
    string name;
    int capacity;
    int maleCount;
    int femaleCount;
    vector<string> members;
};

vector<Student> students;
vector<Activity> sports = {
    {"Rugby", 20, 0, 0, {}},
    {"Athletics", 20, 0, 0, {}},
    {"Swimming", 20, 0, 0, {}},
    {"Soccer", 20, 0, 0, {}}
};
vector<Activity> clubs = {
    {"Journalism Club", 60, 0, 0, {}},
    {"Red Cross Society", 60, 0, 0, {}},
    {"AISEC", 60, 0, 0, {}},
    {"Business Club", 60, 0, 0, {}},
    {"Computer Science Club", 60, 0, 0, {}}
};

// Function prototypes
void login();
void addStudent();
void viewStudents();
void viewActivities(vector<Activity> &activities, const string &type);
void viewGroupedStudents();
void saveAllFiles();
void menu();

bool openFile(ifstream &file, const string &filename) {
    file.open(filename);
    if (!file) {
        cerr << "Error opening file '" << filename << "'.\n";
        return false;
    }
    return true;
}

// Validation functions
bool isValidGender(const string &gender) {
    return gender == "Male" || gender == "Female";
}

bool isValidGroup(int group) {
    return group >= 1 && group <= 3;
}

bool isValidAge(int age) {
    return age > 0;
}

bool isValidSportChoice(int choice) {
    return choice >= 1 && choice <= 4;
}

bool isValidClubChoice(int choice) {
    return choice >= 1 && choice <= 5;
}
