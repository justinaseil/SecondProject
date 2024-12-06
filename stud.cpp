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

istream& operator>>(istream& is, Stud& obj) {
    cout << "Input Name and Surname: ";
    string vardas, pavarde;

    is >> vardas >> pavarde;

    obj.vardas = vardas;
    obj.pavarde = pavarde;


    while (true) {
        cout << "Input Exam points: ";
        if (is >> obj.egz && obj.egz >= 0 && obj.egz <= 10) {
            break;
        } else {
            cout << "Error. Try again" << endl;
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    is.ignore(numeric_limits<streamsize>::max(), '\n');

    obj.ND.clear();
    double grade;
    cout << "Input homework grades and press enter twice to finish: " << endl;
    while (true) {
        string input;
        getline(is, input);
        if (input.empty()) {
            break;
        }
        try {
            grade = stod(input);
            if (grade >= 0 && grade <= 10) {
                obj.ND.push_back(grade);
            } else {
                cout << "Error. Enter number from 0 to 10..." << endl;
            }
        } catch (...) {
            cout << "Error. Enter number from 0 to 10..." << endl;
        }
    }
    return is;
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

ostream& operator<<(ostream& os, const Stud& obj) {
    os << left << setw(18) << obj.getVardas()
        << setw(20) << obj.getPavarde()
        << fixed << setprecision(2);

    if (obj.suMediana) {
        os << obj.rezmed;
    } else {
        os << obj.rezvid;
    }
    os << endl;
    return os;
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


