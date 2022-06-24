#include <iostream>
#include <conio.h>
#include <string>
#include "ListaDoblementeEnlazada.h"
#include "Cliente.h"
using namespace std;
void Merge(DoubleLinkedList<Cliente>& A1, DoubleLinkedList<Cliente>& A2, DoubleLinkedList<Cliente>& A) {
    int i = 0, j = 0, k = 0;
    int mitad = A.Length() / 2;
    while (i < mitad && j < A.Length() - mitad) {
        if (A1.at(i).getNombre() < A2.at(j).getNombre()) {
            A.at(k).getNombre() = A1.at(i).getNombre();
            i++; k++;
        }
        else {
            A.at(k).getNombre() = A2.at(j).getNombre();
            j++; k++;
        }
    }
    while (i < mitad) {
        A.at(k).getNombre() = A1.at(i).getNombre();
        i++; k++;
    }
    while (j < A.Length() - mitad) {
        A.at(k).getNombre() = A2.at(j).getNombre();
        j++; k++;
    }
}
void mergeSort(DoubleLinkedList<Cliente>& A, int n) {
    int n = A.Length();
    if (A.Length() > 1) {
        int mitad = A.Length() / 2;
        int m = mitad;
        DoubleLinkedList<Cliente> A1;
        //A1= A.at(m).getNombre();
        DoubleLinkedList<Cliente> A2;
        // A2= [A.Length() - mitad];

        for (int i = 0; i < mitad; i++) {
            A1.at(i).getNombre() = A.at(i).getNombre();
            cout << A1.at(i).getNombre() << endl;
        }
        cout << endl;
        for (int i = mitad; i < n; i++) {
            A2.at(i - mitad).getNombre() = A.at(i).getNombre();
            cout << A2.at(i - mitad).getNombre() << endl;
        }
        cout << endl;
        mergeSort(A1, mitad);
        mergeSort(A2, n - mitad);
        Merge(A1, A2, A);
    }
}

