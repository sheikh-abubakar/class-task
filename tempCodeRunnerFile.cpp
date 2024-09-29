#include <iostream>
#include <cstring> // Include this for strlen
using namespace std;

int main() {
    const int SIZE = 10;           // Maximum number of tasks
    char buffer[100];              // Temporary buffer for input
    int read_item = 0;             // Index to read the next item from the list
    int add_item = 0;              // Index to add the next item to the list
    char* todolist[SIZE];          // Circular array to store tasks
    int n;                         // User's menu option
    int count = 0;                 // Number of items in the list

    do {
        // Display menu options
        cout << "\nPress 0: Exit\n";
        cout << "Press 1: Add new item\n";
        cout << "Press 2: Read and remove next item on the list\n";
        cout << "Press 3: Show all items on the list\n";
        cout << "Enter an option: ";
        cin >> n;
        cin.ignore();  // Clear input buffer

        switch (n) {
            case 0:
                cout << "Exiting...\n";
                break;

            case 1: {
                if (count == SIZE) {
                    cout << "List is full, overwriting the oldest task...\n";
                }

                cout << "Enter a todo list item: ";
                cin.getline(buffer, sizeof(buffer));  // Read the task from the user

                // Allocate memory for the new task
                todolist[add_item] = new char[strlen(buffer) + 1];  // Allocate enough memory

                // Copy the input into the todo list (manual string copy)
                int i = 0;  // Reset index for copying
                while (buffer[i] != '\0') {
                    todolist[add_item][i] = buffer[i];
                    i++;
                }
                todolist[add_item][i] = '\0';  // Null-terminate the string

                // Manage circular array indexing
                add_item = (add_item + 1) % SIZE;
                if (count < SIZE) {
                    count++;
                } else {
                    // If the list is full, move the read pointer forward
                    read_item = (read_item + 1) % SIZE;
                }
                break;
            }

            case 2:
                if (count == 0) {
                    cout << "List is empty.\n";
                } else {
                    cout << "Removed item: " << todolist[read_item] << endl;
                    delete[] todolist[read_item];  // Free the memory for the removed task
                    read_item = (read_item + 1) % SIZE;  // Circular indexing
                    count--;
                }
                break;

            case 3:
                if (count == 0) {
                    cout << "Todo list is empty.\n";
                } else {
                    cout << "All tasks in the todo list:\n";
                    for (int i = 0; i < count; i++) {
                        int index = (read_item + i) % SIZE;  // Circular indexing for display
                        cout << i + 1 << ". " << todolist[index] << endl; 
                    }
                }
                break;

            default:
                cout << "Invalid option, please try again.\n";
        }

    } while (n != 0);  // Continue until the user chooses to exit

    // Free any remaining allocated memory before exiting
    for (int i = 0; i < count; i++) {
        delete[] todolist[(read_item + i) % SIZE];
    }

    return 0;
}
