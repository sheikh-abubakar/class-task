#include <iostream>
using namespace std;

int stringlen(const char* arr) {
    int l = 0;
    while (arr[l] != '\0') {
        l++;
    }
    return l;
}

char* strcopy(const char* arr1) {
    int l = stringlen(arr1);
    char* arr2 = new char[l + 1];
    for (int i = 0; i < l; i++) {
        arr2[i] = arr1[i];
    }
    arr2[l] = '\0';
    return arr2;
}

struct Book {
    char title[50];
    char author[50];
    int numOfCopies;
};

Book** initializeLibrary(int& numCategories, int*& numBooksinCategory, int*& freeIndexInCategory) {
    cout << "Enter number of categories: ";
    cin >> numCategories;
    Book** library = new Book*[numCategories];
    numBooksinCategory = new int[numCategories];
    freeIndexInCategory = new int[numCategories];

    for (int i = 0; i < numCategories; i++) {
        cout << "Enter number of books in category " << i + 1 << ": ";
        cin >> numBooksinCategory[i];
        library[i] = new Book[numBooksinCategory[i]];
        freeIndexInCategory[i] = 0;
    }
    return library;
}

void addBook(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory) {
    cout << "Enter category number to add: ";
    int cat_num;
    cin >> cat_num;
    if (freeIndexInCategory[cat_num - 1] == numBooksInCategory[cat_num - 1]) {
        cout << "Limit is full";
        return;
    }
    cin >> library[cat_num - 1][freeIndexInCategory[cat_num - 1]].title;
    cin >> library[cat_num - 1][freeIndexInCategory[cat_num - 1]].author;
    cin >> library[cat_num - 1][freeIndexInCategory[cat_num - 1]].numOfCopies;
    freeIndexInCategory[cat_num - 1]++;
}

Book* searchBook(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory) {
    char temp[50];
    cin.ignore(50, '\0');
    cin.getline(temp, 50);
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < freeIndexInCategory[i]; j++) {
            if (strcmp(library[i][j].title, temp) == 0) {
                cout << "Found" << endl;
                return &library[i][j];
            }
        }
    }
    return nullptr;
}

void updateCopies(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory) {
    Book* ptr = searchBook(library, numCategories, numBooksInCategory, freeIndexInCategory);
    if (ptr == nullptr) {
        cout << "Book not found" << endl;
    } else {
        cin >> ptr->numOfCopies;
    }
}

void printAllBooks(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < freeIndexInCategory[i]; j++) {
            cout << library[i][j].title << " " << library[i][j].author << " " << library[i][j].numOfCopies << endl;
        }
    }
}

void releaseMemory(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory) {
    for (int i = 0; i < numCategories; i++) {
        delete[] library[i];
    }
    delete[] library;
    delete[] numBooksInCategory;
    delete[] freeIndexInCategory;
    return;
}

int main() {
    int numCategories = 0;
    int* numBooksInCategory = nullptr;
    int* freeIndexInCategory = nullptr;

    Book** library = initializeLibrary(numCategories, numBooksInCategory, freeIndexInCategory);
    int choice = 0;
    while (choice != 5) {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Update Number of Copies\n";
        cout << "4. Print All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBook(library, numCategories, numBooksInCategory, freeIndexInCategory);
                break;
            case 2:
                searchBook(library, numCategories, numBooksInCategory, freeIndexInCategory);
                break;
            case 3:
                updateCopies(library, numCategories, numBooksInCategory, freeIndexInCategory);
                break;
            case 4:
                printAllBooks(library, numCategories, numBooksInCategory, freeIndexInCategory);
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    releaseMemory(library, numCategories, numBooksInCategory, freeIndexInCategory);
    return 0;
}
