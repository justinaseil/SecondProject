# Mano Projektas

Ši programa skirta darbui su studentų duomenimis. Ji leidžia įvesti studentų vardus, pavardes, egzamino ir namų darbų rezultatus. Įvedant galima pasirinkti, kad pažymius sugeneruotų programa. Duomenis galima nuskaityti iš failo, o neturint failų juos sugeneruoti su 1000, 10000, 100000, 1000000, 10000000 įrašų. Norint patikrinti programos spartą, galima testuoti programą. Programa testuoti galima tiek su veiktor tiek su list konteineriais. Programa suskaičiuoja studento vidurkį ir mediana, tada studentas gali pasirinti, ar galutinis rezultatas bus skaičiuojamas su mediana, ar su vidurkiu ir apskaičiuojama tokiu būdu: galutinis rezultatas = 0.4 * vidurkis/mediana + 0.6 * egzaminas. Taip pat programa skirsto studentus į dvi kategorijas – "kietekai" (studentai, kurių galutinis pažymys ≥ 5) ir "vargšiukai" (galutinis pažymys < 5) ir tada surušiuoja pagal vardo raides abėcėlės tvarka.

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

Darbe naudojamos klasės: Bazinė klasė - Žmogus ir iš jos išvestinė klasė - Stud. Atskiros klasės: Rusiavimas, FileManager
  
## Pavyzdys, kaip atrodo naudojimasis programa:

<img width="487" alt="Screenshot 2024-12-06 at 19 02 58" src="https://github.com/user-attachments/assets/9ef7fc13-b29a-4790-8957-3b57737446ee">

# Testavimo sistema

## CPU
- **Modelis**: Intel(R) Xeon(R) CPU E5-2620 0 @ 2.00GHz
- **Architektūra**: x86_64
- **Branduolių skaičius**: 12
- **Dažnis**: 2.00 GHz

## RAM
- **Bendra**: 8 GiB
- **Naudojama**: 474 MiB
- **Laiva**: 6.5 GiB

## HHD
- **Magnetinis HHD**

  
# V1.1

## Struct ir Class spartos testavimas

Testuojant buvo paimtas 3 testavimų vidurkis, buvo naudojamas vector konteineris ir testuojama su 1000000 ir 10000000 įrašais. Tiek su Struct, tiek su Class buvo naudojami tie patys failais, spartos analizės patikimumui.

## Testavimas su 1000000 įrašų

|Veiksmas                                | Naudojant Struct | Naudojant Class | Kuris greitesnis? |
|----------------------------------------|------------------|-----------------|-------------------|
|**Failo nuskaitymas**                   | 5.2562 s         | 3.7343 s        | Class             |
|**Rūšiavimas į dvi grupes**             | 0.5238 s         | 0.1805 s        | Class             |
|**Rūšiavimas "kietekų" pagal vardus**   | 3.0686 s         | 2.3357 s        | Class             |
|**Rūšiavimas "vargšiukų" pagal vardus** | 2.0412 s         | 1.5718 s        | Class             |
|**Įrašymas į failą "kietetai.txt"**     | 2.6990 s         | 2.2464 s        | Class             |
|**Įrašymas į failą "vargšiukai.txt"**   | 2.4024 s         | 1.7632 s        | Class             |
|**Bendras**                             | 16.3484 s        | 12.0184 s       | Class             |

## Testavimas su 10000000 įrašų

|Veiksmas                                | Naudojant Struct | Naudojant Class | Kuris greitesnis? |
|----------------------------------------|------------------|-----------------|-------------------|
|**Failo nuskaitymas**                   | 54.6492 s        | 37.6397 s       | Class             |
|**Rūšiavimas į dvi grupes**             | 5.4236 s         | 1.5991 s        | Class             |
|**Rūšiavimas "kietekų" pagal vardus**   | 36.4022 s        | 34.3908 s       | Class             |
|**Rūšiavimas "vargšiukų" pagal vardus** | 24.3786 s        | 19.5556 s       | Class             |
|**Įrašymas į failą "kietetai.txt"**     | 27.1734 s        | 21.9323 s       | Class             |
|**Įrašymas į failą "vargšiukai.txt"**   | 19.1892 s        | 16.1792 s       | Class             |
|**Bendras**                             | 170.831 s        | 133.119 s       | Class             |

## Išvada

Matome, kad vienareikšmiškai greičiau veikė Class.


## Eksperimentas Struct ir Class su O1, O2, O3 flag'ais

|Flag           | exe dydis  | greitis  | 
|---------------|------------|----------|
|**O1 Class**   | 77K        | 2m 53s   |
|**O2 Class**   | 80K        | 3m 1s    |
|**O3 Class**   | 102K       | 2m 57s   |
|**O1 Struct**  | 85K        | 1m 56s   |
|**O2 Struct**  | 88K        | 1m 58s   |
|**O3 Struct**  | 103K       | 1m 57s   | 

## Išvada

Greičiausiai veikė Struct su tiek su O1, tiek su O2, tiek su O3, bet užemė daugiau vietos nei Class. Class greičiausiai veikė su O3, bet užemė daugiau vietos nei O1 ir O2. 

# V1.2

Šioje versijoje buvo realizuotu "Rule of Three" ir išvesties, įvesties operatoriai turimai Stud klasei.

# V1.5

Versijoje v1.5 buvo sukurta bazinė (abstrakti) klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Studentas. Užtikrinimui,kad klasė būtų abstrakti buvo naudoja funkcija "abstraktas".

Norint įsitikinti, kad Žmogus yra abstrakti klasė buvo pabandyta sukurti objektą iš klasės žmogus:
<img width="1080" alt="Screenshot 2024-12-13 at 19 11 02" src="https://github.com/user-attachments/assets/34b7dfcd-8927-4549-9ee1-ef92ed331471" />

Matome, kad objekto sukurti nepavyko, todėl matome, kad klasė žmogus yra abstrakti.
