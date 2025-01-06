#include "datatypes.h"

//Tieu de he thong quan ly thu vien
void displaySystemName();
// Xoa man hinh terminal
void clearScreen();
//Menu chinh cua chuong trinh
void displayMenu();
//Tim kiem sach
void searchBook(const struct Book books[], int count);
//Tai thong tin sach tu file
void loadBooksFromFile(struct Book books[], int* count);
//Luu thong tin sach vao file
void saveBooksToFile(struct Book books[], int count);
//Hien thi danh sach sach
void displayBooks(struct Book books[], int count);
//Them sach moi
void addBook(struct Book books[], int* count);
//Sua sach
void editBook(struct Book books[], int count);
//Xoa sach
void deleteBook(struct Book books[], int* count);
//Sap xep sach
void arrangeBook(struct Book books[], int count);
//Tai file thong tin user
void readAccountFromFile(char* username, char* password);
//Ham dang nhap
int login(const char* storedUsername, const char* storedPassword);