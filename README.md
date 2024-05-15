# D. Chińska komórka
> Dostępna pamięć: 32 MB

Niezbyt dawno temu wpisywanie tekstu na telefonie komórkowym wyglądało następująco.

$𝐿$ liter napisanych w kolejności alfabetycznej było podzielone pomiędzy $𝐾$ klawiszy, tj. każdy klawisz zawierał spójny fragment alfabetu. Aby wpisać określoną literę, należało znaleźć klawisz z zadaną literą; jeśli stała ona na nim na $𝑖$-tej pozycji, należało nacisnąć ten klawisz $𝑖$ razy. 

Przykładowo na standardowej komórce $𝐿 = 26$ liter było podzielonych między $𝐾 = 8$ klawiszy. Na klawiszu „$7$” znajdowały się litery $pqrs$. Wprowadzenie litery $r$ wymagało zatem naciśnięcia tego klawisza $3$ razy. 

## Problem
Ostatnio Rząd Chińskiej Republiki Ludowej postanowił wprowadzić na rynek podobną komórkę, tylko nieco większą, żeby zmieściły się na niej wszystkie chińskie symbole (dalej nazywane literami). Litery zostały ponumerowane od $1$ do $𝐿$, pozostało je tylko podzielić pomiędzy $𝐾$ klawiszy. Rząd ChRL ustalił, że układ klawiszy na komórce ma zostać tak zoptymalizowany, żeby pewien określony komunistyczny pamflet dało się wpisać naciskając klawisze minimalną liczbę razy.

## Specyfikacja danych wejściowych
W pierwszym wierszu wejścia znajdują się dwie liczby naturalne $𝐾$ i $𝐿$ oddzielone pojedynczą spacją, spełniające warunki: 
- $1 ⩽ 𝐾 ⩽ 100$, 
- $1 ⩽ 𝐿 ⩽ 10 000$, 
- $𝐾 ⩽ 𝐿$. 

W drugim wierszu znajduje się $𝐿$ liczb naturalnych $𝑓_1, 𝑓_2, . . . , 𝑓_𝐿$ oddzielonych pojedynczym odstępem. Liczba $𝑓_𝑖 ∈ [1, . . . , 1000]$ jest liczbą wystąpień litery $𝑖$ w pamflecie. W siedmiu punktowanych testach zachodzi dodatkowo $𝐿 ⩽ 1000$.

## Specyfikacja danych wyjściowych
W pierwszym wierszu wyjścia Twój program powinien wypisać jedną liczbę naturalną będącą minimalną liczbą naciśnięć klawiszy konieczną do wpisania pamfletu na najlepszej możliwej klawiaturze składającej się z $𝐾$ klawiszy. 

W drugim wierszu wyjścia Twój program powinien wypisać opis takiej klawiatury: $𝐾$ liczb naturalnych $𝑘_1, 𝑘_2, . . . , 𝑘_𝐾$ oddzielonych pojedynczymi odstępami, gdzie $𝑘_𝑗$ jest liczbą liter przypisanych do klawisza $𝑗$. 

Jeśli istnieje wiele optymalnych rozmieszczeń liter na klawiszach, należy wybrać takie, które maksymalizuje liczbę liter na ostatnim klawiszu, wśród nich to, które maksymalizuje liczbę liter na przedostatnim klawiszu itd.

## Przykłady
### Przykład A
Wejście:
```
5 6
2 2 2 2 2 2
```
Wyjście:
```
14
1 1 1 1 2
```
### Przykład B
Wejście:
```
2 4
3 1 1 1
```
Wyjście:
```
8
2 2
```
### Przykład C
Wejście:
```
3 6
3 4 3 1 1 4
```
Wyjście:
```
23
2 3 1
```