# SecondProject

# Struct ir Class spartos testavimas

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


# Eksperimentas Struct ir Class su O1, O2, O3 flag'ais

|Flag           | exe dydis  | greitis  | 
|---------------|------------|----------|
|**O1 Class**   | 77K        | 2m 53s   |
|**O2 Class**   | 80K        | 3m 1s    |
|**O3 Class**   | 102K       | 2m 57s   |
|**O1 Struct**  | 85K        | 1m 56s   |
|**O2 Struct**  | 88K        | 1m 58s   |
|**O3 Struct**  | 103K       | 1m 57s   | 

# Išvada

Greičiausiai veikė Struct su tiek su O1, tiek su O2, tiek su O3, bet užemė daugiau vietos nei Class. Class greičiausiai veikė su O3, bet užemė daugiau vietos nei O1 ir O2. 


