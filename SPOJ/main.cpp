#include <iostream>
#include <iomanip>
#include <fstream>
#include "box.h"
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono;
using namespace std;
const long int n = 962902;


/******************************************************************************************************************
 **********************************************    QUICKSORT   ****************************************************
 *****************************************************************************************************************/


/*
 * Podzial tablicy na trzy podtablce: mniejsza, rowna, wieksza od pivota
 */
void partition(Who *tab, long int low, long int high, long int& i, long int& j)
{
    // okreslamy ineeksy i, j ktore sluza do przeszukiwania tablicy
    i = low - 1, j = high;

    //indeksy ktore sa pomocne przy zamianie elementow
    // przechowuja dane na koniec ile jest elementow mnieszych i wiekszych od pivota
    long int smaller = low - 1, bigger = high;

    //pivot to ostatni element w danej tablicy
    int pivot = tab[high].rating;

    while (true) {
        /*
         * Szukamy elemenu od poczatku wiekszego badz rownego pivotowi
         */
        while (tab[++i].rating < pivot)
            ;

        /*
         * Szukamy elementu od konca mniejszego badz rownego pivotowi
         */
        while (pivot < tab[--j].rating)
            if (j == low)
                break;

        /*
         * Jesli indesky sie minely to koniec
         */
        if (i >= j)
            break;

        /*
         * Zamiana elementu wiekszego lub rownego, z mniejszym lub rowntm
         */
        swap(tab[i], tab[j]);

        /*
         * Jesli element ktory zostal przed chwila zamieniony z przodu jest rowny pivotowi to ten element jest zamieniany
         * W takiej sytuacju elementy == pivot sa z przodu a mniesjsze pozniej
         */
        if (tab[i].rating == pivot) {
            smaller++;
            swap(tab[bigger], tab[i]);
        }

        /*
         * Podobna sytuacja
         * Jesli element ktory zostal przed chwila zamieniony na koncu jest rowny pivotowi to ten element jest zamieniany
         * W takiej sytuacju elementy == pivot sa na koncu a wikesze wczesniej
         */
        if (tab[j].rating == pivot) {
            bigger--;
            swap(tab[j], tab[bigger]);
        }
    }

    /*
     * Zamiana pivota jesli indeksy i,j sie minely
     * Mamay teraz sytuacje taka:
     *      *  oznacza elementy rowne pivotowi
     *      -  oznacza elementy mniejsze od pivota
     *      +  oznacza elementy wieksze od pivota
     * Maly scheamt
     *      ******----+++++******
     *           p   ji    q
     *
     * W takiej sytacji wiemy ile jest mniejszych elemntow i ile wiekszych
     *      inforamcja ta przechowywana jest w indeksach smaller i bigger
     *
     */

    swap(tab[i], tab[high]);

    /*
     * Przesuwamy elementy mniesze na poczatek tablicy
     */
    j = i - 1;
    for (int k = low; k < smaller; k++, j--)
        swap(tab[k], tab[j]);

    /*
     * Przesuwamy elementy wieksze na koniec tablicy
     */
    i = i + 1;
    for (int k = high - 1; k > bigger; k--, i++)
        swap(tab[i], tab[k]);
}

/*
 * Algorytm quicksorta
 */
void quicksort(Who *tab, long int low, long int high)
{
    /*
     * sprawdzenie czy tablica jest jest wisza od 1
     */
    if (high <= low)
        return;

    //liczby przechowujce indeks poczatkowy i koncowy podtablic
    long int i, j;

    /*
     *  Szukmay elemntow mniejszych i wiekszych od pivota
     *  Jesli elementy pivta sie powtarzaja, ustawiane sa w srodku
     *  Pozwala nam to znalezc ilosc elementow mnieszych, wiekszych
     *      j - numer indeksu gdzie w tablicy koncza sie elementy mniejsze od pivota
     *      i - numer indeksu gdzie zaczynaja sie elementy wieksze od pivota
     *  Czyli dzielimy tablice na 3 mniejsze podtablice operujac caly czas na glownej
     *      Tab1 - elemnty mniesze od pivota
     *      Tab2 - elemnty rowne pivot
     *      Tab3 - elementy wieksze od pivota
     *      Ale tab = Tab1 + Tab2 + Tab3;
     *  Tak podzilona tablice glowna, sortujemy na mniejszych przedzialach
     *  zmnniejszajac zloznocs obliczeniowa i ilosc rekurencji
     */

    partition(tab, low, high,i, j);

    //rekurencja quicksorta
    quicksort(tab, low, j);
    quicksort(tab, i, high);
}

/******************************************************************************************************************
 **********************************************    MERGESORT   ****************************************************
 *****************************************************************************************************************/

/*
 * Glowna funkcja mergesorta
 *
 * Zadniczo "laczymy" podtablice
 */
void merge(Who *tab, int low, int mid1, int mid2, int high, Who *tabDuplicate)
{
    /*
     * Pomocnicze indeksy
     */
    int i = low, j = mid1, k = mid2, l = low;

    /*
     * Dopoki nie wyjdzemy poza zakres operujemy na tablicy
     * Wsrod 3 podtablic wyszukujemy najmnijszy element i ustawiamy na odpowiednim miejscu
     */
    while ((i < mid1) && (j < mid2) && (k < high)){
        if(tab[i].rating < tab[j].rating){
            if(tab[i].rating < tab[k].rating){
                tabDuplicate[l].rating = tab[i].rating;
                tabDuplicate[l].title = tab[i].title;
                l++;i++;
            }
            else{
                tabDuplicate[l].rating = tab[k].rating;
                tabDuplicate[l].title = tab[k].title;
                l++;k++;
            }
        }
        else{
            if(tab[j].rating < tab[k].rating){
                tabDuplicate[l].rating = tab[j].rating;
                tabDuplicate[l].title = tab[j].title;
                l++;j++;
            }
            else{
                tabDuplicate[l].rating = tab[k].rating;
                tabDuplicate[l].title = tab[k].title;
                l++;k++;
            }
        }
    }

    /*
     * Tablice moga byc nierowno podzielne
     */

    /*
     *  Przypadek 1 i 2
     */
    while ((i < mid1) && (j < mid2)){
        if(tab[i].rating < tab[j].rating){
            tabDuplicate[l].rating = tab[i].rating;
            tabDuplicate[l].title = tab[i].title;
            l++;i++;
        }
        else{
            tabDuplicate[l].rating = tab[j].rating;
            tabDuplicate[l].title = tab[j].title;
            l++;j++;
        }
    }

    /*
     *  Przypadek 2 i 3
     */
    while ((j < mid2) && (k < high)){
        if(tab[j].rating < tab[k].rating){
            tabDuplicate[l].rating = tab[j].rating;
            tabDuplicate[l].title = tab[j].title;
            l++;j++;
        }
        else{
            tabDuplicate[l].rating = tab[k].rating;
            tabDuplicate[l].title = tab[k].title;
            l++;k++;
        }
    }

    /*
     *  Przypadek 1 i 3
     */
    while ((i < mid1) && (k < high)){
        if(tab[i].rating < tab[k].rating){
            tabDuplicate[l].rating = tab[i].rating;
            tabDuplicate[l].title = tab[i].title;
            l++;i++;
        }
        else{
            tabDuplicate[l].rating = tab[k].rating;
            tabDuplicate[l].title = tab[k].title;
            l++;k++;
        }
    }


    /*
     * Kopiowanie
     */
    while (i < mid1){
        tabDuplicate[l].rating = tab[i].rating;
        tabDuplicate[l].title = tab[i].title;
        l++;i++;
    }
    while (j < mid2){
        tabDuplicate[l].rating = tab[j].rating;
        tabDuplicate[l].title = tab[j].title;
        l++;j++;
    }
    while (k < high){
        tabDuplicate[l].rating = tab[k].rating;
        tabDuplicate[l].title = tab[k].title;
        l++;k++;
    }
}

/*
 * Funkcja dzielaca na mniejsze funkcje
 */
void devide(Who *tabDuplicate, long int low, long int high, Who *tab)
{
    /*
     * Spradzamy czy funkcja nie jest jednoelementowa
     */
    if (high - low < 2)
        return;

    /*
     * Towrzymy granice dzielenia tablicy
     */
    long int mid1 = low + ((high - low) / 3);
    long int mid2 = low + 2 * ((high - low) / 3) + 1;

    /*
     * rekurencyjnie dizelimy tablcie na mniejsze podtablice
     */
    devide(tab, low, mid1, tabDuplicate);
    devide(tab, mid1, mid2, tabDuplicate);
    devide(tab, mid2, high, tabDuplicate);

    /*
     * Laczymy podzielne tablice w odpowiedniej kolejnosci
     */
    merge(tab, low, mid1, mid2, high, tabDuplicate);
}

/*
 * Przedalgorytm mergesorta
 */
void mergeSort(Who *tab, int n)
{

    /*
     * Tworzymy dynamiczna tablice glowne tablicy
     */
    Who  *tabDuplicate = new Who[n];

    /*
     * Kopiujejmy elementy z glownej do kopii
     */
    for (int i = 0; i < n; i++) {
        tabDuplicate[i].rating = tab[i].rating;
        tabDuplicate[i].title = tab[i].title;
    }

    /*
     * Funkcja sortujaca (dzielac)
     */
    devide(tabDuplicate, 0, n, tab);

    /*
     * Przypisywanie posortowanych w dupikacie do origanlow
     */
    for (int i = 0; i < n; i++) {
        tab[i].rating = tabDuplicate[i].rating;
        tab[i].title = tabDuplicate[i].title;
    }
}

/******************************************************************************************************************
 **********************************************    BUCKETSORT   ***************************************************
 *****************************************************************************************************************/
/*
 * Algorytm bucketsorta
 */
void bucketSort(Who *tab, long int howMany) {
    /*
     * Szukamy minimalnej i maksymalnej wartosci w tablicy
     */
    long int minValue = tab[0].rating, maxValue = tab[0].rating;

    for (int i = 1; i < howMany; i++){
        if (tab[i].rating > maxValue)
            maxValue = tab[i].rating;
        if (tab[i].rating < minValue)
            minValue = tab[i].rating;
    }

    /*
     *      bucketLength - ile koszykow utowrzyc
     */
    int bucketLength = maxValue - minValue + 1;
    /*
     * Dynamiaczna tablica vectora bucket
     */
    vector<Who>* bucket = new vector<Who>[bucketLength];
    for (int i = 0; i < bucketLength; i++)
        bucket[i] = vector<Who>();


    /*
     * Wrzucamy do koszykow odpowiednie wartosci
     */
    for (long int i = 0; i < howMany; i++)
        bucket[tab[i].rating - minValue].push_back(tab[i]);

    /*
     * kolejne koszyki sa laczone i ich wartosci przypiswyane do tablicy
     */
    long int k = 0;
    for (int i = 0; i < bucketLength; i++){
        if (bucket[i].size() > 0){
            for (long int j = 0; j < bucket[i].size(); j++, k++){
                tab[k] = bucket[i][j];
            }
        }
    }
    delete [] bucket;
}

int main() {

    Who *tab = new Who[n];

    ifstream plik;
    plik.open("zapis.txt");

    string title, numberString, ratingString;

    int rating;
    for (long long int i = 0; i < n; ++i) {
        getline(plik, numberString, ',');
        getline(plik, title, '\n');

        for (int j = title.length() - 1; j > 0; --j) {
            ratingString = title;
            if (title[j] == ',') {
                title.erase(j, title.length() - 1);
                ratingString.erase(0, j + 1);
                break;
            }

        }
        rating = stoi(ratingString);
        tab[i].addWho(title, rating);


    }

    auto start = high_resolution_clock::now();

    //1bucketSort(tab,n);
    //quicksort(tab, 0, n - 1);
    mergeSort(tab,n);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " sec" << endl;
    delete[] tab;

}