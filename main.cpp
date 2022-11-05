// main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "DoublyLinkedList.hpp"
#include "Misc.hpp"

using namespace std;

void test_1() {
    // TEST Lista 1
    DoublyLinkedList<Car>* list1 = new DoublyLinkedList<Car>();
	
    const size_t n = 10000;
	
    Car cars[n];
	
    clock_t time1 = clock();
	
    for (int i = 0; i < n; i++) {
        list1->addHead(cars[i]);
    }
	
    clock_t time2 = clock();

    double time = (double)(time2 - time1) / CLOCKS_PER_SEC;

    cout << fixed;
    cout << setprecision(5);
    cout << "Czas dodawania " << n << " elementow: " << time << " s" << endl;
    cout << "Czas dodawania jednego elementu: " << (time / n)*1000 << " ms" << endl;

    list1->clearList();
    delete list1;
}

void test_2() {
    // TEST Lista 2
    DoublyLinkedList<Car*>* list2 = new DoublyLinkedList<Car*>();
	
    const size_t n = 100000;

    clock_t time1 = clock();

    for (int i = 0; i < n; i++) {
        list2->addHead(new Car());
    }

    clock_t time2 = clock();

    double time = (double)(time2 - time1) / CLOCKS_PER_SEC;

    cout << fixed;
    cout << setprecision(5);
    cout << "Czas dodawania " << n << " elementow: " << time << " s" << endl;
    cout << "Czas dodawania jednego elementu: " << (time / n)*1000 << " ms" << endl;

    list2->clearList();
    delete list2;
}

void main_test()
{
    DoublyLinkedList<Car>* list1 = new DoublyLinkedList<Car>();
    DoublyLinkedList<Car*>* list2 = new DoublyLinkedList<Car*>();
	
    char option;
    bool quit = false;

    do {
        cout << "==============================" << endl;
        cout << "1: Dodaj od poczatku" << endl; // B
        cout << "2: Dodaj od konca" << endl; // A
        cout << "3: Usun z poczatku" << endl; // D
        cout << "4: Usun z konca" << endl; // C
        cout << "5: Wyswietl dane i-tego elementu" << endl; // E
        cout << "6: Zmien dane i-tego elementu" << endl; // F
        cout << "7: Wyszukaj element" << endl; // G
        cout << "8: Wyszukaj i usun element" << endl; // H
        cout << "9: Dodaj z wymuszeniem porzadku BRAK :(" << endl; // I - brak
        cout << "0: Wyczysc liste" << endl; // J
        cout << "P: Wyswietl liste" << endl; // K
        cout << "X: Wyjdz" << endl;
        cout << "==============================" << endl;
        cout << ">> ";
        cin >> option;
        
        switch (option) {
        case '1':
        {
            Car cars[10];
			for (int i = 0; i < 10; i++) {
				list1->addHead(cars[i]);
			}
			
            for (int i = 0; i < 10; i++) {
				list2->addHead(new Car());
            }
            break;
        }

        case '2':
        {
            Car temp1;
            list1->addTail(temp1);
			
            list2->addTail(new Car());
			
            break;
        }

        case '3':
        {
            list1->popHead();
            list2->popHead();
            break;
        }

        case '4':
        {
            list1->popTail();
            list2->popTail();
            break;
        }

        case '5':
        {
            cout << list1->getByIndex(2)->value;
            cout << list2->getByIndex(2)->value;
            break;
        }

        case '6':
        {
            Car temp1;
            temp1.manufacturer = "TestManufacturer_1";
            temp1.model = "TestModel_1";
            temp1.year = 2001;
            list1->changeDataAtIndex(2, temp1);
            Car* temp2 = new Car();
            temp2->manufacturer = "TestManufacturer_2";
            temp2->model = "TestModel_2";
            temp2->year = 2002;
            list2->changeDataAtIndex(2, temp2);
			
            break;
        }

        case '7':
        {
            Car temp1;
            temp1.manufacturer = "TestManufacturer_1";
            temp1.model = "TestModel_1";
            temp1.year = 2001;
			
			Car* temp2 = new Car();
            temp2->manufacturer = "TestManufacturer_2";
            temp2->model = "TestModel_2";
            temp2->year = 2002;
			
            cout << "Adres: " << list1->findByValues(temp1) << " " << list1->node_to_string(list1->findByValues(temp1)) << endl;
            cout << "Adres: " << list2->findByValues(temp2, true) << " " << list2->node_to_string(list2->findByValues(temp2, true)) << endl; 
			
            break;
        }

        case '8':
        {
            Car temp1;
            temp1.manufacturer = "TestManufacturer_1";
            temp1.model = "TestModel_1";
            temp1.year = 2001;

            Car* temp2 = new Car();
            temp2->manufacturer = "TestManufacturer_2";
            temp2->model = "TestModel_2";
            temp2->year = 2002;
			
            if (list1->findAndDelete(temp1)) {
                cout << "Usuwanie 1 powiodlo sie" << endl;
            }
            else {
                cout << "Usuwanie 1 nie powiodlo sie";
            }

            if (list2->findAndDelete(temp2, true)) {
                cout << "Usuwanie 2 powiodlo sie" << endl;
            }
            else {
                cout << "Usuwanie 2 nie powiodlo sie";
            }

            break;
        }

        case '0':
        {
            list1->clearList();
            list2->clearList();
            break;
        }

        case 'p': case 'P':
        {
             
            colors('r'); cout << list1->list_to_string(); colors('x'); cout << "#####" << endl; 
            colors('b'); cout << list2->list_to_string(); colors('x'); cout << endl;
            break;
        }

        case 'x': case 'X':
        {
            quit = true;
            break;
        }

        default:
            cout << "Zla opcja" << endl;
            break;
        }

    } while (!quit);

    cout << "Zakonczono program. Zamykanie.";
	
}

int main() {
    
    colors('r');
    test_1();
    cout << endl;
    cout << setprecision(3);
    colors('c');
    test_2();
    colors('x');
    
    //main_test();
    return 0;
}
