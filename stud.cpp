#include "stud.h"


void Stud::vidurkis() {
    if (!ND.empty()) {
        vid = accumulate(ND.begin(), ND.end(), 0.0) / ND.size();
    } else {
        vid = 0.0;
    }
}

void Stud::mediana() {
    if (!ND.empty()) {
        sort(ND.begin(), ND.end());
        int size = ND.size();
        if (size % 2 == 0) {
            med = (ND[size / 2 - 1] + ND[size / 2]) / 2.0;
        } else {
            med = ND[size / 2];
        }
    } else {
        med = 0.0;
    }
}

void Stud::galutinisvid() {
    vidurkis();
    rezvid = 0.4 * vid + 0.6 * egz;
}

void Stud::galutinismed() {
    mediana();
    rezmed = 0.4 * med + 0.6 * egz;
}

void Stud::ived() {
    cout << "Input Name and Surname: ";
    cin >> vardas >> pavarde;

    while (true) {
        cout << "Input Exam points: ";
        if (cin >> egz && egz >= 0 && egz <= 10) {
            break;
        } else {
            cout << "Error. Try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double grade;
    cout << "Input homework grades and press enter twice to finish: " << endl;
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        try {
            grade = stod(input);
            if (grade >= 0 && grade <= 10) {
                ND.push_back(grade);
            } else {
                cout << "Error. Enter number from 0 to 10..." << endl;
            }
        } catch (...) {
            cout << "Error. Enter number from 0 to 10..." << endl;
        }
    }
}

void Stud::autom() {
    cout << "Input Name, Surname: ";
    cin >> vardas >> pavarde;

    srand(time(0));
    egz = rand() % 10 + 1;

    for (int j = 0; j < 12; ++j) {
        ND.push_back(rand() % 10 + 1);
    }
}

void Stud::output() const {
    cout << left << setw(18) << vardas
         << setw(20) << pavarde
         << fixed << setprecision(2);

    if (suMediana) {
        cout << rezmed << endl;
    } else {
        cout << rezvid << endl;
    }
}

void Stud::val() {
    vardas.clear();
    pavarde.clear();
    ND.clear();
    vid = 0;
    med = 0;
    rezmed = 0;
    rezvid = 0;
    suMediana = false;
}


    void generuotifailus() {
    FileManager::genfailas("studentai1000.txt", 1000);
    FileManager::genfailas("studentai10000.txt", 10000);
    FileManager::genfailas("studentai100000.txt", 100000);
    FileManager::genfailas("studentai1000000.txt", 1000000);
    FileManager::genfailas("studentai10000000.txt", 10000000);
}


