#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Book {
public:
    string title;
    string author;
    string publication;
    string issuedTo;
    bool available;

    Book(string t, string a, string p) : title(t), author(a), publication(p), issuedTo(""), available(true) {}
};

struct IssuedBook {
    Book* book;
    string user;

    IssuedBook(Book* b, const string& u) : book(b), user(u) {}
};

class LMS {
private:
    vector<Book> books;
    queue<IssuedBook> issuedBooksQueue;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added: " << book.title << " by " << book.author << endl;
    }

    void listBooks() {
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Publication: " << book.publication;
            if (!book.available) {
                cout << " (Issued to: " << book.issuedTo << ")";
            }
            cout << endl;
        }
    }

    void searchBooks(const string& title) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(title) != string::npos) {
                cout << "Found - Title: " << book.title << ", Author: " << book.author << ", Publication: " << book.publication;
                if (!book.available) {
                    cout << " (Issued to: " << book.issuedTo << ")";
                }
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the title containing: " << title << endl;
        }
    }

    void issueBook(const string& title, const string& user) {
        for (auto& book : books) {
            if (book.title == title && book.available) {
                book.available = false;
                book.issuedTo = user;
                issuedBooksQueue.push(IssuedBook(&book, user));
                cout << "Book issued: " << book.title << " to " << user << endl;
                return;
            }
        }
        cout << "Book not available for issue: " << title << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title && !book.available) {
                cout << "Book returned: " << book.title << " from " << book.issuedTo << endl;
                book.available = true;
                book.issuedTo.clear();
                // Remove the returned book from the issuedBooksQueue
                queue<IssuedBook> tempQueue;
                while (!issuedBooksQueue.empty()) {
                    IssuedBook issuedBook = issuedBooksQueue.front();
                    issuedBooksQueue.pop();
                    if (issuedBook.book->title != title) {
                        tempQueue.push(issuedBook);
                    }
                }
                issuedBooksQueue = tempQueue;
                return;
            }
        }
        cout << "Book not found or not issued: " << title << endl;
    }

    void listIssuedBooks() {
        queue<IssuedBook> tempQueue = issuedBooksQueue;
        while (!tempQueue.empty()) {
            IssuedBook issuedBook = tempQueue.front();
            tempQueue.pop();
            cout << "Title: " << issuedBook.book->title << ", Issued to: " << issuedBook.user << endl;
        }
    }

    void deleteBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                if (!it->available) {
                    cout << "Cannot delete book that is currently issued: " << title << endl;
                    return;
                }
                books.erase(it);
                cout << "Book deleted: " << title << endl;
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }
};

int main() {
    bool restart = false;
    do {
        LMS lms;
        string title, author, publication, searchTitle, user;
        char choice;

        do {
            cout << "\n1. Add Book\n2. List Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. List Issued Books\n7. Delete Book\n8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case '1':
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book publication: ";
                getline(cin, publication);
                lms.addBook(Book(title, author, publication));
                break;
            case '2':
                cout << "\nBooks in the library:\n";
                lms.listBooks();
                break;
            case '3':
                cout << "Enter title to search: ";
                getline(cin, searchTitle);
                lms.searchBooks(searchTitle);
                break;
            case '4':
                cout << "Enter book title to issue: ";
                getline(cin, title);
                cout << "Enter user name: ";
                getline(cin, user);
                lms.issueBook(title, user);
                break;
            case '5':
                cout << "Enter book title to return: ";
                getline(cin, title);
                lms.returnBook(title);
                break;
            case '6':
                cout << "\nIssued books:\n";
                lms.listIssuedBooks();
                break;
            case '7':
                cout << "Enter book title to delete: ";
                getline(cin, title);
                lms.deleteBook(title);
                break;
            case '8':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != '8');

        char restartChoice;
        cout << "Do you want to restart the program? (y/n): ";
        cin >> restartChoice;
        restart = (restartChoice == 'y' || restartChoice == 'Y');

    } while (restart);

    return 0;
}
