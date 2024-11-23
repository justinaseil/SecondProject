#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "mylib.h"

class Stud {

private:
    string vardas;
    string pavarde;
    vector<double> ND;
    double egz;
    double vid;
    double med;
    double rezvid;
    double rezmed;
    bool suMediana = false;


public:
    Stud() : egz(0), vid(0), med(0), suMediana(false) {}
    Stud(const string& vard, const string& pav)
        : vardas(vard), pavarde(pav), egz(0), vid(0), med(0), suMediana(false) {}

~Stud() {}

const string& getVardas() const { return vardas; }
    const string& getPavarde() const { return pavarde; }
    vector<double>& getND() { return ND; }
    double getEgz() const { return egz; }
    double getVid() const { return vid; }
    double getMed() const { return med; }
    bool getSuMediana() const { return suMediana; }
    double getRezmed() const { return rezmed; }
    double getRezvid() const { return rezvid; }

    void setRezVid(double r) { rezvid = r; }
    void setRezMed(double r) { rezmed = r; }

    void addND(double grade) {
        if (grade >= 0 && grade <= 10) {
            ND.push_back(grade);
        } else {
            throw runtime_error("Grade out of range.");
        }
    }

    void setEgz(double e) {
        if (e >= 0 && e <= 10) {
            egz = e;
        } else {
            throw runtime_error("Exam grade out of range.");
        }
    }

    void setSuMediana(bool value) { suMediana = value; }


    void vidurkis();
    void mediana();
    void galutinismed();
    void galutinisvid();

    void ived();
    void autom();
    void output() const;

    void val();
};

class FileManager {
public:
    static void genfailas(const string& filename, int numStudents) {

    auto start = steady_clock::now();

    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    file << "Vardas Pavarde ";
    for (int i = 1; i <= 10; ++i) {
        file << "ND" << i << " ";
    }
    file << "Egzaminas" << endl;

    srand(time(0));

    for (int i = 1; i <= numStudents; ++i) {
        file << "Vardas" << i << " Pavarde" << i << " ";

        for (int j = 0; j < 10; ++j) {
            file << rand() % 10 + 1 << " ";
        }

        file << rand() % 10 + 1 << endl;
    }

    file.close();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);

    cout << "File " << filename << " created in " << diff.count() << " s." << endl;
};
    template <typename Container>
    static void nuskaitymas(Container& students, const string& filename) {

    auto start = steady_clock::now();

    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file.");
    }

    string header;
    getline(file, header);

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string vardas, pavarde;
        ss >> vardas >> pavarde;

        Stud student(vardas, pavarde);

        double grade;
        while (ss >> grade) {
            if (grade >= 0 && grade <= 10) {
               student.addND(grade); ;
            } else {
                throw runtime_error("Invalid grade format in file.");
            }
        }

        if (!student.getND().empty()) {
            student.setEgz(student.getND().back());
            student.getND().pop_back();
        } else {
            throw runtime_error("No grades found in file.");
        }

        students.push_back(student);
    }

    file.close();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);

    cout << "File " << filename << " read in " << diff.count() << " s." << endl;

};
    template <typename Container>
    static void ratefailas(const Container& students, const string& filename, const string& title){
    auto start = steady_clock::now();

    ofstream file(filename);
    if (file.is_open()) {
        file << title << ":\n";
        file << left << setw(20) << "Vardas"
             << setw(25) << "Pavardė"
             << setw(30) << "Galutinis (Vid.)/Galutinis (Med.)" << endl;
        file << "-----------------------------------------------------------------------" << endl;

        for (const auto& student : students) {
            file << left << setw(20) << student.getVardas()
                 << setw(25) << student.getPavarde()
                 << fixed << setprecision(2);
            if (student.getSuMediana()) {
                file << student.getRezmed() << endl;
            } else {
                file << student.getRezvid() << endl;
            }
        }

        file.close();
    } else {
        cout << "Unable to open " << filename << " file." << endl;
    }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "File " << filename << " created in " << diff.count() << " s." << endl;
};
};

class Rusiavimas {
    public:
    template <typename Container>
    static void sortabc(Container& students) {
    auto start = steady_clock::now();

     if constexpr (is_same<Container, vector<Stud>>::value) {
            sort(students.begin(), students.end(), [](const Stud &a, const Stud &b) {
                string vardasA = a.getVardas();
                string vardasB = b.getVardas();

                transform(vardasA.begin(), vardasA.end(), vardasA.begin(), ::toupper);
                transform(vardasB.begin(), vardasB.end(), vardasB.begin(), ::toupper);

                return vardasA < vardasB;
            });
        } else if constexpr (is_same<Container, list<Stud>>::value) {
            students.sort([](const Stud &a, const Stud &b) {
                string vardasA = a.getVardas();
                string vardasB = b.getVardas();

                transform(vardasA.begin(), vardasA.end(), vardasA.begin(), ::toupper);
                transform(vardasB.begin(), vardasB.end(), vardasB.begin(), ::toupper);

                return vardasA < vardasB;
            });
        }

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Students sorted by name in " << diff.count() << " s." << endl;
};

    template <typename Container>
    static void rusiavimas(Container& students, Container& vargsiukai, bool suMediana) {
    auto start = steady_clock::now();

    auto it = partition(students.begin(), students.end(), [suMediana](Stud& student) {
        if (suMediana && student.getRezmed() == 0) {
            student.galutinismed();
        } else if (!suMediana && student.getRezvid() == 0) {
            student.galutinisvid();
        }
        return suMediana ? (student.getRezmed() < 5.0) : (student.getRezvid() < 5.0);
    });

    vargsiukai.insert(vargsiukai.end(), students.begin(), it);
    students.erase(students.begin(), it);

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Students sorted into 'vargsiukai' and remaining 'kietekai' in " << diff.count() << " s." << endl;
};
};

template <typename Container>
void testavimas(Container& students, const string& filename, int numStudents) {

    auto start = steady_clock::now();

    Container vargsiukai;

    FileManager::nuskaitymas(students, filename);

    bool suMediana = false;
    for (auto& student : students) {
        student.vidurkis();
        student.mediana();

        if (suMediana) {
            student.galutinismed();
        } else {
            student.galutinisvid();
        }
    }

    Rusiavimas::rusiavimas(students, vargsiukai, suMediana);
    Rusiavimas::sortabc(students);
    Rusiavimas::sortabc(vargsiukai);

    FileManager::ratefailas(students, "kietekai_" + filename, "Kietekai");
    FileManager::ratefailas(vargsiukai, "vargsiukai_" + filename, "Vargšiukai");

    students.clear();

    auto end = steady_clock::now();
    duration<double> diff = duration_cast<duration<double>>(end - start);
    cout << "Testing time for " << filename << ": " << diff.count() << " s." << endl;
    cout << "File testing done. " << endl;
    cout << endl;
}

void generuotifailus();


#endif // STUD_H_INCLUDED
