#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;
    bool isIssued;


    Book(string t, string a, string i) : title(t), author(a), isbn(i), isIssued(false) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn;
        if (isIssued) {
            cout << " [Issued]";
        } else {
            cout << " [Available]";
        }
        cout << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:

    void addBook(const string &title, const string &author, const string &isbn) {
        Book newBook(title, author, isbn);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }


    void removeBook(const string &isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->isbn == isbn) {
                books.erase(it);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }


    void editBook(const string &isbn) {
        for (auto &book : books) {
            if (book.isbn == isbn) {
                cout << "Editing book with ISBN: " << isbn << endl;
                cout << "Enter new title: ";
                getline(cin, book.title);
                cout << "Enter new author: ";
                getline(cin, book.author);
                cout << "Book details updated successfully!" << endl;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }


    void displayBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        for (const auto &book : books) {
            book.display();
        }
    }

    void issueBook(const string &isbn) {
        for (auto &book : books) {
            if (book.isbn == isbn) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully!" << endl;
                    return;
                } else {
                    cout << "The book is already issued!" << endl;
                    return;
                }
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }


    void returnBook(const string &isbn) {
        for (auto &book : books) {
            if (book.isbn == isbn) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully!" << endl;
                    return;
                } else {
                    cout << "The book was not issued!" << endl;
                    return;
                }
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }


    void searchBookByTitle(const string &title) const {
        bool found = false;
        for (const auto &book : books) {
            if (book.title == title) {
                book.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the title " << title << endl;
        }
    }
};


void adminMenu(Library &library) {
    int choice;
    string title, author, isbn;

    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Edit Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                getline(cin, isbn);
                library.addBook(title, author, isbn);
                break;
            case 2:
                cout << "Enter ISBN of the book to remove: ";
                getline(cin, isbn);
                library.removeBook(isbn);
                break;
            case 3:
                cout << "Enter ISBN of the book to edit: ";
                getline(cin, isbn);
                library.editBook(isbn);
                break;
            case 4:
                library.displayBooks();
                break;
            case 5:
                cout << "Exiting Admin Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void studentMenu(Library &library) {
    int choice;
    string isbn;

    do {
        cout << "\nStudent Menu:\n";
        cout << "1. Issue Book\n";
        cout << "2. Return Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter ISBN of the book to issue: ";
                getline(cin, isbn);
                library.issueBook(isbn);
                break;
            case 2:
                cout << "Enter ISBN of the book to return: ";
                getline(cin, isbn);
                library.returnBook(isbn);
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout << "Enter the title of the book to search: ";
                getline(cin, isbn);
                library.searchBookByTitle(isbn);
                break;
            case 5:
                cout << "Exiting Student Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    Library library;
    int roleChoice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Admin\n";
        cout << "2. Student\n";
        cout << "3. Exit\n";
        cout << "Enter your role choice: ";
        cin >> roleChoice;
        cin.ignore();

        switch (roleChoice) {
            case 1:
                adminMenu(library);
                break;
            case 2:
                studentMenu(library);
                break;
            case 3:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (roleChoice != 3);

    return 0;
}
