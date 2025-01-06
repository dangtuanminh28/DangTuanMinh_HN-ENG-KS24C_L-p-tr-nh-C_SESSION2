#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    struct Book books[100];
    int count = 0;
    char storedUsername[20];
    char storedPassword[10];
    
    readAccountFromFile(storedUsername, storedPassword);

    // Nguoi dung dang nhap
    while (1) {
        //kiem tra ket qua dang nhap
        if (login(storedUsername, storedPassword)) {
            printf("Login successful!\n");
            break;  // Dang nhap thanh cong thoat vong lap
        }
        else {
            printf("Invalid username or password! Please try again.\n");
        }
    }
    
    loadBooksFromFile(books, &count);

    int choice;
    do {
        displaySystemName();
        displayMenu();
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            addBook(books, &count);
            saveBooksToFile(books, count);
            break;
        case 2:
            displayBooks(books, count);
            break;
        case 3:
            searchBook(books, count);
            break;
        case 4:
            editBook(books, count);
            saveBooksToFile(books, count);
            break;
        case 5:
            deleteBook(books, &count);
            saveBooksToFile(books, count);
            break;
        case 6:
            arrangeBook(books, count);
            break;
        case 0:
            printf("========= Thank You =========\n");
            printf("========= See You Soon ======\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}