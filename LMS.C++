#include <iostream>
#include <cstring>
#include <iomanip> 

using namespace std;

class Library
{
public:
    int id;
    char book_name[100];
    char author_name[100];
    char student_name[100];
    int price;
    int pages;
};

int main()
{
    Library lib[20];
    int input = 0;
    int count = 0;

    while (true)
    {
        cout << "\n================== Library Menu ==================\n";
        cout << "1. Add Book Details\n";
        cout << "2. Display All Books\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> input;
        cin.ignore(); 

        switch (input)
        {
        case 1:
        {
            char choice = 'y';
            while (choice == 'y' || choice == 'Y')
            {
                if (count >= 20)
                {
                    cout << "Library is full! Cannot add more books.\n";
                    break;
                }

                cout << "\nEnter details for book #" << (count + 1) << ":\n";
                cout << "Book ID: ";
                cin >> lib[count].id;
                cin.ignore();

                cout << "Book Name: ";
                cin.getline(lib[count].book_name, 100);

                cout << "Author Name: ";
                cin.getline(lib[count].author_name, 100);

                cout << "Student Name: ";
                cin.getline(lib[count].student_name, 100);

                cout << "Price: ";
                cin >> lib[count].price;

                cout << "Number of Pages: ";
                cin >> lib[count].pages;

                cin.ignore(); 
                count++;

                cout << "Add another book? (y/n): ";
                cin >> choice;
                cin.ignore(); 
            }
            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "No book records to display.\n";
            }
            else
            {
                cout << "\n================ Book Details ================\n";
                cout << left << setw(10) << "ID"
                     << setw(25) << "Book Name"
                     << setw(25) << "Author Name"
                     << setw(25) << "Student Name"
                     << setw(10) << "Price"
                     << setw(10) << "Pages" << endl;
        
                cout << "-------------------------------------------------------------------------------\n";
        
                for (int i = 0; i < count; i++)
                {
                    cout << left << setw(10) << lib[i].id
                         << setw(25) << lib[i].book_name
                         << setw(25) << lib[i].author_name
                         << setw(25) << lib[i].student_name
                         << setw(10) << lib[i].price
                         << setw(10) << lib[i].pages << endl;
                }
            }
            break;
        }

        case 3:
            cout << "Exiting the program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

