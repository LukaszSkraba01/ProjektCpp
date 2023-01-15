# ProjektCpp - P4 | Łukasz Skraba i Adrian Ruchała |
# Macierze | Programowanie Zaawansowane | 2022/3|
W podanym programie znajduje się konstruktor Matrix(int rows, int cols), który umożliwia utworzenie macierzy o podanych liczbie wierszy i kolumn. Konstruktor ten jest wywoływany w linii Matrix m(rows, cols), gdzie rows i cols to zmienne, które są wczytywane od użytkownika.

Klasa Matrix pozwala na tworzenie obiektów przechowujących macierze. W podanym programie obiekt o nazwie m jest tworzony w linii Matrix m(rows, cols), gdzie rows i cols są zmiennymi, które są wczytywane od użytkownika. Obiekt ten przechowuje macierz o liczbie wierszy i kolumn określonej przez użytkownika.

Klasa Matrix zawiera również kilka metod umożliwiających manipulowanie macierzą, takich jak na przykład operator indeksowania operator(), który pozwala na dostęp do poszczególnych elementów macierzy za pomocą notacji m(i, j), gdzie i i j to indeksy wiersza i kolumny odpowiednio. Klasa ta również zawiera metodę print(), która pozwala na wyświetlenie macierzy na ekranie.

Metoda transpose() zwraca nowy obiekt macierzy, który jest transpozycją macierzy, na której jest wywoływana. W głównej funkcji programu macierz po transpozycji jest wyświetlana na ekranie.

Metoda reverse() zwraca nowy obiekt macierzy, który jest odwrotną macierzą, na której jest wywoływana. W głównej funkcji programu macierz po odwróceniu jest wyświetlana na ekranie.
Macierz odwrotna jest macierzą, która dla danej macierzy A spełnia warunek: A * A^-1 = A^-1 * A = I (gdzie I jest macierzą jednostkową).

Jeśli A jest macierzą kwadratową o wymiarze n x n, to wzór na macierz odwrotną jest następujący:
A^-1 = 1/det(A) * adj(A)

gdzie det(A) oznacza wyznacznik macierzy A, a adj(A) oznacza macierz przeciwną (adjugat) macierzy A.

-Aby obliczyć macierz przeciwną (adjugat) macierzy A, należy:
-Obliczyć macierz sprzezoną A* (czyli transponować macierz A i zmienić znaki elementów przekątni)
-Dla każdego elementu macierzy sprzezonej A* obliczyć macierz pochodną tego elementu (czyli macierz, w której usunięto wiersz i -kolumnę, w której znajduje się dany element)
-Każdą z obliczonych macierzy pochodnych pomnożyć przez (-1)^(i+j) gdzie i i j to odpowiednio indeksy wiersza i kolumny danego elementu
-Wszystkie obliczone macierze połączyć tworząc macierz przeciwną (adjugat) macierzy A

Metoda determinant() oblicza wyznacznik podanej macierzy za pomocą algorytmu Laplace'a. Algorytm ten polega na wyliczeniu sumy iloczynów elementów na głównej przekątnej macierzy, pomnożonych przez odpowiednie współczynniki (-1)^n (gdzie n to numer elementu), oraz wartości wyznaczników tzw. macierzy podrzędnych, czyli macierzy o wymiarach o 1 mniejszych niż macierz wejściowa, pochodzących z macierzy wejściowej po usunięciu pierwszego wiersza i n-tej kolumny (gdzie n to numer elementu).
Dla macierzy kwadratowej o rozmiarze 1x1, wyznacznik jest równy elementowi na przekątnej. Dla macierzy o rozmiarze 2x2, wyznacznik jest obliczany według wzoru a*d - b*c, gdzie a, b, c i d to elementy macierzy (a to element w lewym górnym rogu, b to element w lewym dolnym rogu itd.). Dla macierzy o rozmiarze 3x3, wyznacznik jest obliczany według wzoru a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h, gdzie a, b, c, d, e, f, g, h i i to elementy macierzy (a to element w lewym górnym rogu, b to element w środkowym górnym rogu itd.).

Metoda degree() oblicza stopień podanej macierzy. Stopień macierzy to maksymalna liczba rzędów wierszy lub kolumn, które nie są zerowe. Aby to obliczyć, metoda przechodzi przez wszystkie wiersze i sprawdza, czy wszystkie elementy w wierszu są równe zero. Jeśli nie, to zwiększa licznik wierszy niezerowych. Następnie przechodzi przez wszystkie kolumny i robi to samo dla kolumn. Na końcu zwraca maksymalną liczbę wierszy lub kolumn niezerowych.

Metoda algebraic_complement() oblicza dopełnienie algebraiczne podanej macierzy. Dopełnienie algebraiczne to element macierzy, który jest wyznaczany przez wzór C(i,j) = (-1)^(i+j) * M(i,j), gdzie C to macierz dopełnień, a M to macierz wejściowa.
Metoda sprawdza, czy macierz wejściowa jest kwadratowa. Jeśli nie jest, to wypisuje komunikat o błędzie i zwraca macierz pustą (o rozmiarze 0x0). Jeśli macierz jest kwadratowa, to tworzy nową macierz o takim samym rozmiarze i wypełnia ją wartościami dopełnień algebraicznych dla każdego elementu macierzy wejściowej. Następnie zwraca tę macierz.