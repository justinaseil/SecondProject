#include "mylib.h"
#include "stud.h"

int main() {
    vector<Stud> vec1;
    vector<Stud> vargsiukai;
    Stud s;
    vector<int> numStudents = {1000000, 10000000};
    char choice;
    bool suMediana = false;

    while (true) {
        cout << "Do you want to test the file? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'Y' || choice == 'y') {

        cout << "Do you want to generate files (G) or you generated them before (B)?";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'G' || choice == 'g') {
                for (int num : numStudents) {
                string filename = "studentai" + to_string(num) + ".txt";
        FileManager::genfailas(filename, num);
        cout << endl;
        }
        }else if (choice == 'B' || choice == 'b'){
        } else {
            cout << "Error.Try again" << endl;
        }
        cout << "Testing with vector and list containers." << endl;

        for (int num : numStudents) {
        vector<Stud> students;
        string filename = "studentai" + to_string(num) + ".txt";
        cout << "Testing with vector container for file: " << filename << endl;
        testavimas(students, filename, num);
        }

        for (int num : numStudents) {
        list<Stud> students;
        string filename = "studentai" + to_string(num) + ".txt";
        cout << "Testing with list container for file: " << filename << endl;
        testavimas(students, filename, num);
        }

        cout << "Do you want to continue the program? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'N' || choice == 'n') {
                return 0;
                } else if (choice == 'Y' || choice == 'y'){
                    break;
                } else {
                        cout << "Error.Try again" << endl;
                }
        } else if (choice == 'N' || choice == 'n') {
            break;
        } else {
            cout << "Error. Try again." << endl;
        }
    }

    while (true) {
        cout << "Do you want to read student data from a file? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {
            break;
        } else {
            cout << "Error. Try again." << endl;
        }
    }

    if (choice == 'Y' || choice == 'y') {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;

        FileManager::nuskaitymas(vec1, filename);


        while (true) {
            cout << "Do you want to calculate the final grade with median or with average? (M/A): ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'M' || choice == 'm') {
                suMediana = true;
                break;
            } else if (choice == 'A' || choice == 'a') {
                suMediana = false;
                break;
            } else {
                cout << "Error. Try again." << endl;
            }
        }

        for (auto& student : vec1) {
        student.setSuMediana(suMediana);
        if (suMediana) {
            student.galutinismed();
        } else {
            student.galutinisvid();
                }
            }
    } else {

        while (true) {
        cout << "Do you want to generate student data files? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 'Y' || choice == 'y') {
                generuotifailus();
                return 0;
            } else if (choice == 'N' || choice == 'n') {
                break;
            } else {
                cout << "Error. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

            int n;
            while (true) {
                cout << "How many students do you have? ";
                if (cin >> n && n > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                } else {
                    cout << "Error. Try again." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            for (int i = 0; i < n; i++) {
                cout << "Please input user data for student " << endl;

                while (true) {
                    cout << "Do you want to generate random grades for this student? (Y/N): ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (choice == 'Y' || choice == 'y') {
                        s.autom();
                        break;
                    } else if (choice == 'N' || choice == 'n') {
                        s.ived();
                        break;
                    } else {
                        cout << "Error. Try again." << endl;
                    }
                }

                 while (true) {
                    cout << "Do you want to calculate the final grade with median or with average? (M/A): ";
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (choice == 'M' || choice == 'm') {
                        suMediana = true;
                        break;
                    } else if (choice == 'A' || choice == 'a') {
                        suMediana = false;
                        break;
                    } else {
                        cout << "Error. Try again." << endl;
                    }
                }

                s.setSuMediana(suMediana);
                if (suMediana) {
                        s.galutinismed();
                } else {
                    s.galutinisvid();
                    }

                    cout << "Student address in memory: " << &s << endl;
                    vec1.push_back(s);
                    s.val();
            }
        }


    Rusiavimas::rusiavimas(vec1, vargsiukai, suMediana);

    Rusiavimas::sortabc(vec1);
    Rusiavimas::sortabc(vargsiukai);


    cout << "\nKietekai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis" << endl;
    cout << string(60, '-') << endl;
    for (const auto& student : vec1) {
        student.output();
    }

    cout << "\nVargšiukai:\n";
    cout << left << setw(18) << "Vardas" << setw(18) << "Pavardė" << setw(25) << "Galutinis" << endl;
    cout << string(60, '-') << endl;
    for (const auto& student : vargsiukai) {
        student.output();
    }

    FileManager::ratefailas(vec1, "kietekai.txt", "Kietekai");
    FileManager::ratefailas(vargsiukai, "vargsiukai.txt", "Vargšiukai");


    char a;
    cout << "Press any key to exit..." << endl;
    cin >> a;

    return 0;

}
