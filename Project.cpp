#include <iostream>
#include <vector>
#include <string>
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

// Main function
int main() {
    ifstream inFile;
    if (!openFile(inFile, "names.csv")) {
        return 1; // Exit program if file cannot be opened
    }
    
    inFile.close(); // Close file after reading initial data
    
    cout << "\n*** Welcome to Student Activities Management System ***\n\n";

    srand(time(0)); // Seed random number generator
    login(); // Start login process
    return 0;
}

// Login function
void login() {
    string username, password;
    cout << "=== Login ===\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == "139691" && password == "password") {
        cout << "Login successful!\n";
        menu(); // Proceed to main menu
    } else {
        cout << "Incorrect username or password. Please try again.\n";
        login(); // Retry login if credentials are incorrect
    }
}

// Function definitions for menu options

void addStudent() {
    Student student;
    cout << "Enter first name: ";
    cin >> student.firstname;
    cout << "Enter surname: ";
    cin >> student.surname;

    while (true) {
        cout << "Enter gender (Male/Female): ";
        cin >> student.gender;
        if (isValidGender(student.gender)) break;
        else cout << "Invalid gender. Please enter 'Male' or 'Female'.\n";
    }

    while (true) {
        cout << "Enter age: ";
        cin >> student.age;
        if (isValidAge(student.age)) break;
        else cout << "Invalid age. Please enter a positive number.\n";
    }

    while (true) {
        cout << "Enter BBIT group (1-3): ";
        cin >> student.group;
        if (isValidGroup(student.group)) break;
        else cout << "Invalid group. Please enter a number between 1 and 3.\n";
    }

    cout << "Select activities for the student.\n";

    int sportChoice;
    int clubChoice;
    string input;
    bool participatingInSport = false;

    // Select Sport
    cout << "Do you want to participate in a sport? (yes/no): ";
    cin >> input;
    if (input == "yes") {
        participatingInSport = true;
        while (true) {
            cout << "Select a sport: \n1. Rugby\n2. Athletics\n3. Swimming\n4. Soccer\n";
            cin >> sportChoice;
            if (isValidSportChoice(sportChoice)) {
                student.sports.push_back(sports[sportChoice - 1].name);
                break;
            } else {
                cout << "Invalid choice. Please select a sport from the list.\n";
            }
        }
    }

    // Select Clubs
    cout << "Select clubs (Enter up to 3 clubs, separated by spaces): \n1. Journalism Club\n2. Red Cross Society\n3. AISEC\n4. Business Club\n5. Computer Science Club\n";
    if (participatingInSport) {
        cout << "You can select up to 2 clubs.\n";
    } else {
        cout << "You can select up to 3 clubs.\n";
    }
    int maxClubs = participatingInSport ? 2 : 3;
    for (int i = 0; i < maxClubs; ++i) {
        while (true) {
            cin >> clubChoice;
            if (isValidClubChoice(clubChoice)) {
                student.clubs.push_back(clubs[clubChoice - 1].name);
                break;
            } else {
                cout << "Invalid choice. Please select a club from the list.\n";
            }
        }
        if (i < maxClubs - 1) {
            cout << "Add another club? (yes/no): ";
            cin >> input;
            if (input == "no") break;
        }
    }

    students.push_back(student);
    cout << "Student added successfully!\n";
}

