#include <gtest/gtest.h>
#include "stud.h"
#include "mylib.h"

TEST(StudTest, CalculateFinalGradeWithMedian) {
    Stud student("Juste", "Seil");

    student.addND(5.0);
    student.addND(7.0);
    student.addND(6.0);
    student.setEgz(8.0);
    student.setSuMediana(true);

    student.galutinismed();

    EXPECT_DOUBLE_EQ(student.getRezmed(), 7.2);
}

TEST(RankingTest, SortByName) {
    vector<Stud> students;

    students.push_back(Stud("Ana", "Petraityte"));
    students.push_back(Stud("Benas", "Kelmas"));
    students.push_back(Stud("Dominyka", "Jonaite"));

    Rusiavimas::sortabc(students);

    EXPECT_EQ(students[0].getVardas(), "Ana");
    EXPECT_EQ(students[1].getVardas(), "Benas");
    EXPECT_EQ(students[2].getVardas(), "Dominyka");
}

TEST(FileManagerTest, ReadFile) {

    const string filename = "test_input.txt";
    FileManager::genfailas(filename, 10);


    vector<Stud> students;
    FileManager::nuskaitymas(students, filename);

    EXPECT_EQ(students.size(), 10);
}
