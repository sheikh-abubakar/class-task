#include<iostream>

using namespace std;

struct Book{
    char title[50];
    char author[50];
    int numOfCopies;
};
Book** initializeLibrary(int &numCategories, int* &numBooksinCategory, int*&freeIndexInCategory){
    cout<<"enter number of catogeries"; 
    cin>> numCategories;
    Book** library = new Book*[numCategories];
    numBooksinCatogery = new int[numCategories];

    freeIndexInCategory = new int[numCategories];

    for(int i =0; i< numCategories; i++){
        cout<<"enter num of books : "<<i+1;
        cin>>numBooksinCategory[i];
        library[i] = new Book[numBooksinCategory[i]];
        freeIndexInCategory[i] = 0;

    }
    return library;


}

void addBook(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory){
    cout<<"enter cotagery number to add";
    int cat_num;

    cin>>cat_num;
    if(freeIndexInCategory[cat_num-1] == numBooksInCategory){
        cout<<"limit is full";
        return;
    }
    cin>>library[cat_num-1][freeIndexInCategory[cat_num-1]].title;
    cin>>library[cat_num-1][freeIndexInCategory[cat_num-1]].author;
    cin>>library[cat_num-1][freeIndexInCategory[cat_num-1]].numOfCopies;
    freeIndexInCategory[cat_num-1]++;
}

Book* searchBook(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory){
    char temp[50];
    
    cin.getline(temp, 50);
    for(int i =0; i<numBooksInCategory; i++){
        for(int j =0; j< freeIndexInCategory[i];j++ ){
            if(strcmp(library[i][j].title,temp)==0){
                cout<<"'found";
                return &library[i][j];
            }
        }
    }
    return nullptr;
}

void updateCopies(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory){
   Book* ptr =  searchBook(library, numCategories, numBooksInCategory, freeIndexInCategory);
    if(ptr == nullptr)
    else{
   cin>> ptr -> numOfCopies;
   
    
 }
}

printAllBooks(library, numCategories, numBooksInCategory, int* freeIndexInCategory);

void releaseMemory(Book** library, int numCategories, int* numBooksInCategory, int* freeIndexInCategory)
int main(){

int numCategories = 0;
int* numBooksInCategory = nullptr; //dynamic array
int* freeIndexInCategory = nullptr; //dynamic array integer array

//To be used while adding a new book to the library

Book** library = initializeLibrary(numCategories, numBooksInCategory, freeIndexInCategory);
int choice;
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