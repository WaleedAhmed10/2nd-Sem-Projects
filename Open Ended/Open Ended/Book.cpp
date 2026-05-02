#include <iostream>
#include <string>
using namespace std;

class book
{
private:
    string title, author, publisher;
    int pubYear, numPages, price;
    static int numPub;

public:
    book(string t, string auth, string pub, int pY, int pg, int p)
    {
        title = t;
        author = auth;
        publisher = pub;
        pubYear = pY;
        numPages = pg;
        price = p;
        numPub++;
    }

    int calcPrice() const
    {
        if (numPages > 0)
            return price / numPages;
        else
            return 0;
    }

    void displayBookDetails() const
    {
        cout << "Book Details: " << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Published Year: " << pubYear << endl;
        cout << "Price: " << price << endl;
        cout << "Number of Pages: " << numPages << endl;
        cout << "Number of Publications: " << numPub << endl;
    }

    static int getNumOfPublications()
    {
        return numPub;
    }

    ~book()
    {
        cout << "Deleting the book: " << title << endl;
    }
};

int book::numPub = 0;

int main()
{
    string title, author, publisher;
    int pubYear, numPages, price;

    cout << "Enter Title of book: ";
    getline(cin, title);
    cout << "Enter Name of author: ";
    getline(cin, author);
    cout << "Enter Book's publisher: ";
    getline(cin, publisher);
    cout << "Enter Published year: ";
    cin >> pubYear;
    cout << "Enter Price of the Book: ";
    cin >> price;
    cout << "Enter Number of Pages: ";
    cin >> numPages;

    book myBook(title, author, publisher, pubYear, numPages, price);
    myBook.displayBookDetails();
    cout << "Price per page: " << myBook.calcPrice() << endl;

    return 0;
}