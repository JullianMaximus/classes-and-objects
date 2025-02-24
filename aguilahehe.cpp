#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    string getTitle() { return title; }

    void display() {
        cout << left << title;
        cout << string(25 - title.length(), ' ');
        cout << author;
        cout << string(20 - author.length(), ' ');
        cout << year << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int year) {
        books.push_back(Book(title, author, year));
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        cout << "Book List:\n";
        cout << "------------------------------------------------\n";
        cout << "Title                    Author              Year\n";
        cout << "------------------------------------------------\n";
        for (Book &book : books) {
            book.display();
        }
    }

    void searchBook(string searchTitle) {
        for (Book &book : books) {
            if (book.getTitle() == searchTitle) {
                cout << "Book found!" << endl;
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getTitle() << endl;
                cout << "Year: " << book.getTitle() << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    while (true) {
        cout << "\nMenu\n1 - Add Book\n2 - Display Books\n3 - Search Book\n4 - Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                cin.ignore();
                library.addBook(title, author, year);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter a book to search: ";
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}