# Mano Projektas

Ši programa skirta darbui su studentų duomenimis. Ji leidžia įvesti studentų vardus, pavardes, egzamino ir namų darbų rezultatus. Įvedant galima pasirinkti, kad pažymius sugeneruotų programa. Duomenis galima nuskaityti iš failo, o neturint failų juos sugeneruoti su 1000, 10000, 100000, 1000000, 10000000 įrašų. Norint patikrinti programos spartą, galima testuoti programą. Programa testuoti galima tiek su veiktor tiek su list konteineriais. Programa suskaičiuoja studento vidurkį ir mediana, tada studentas gali pasirinti, ar galutinis rezultatas bus skaičiuojamas su mediana, ar su vidurkiu ir apskaičiuojama tokiu būdu: galutinis rezultatas = 0.4 * vidurkis/mediana + 0.6 * egzaminas. Taip pat programa skirsto studentus į dvi kategorijas – "kietekai" (studentai, kurių galutinis pažymys ≥ 5) ir "vargšiukai" (galutinis pažymys < 5) ir tada suručiuoja pagal vardo raides abėcėlės tvarka.

Programa apima šiuos pagrindinius funkcionalumus:
1. **Duomenų įvestis:**
   * Rankiniu būdu (vartotojas įveda kiekvieno studento duomenis per konsolę). Jai naudojamas įvesties operatorius;
   * Automatiniu būdu (programa sugeneruoja atsitiktinius duomenis). Naudojama funkcija: void Stud::autom();
    * Skaitymas iš failo. Naudojama static void nuskaitymas(Container& students, const string& filename); funkcija iš FileManager klasės.
2. **Duomenų išvestis:**
    * Į konsolę (rodo "kietekai“ lentelę ir "vargšiukai“ lentelę) čia naudojama ir išvedimo operatorius.
    * Į failus (įrašoma į kietekai.txt ir vargsiukai.txt). Naudojama funkcija static void ratefailas(const Container& students, const string& filename, const string& title) iš klasės FileManager.
3. **Galutinio pažymio skaičiavimas:**
    * Pagal vidurkį - void Stud::galutinisvid();
    * Pagal medianą - void Stud::galutinismed()
4. **Duomenų rūšiavimas:**
    * Skirstymas į "kietekus" (kai galutinis pažymys >5) ir "vargšiukus“ (galutinis pažymys < 5). Naudojama funkcija static void rusiavimas(Container& students, Container& vargsiukai, bool suMediana) iš Rusiavimas klasės;
    * Studentų rūšiavimas pagal vardą abėcėlės tvarka. Naudojama funkcija iš Rusiavimas klasės static void sortabc(Container& students);
5. **Failų valdymas:**
    * Didelių failų (pvz., 1000, 10000, 100000, 1000000, 10000000 studentų įrašų) generavimas, nuskaitymas ir testavimas. Naudojamos funkcijos: static void genfailas(const string& filename, int numStudents); static void nuskaitymas(Container& students, const string& filename); void testavimas(Container& students, const string& filename, int numStudents);

<img width="487" alt="Screenshot 2024-12-06 at 19 02 58" src="https://github.com/user-attachments/assets/9ef7fc13-b29a-4790-8957-3b57737446ee">

Versijoje v1.5 bazinė (abstrakti) klasę, skirta bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Stud.
Norint įsitikinti, ar klasė yra abstrakti, reikėtų patikrinti, ar nesusikuria objektas iš klasės Žmogus:

<img width="1080" alt="Screenshot 2024-12-13 at 19 11 02" src="https://github.com/user-attachments/assets/84b4a306-4c6c-4a3a-ae17-e91388bb4e55" />

Pabandžius, kurti objektą iš klasės žmogus, jo sukurti nepavyko, todėl reiškia, kad klasė yra abstrakti.
