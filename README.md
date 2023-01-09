# ProjektCpp
W podanym programie znajduje się konstruktor Matrix(int rows, int cols), który umożliwia utworzenie macierzy o podanych liczbie wierszy i kolumn. Konstruktor ten jest wywoływany w linii Matrix m(rows, cols), gdzie rows i cols to zmienne, które są wczytywane od użytkownika.

Klasa Matrix pozwala na tworzenie obiektów przechowujących macierze. W podanym programie obiekt o nazwie m jest tworzony w linii Matrix m(rows, cols), gdzie rows i cols są zmiennymi, które są wczytywane od użytkownika. Obiekt ten przechowuje macierz o liczbie wierszy i kolumn określonej przez użytkownika.

Klasa Matrix zawiera również kilka metod umożliwiających manipulowanie macierzą, takich jak na przykład operator indeksowania operator(), który pozwala na dostęp do poszczególnych elementów macierzy za pomocą notacji m(i, j), gdzie i i j to indeksy wiersza i kolumny odpowiednio. Klasa ta również zawiera metodę print(), która pozwala na wyświetlenie macierzy na ekranie.

Metoda transpose() zwraca nowy obiekt macierzy, który jest transpozycją macierzy, na której jest wywoływana. W głównej funkcji programu macierz po transpozycji jest wyświetlana na ekranie.

Metoda reverse() zwraca nowy obiekt macierzy, który jest odwróconą macierzą, na której jest wywoływana. W głównej funkcji programu macierz po odwróceniu jest wyświetlana na ekranie.

Metoda determinant() oblicza wyznacznik podanej macierzy za pomocą algorytmu Laplace'a. Algorytm ten polega na wyliczeniu sumy iloczynów elementów na głównej przekątnej macierzy, pomnożonych przez odpowiednie współczynniki (-1)^n (gdzie n to numer elementu), oraz wartości wyznaczników tzw. macierzy podrzędnych, czyli macierzy o wymiarach o 1 mniejszych niż macierz wejściowa, pochodzących z macierzy wejściowej po usunięciu pierwszego wiersza i n-tej kolumny (gdzie n to numer elementu).
Dla macierzy kwadratowej o rozmiarze 1x1, wyznacznik jest równy elementowi na przekątnej. Dla macierzy o rozmiarze 2x2, wyznacznik jest obliczany według wzoru a*d - b*c, gdzie a, b, c i d to elementy macierzy (a to element w lewym górnym rogu, b to element w lewym dolnym rogu itd.). Dla macierzy o rozmiarze 3x3, wyznacznik jest obliczany według wzoru a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h, gdzie a, b, c, d, e, f, g, h i i to elementy macierzy (a to element w lewym górnym rogu, b to element w środkowym górnym rogu itd.).

