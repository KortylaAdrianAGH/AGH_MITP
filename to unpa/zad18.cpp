#include <iostream>
#include <cstring>
#include "sort.h"
#include "date.h"
using namespace std;

void printUsecase() {
    cout << "usage: zad16 -n name";
    cout << endl << endl;
    cout << "name: " << endl;
    cout << "bubble    - for bubble sort" << endl;
    cout << "selection - for selection sort" << endl;
}

int comparInt(void* a, void* b) {

    int* ax = (int*)a;
    int* bx = (int*)b;

    return (*ax - *bx);

}

int comparDate(void * a, void * b) {

    Date x = *(Date*)a;
    Date y = *(Date*)b;

    cout << x.day << "." << x.month << "." << x.year;
    cout << " :: ";
    cout << y.day << "." << y.month << "." << y.year;

    if ((x.year =! y.year)) {
        return x.year - y.year;
    } else if ((x.month =! y.month)) {
        return x.month - y.month;
    } else {
        return (x.day - y.day);
    }

}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printUsecase();
        return 0;
    } else {
        if (strcmp(argv[1], "-n")) {
            printUsecase();
            return 0;
        } else {
            if (strcmp(argv[2], "bubble") && strcmp(argv[2], "selection")) {
                printUsecase();
                return 0;
            }
        }
    }

    int size;
    cout << "Podaj wymiar swojej tablicy: ";
    cin >> size;

    int choice;

    cout << "Co chcesz sortowa-^-: " << endl;
    cout << "1. Int" << endl << "2. Daty" << endl;
    cout << "Wybor: ";

    cin >> choice;

    int* tab;
    Date* tabDate;

    if (choice == 1) {
        tab = new int[size];

        cout << "Podaj elementy: ";
        for (int i = 0; i < size; i++) {
            cin >> tab[i];
        }

        if (!strcmp(argv[2], "bubble")) {
            cout << "Wybrano BubbleSort: " << endl;
            bubbleSort(tab, size, sizeof(int), comparInt);
        } else {
          cout << "Wybrano SelectionSort: " << endl;
            selectionSort(tab, size, sizeof(int), comparInt);
        }

        cout << endl << endl;

        cout << "Sorted: ";
        for (int i = 0; i < size; i++) {
            cout << tab[i] << " ";
        }

        delete [] tab;
    } else if (choice == 2) {
        tabDate = new Date[size];

        cout << "Podaj elementy: " << endl;
        for (int i = 0; i < size; i++) {
            cout << i+1 << ": ";
            cin >> tabDate[i].day;
            cin >> tabDate[i].month;
            cin >> tabDate[i].year;
        }

        if (!strcmp(argv[2], "bubble")) {
            cout << "Wybrano BubbleSort: " << endl;
            bubbleSort(tabDate, size, sizeof(Date), comparDate);
        } else {
            cout << "Wybrano SelectionSort: " << endl;
            selectionSort(tabDate, size, sizeof(Date), comparDate);
       }

        cout << endl << endl;

        cout << "Sorted: " << endl;
        for (int i = 0; i < size; i++) {
            cout << tabDate[i].day << " " << tabDate[i].month << " " << tabDate[i].year;
            cout << endl;
        }

        delete [] tabDate;
    } else {
        cout << "Error :)";
        return 0;
    }

    cout << endl;

    return 0;

}

