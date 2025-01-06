#include <stdio.h>
#include <string.h>
#include "functions.h"

//Tieu de he thong quan ly thu vien
void displaySystemName() {
	clearScreen();
	printf("***Library Management System Using C***\n");
}

// Xoa man hinh terminal
void clearScreen() {
	printf("\033[2J\033[H");
}

//Menu chinh cua chuong trinh
void displayMenu() {
	printf("\n          MENU:\n");
	printf("============================\n");
	printf("[1] Add a new book\n");
	printf("[2] Show all books\n");
	printf("[3] Search a book\n");
	printf("[4] Edit a book\n");
	printf("[5] Delete a book\n");
	printf("[6] Arrange a book\n");
	printf("[0] Exit the program\n");
	printf("============================\n");
	printf("Enter your choice: ");
}

//Tai thong tin sach tu file
void loadBooksFromFile(struct Book books[], int* count) {
	FILE* file = fopen("C:/Users/Lenovo/Desktop/project real/LMS/books.dat", "rb");
	if (file == NULL) {
		*count = 0;
		return;
	}

	fread(count, sizeof(int), 1, file);
	fread(books, sizeof(struct Book), *count, file);
	fclose(file);
}

//Luu thong tin sach vao file
void saveBooksToFile(struct Book books[], int count) {
	FILE* file = fopen("C:/Users/Lenovo/Desktop/project real/LMS/books.dat", "wb");
	if (file == NULL) {
		printf("Error: Could not save books to file.\n");
		return;
	}

	fwrite(&count, sizeof(int), 1, file);
	fwrite(books, sizeof(struct Book), count, file);
	fclose(file);
}

//Hien thi danh sach sach
void displayBooks(struct Book books[], int count) {
	clearScreen();
	printf("            ***All Books***\n");
	if (count == 0) {
		printf("\nNo books available in the library.\n");
		printf("\nPress [0] to return the main menu");
		printf("\nEnter your choice: ");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}
	printf("|=======|==================================================|=======================================|===================|\n");
	printf("| %-5s | %-48s | %-37s | %-17s |\n", "ID", "Title", "Author", "Price");
	printf("|=======|==================================================|=======================================|===================|\n");
	for (int i = 0; i < count; i++) {
		printf("| %-5d | %-48s | %-37s | %-17d |\n",
			books[i].id,
			books[i].title,
			books[i].author,
			books[i].price);
		printf("|-------|--------------------------------------------------|---------------------------------------|-------------------|\n");
	}
	printf("\nPress [0] to return the main menu\n");
	printf("Enter your choice: ");
	char choice;
	do {
		scanf_s(" %c", &choice);
		if (choice == '0') {
			clearScreen();
			break;
		}
	} while (1);
	return;
}

// Tim kiem sach
void searchBook(const struct Book books[], int count) {
	clearScreen();
	printf("            ***Search A Book***\n");

	if (count == 0) {
		printf("\nNo books available to search.\n");
		printf("\nPress [0] to return to the main menu...");
		printf("\nEnter your choice: ");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	char keyword[50];
	printf("Enter title or author to search: ");
	getchar();
	fgets(keyword, sizeof(keyword), stdin);
	keyword[strcspn(keyword, "\n")] = 0; // Loai bo ky tu xuong dong

	int found = 0;
	printf("\nSearch Results:\n");
	printf("|=======|==================================================|=======================================|===================|\n");
	printf("| %-5s | %-48s | %-37s | %-17s |\n", "ID", "Title", "Author", "Price");
	printf("|=======|==================================================|=======================================|===================|\n");

	for (int i = 0; i < count; i++) {
		if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
			printf("| %-5d | %-48s | %-37s | %-17d |\n",
				books[i].id,
				books[i].title,
				books[i].author,
				books[i].price);
			printf("|-------|--------------------------------------------------|---------------------------------------|-------------------|\n");
			found = 1;
		}
	}

	if (!found) {
		printf("\nNo matching books found for keyword: '%s'.\n", keyword);
	}
	printf("\nPress [0] to return the main menu\n");
	printf("Enter your choice: ");
	char choice;
	do {
		scanf_s(" %c", &choice);
		if (choice == '0') {
			clearScreen();
			break;
		}
	} while (choice != '0');

}

//Ham kiem tra trung title
int isDuplicateTitle(struct Book books[], int count, const char* newTitle) {
	for (int i = 0; i < count; i++) {
		if (strcmp(books[i].title, newTitle) == 0) {
			return 1; // Trung
		}
	}
	return 0; // Khong trung
}

//Them sach
void addBook(struct Book books[], int* count) {
	clearScreen();
	printf("            ***Add A New Book***\n");

	if (*count >= 100) {
		printf("Book list is full! Cannot add more books.\n");
		printf("\nPress [0] to return to the main menu...");
		printf("\nEnter your choice:");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	//Nhap ID
	int newId;
	while (1) {
		printf("Enter Book ID: ");
		scanf_s("%d", &newId);
		getchar(); // Loai bo ky tu con sot lai

		if (newId <= 0) {
			printf("Error: Book ID Invalid! Please enter a different ID.\n", newId);
			continue;
		}

		// Kiem tra ID trung lap
		int isDuplicate = 0;
		for (int i = 0; i < *count; i++) {
			if (books[i].id == newId) {
				isDuplicate = 1;
				break;
			}
		}

		if (isDuplicate) {
			printf("Error: Book ID %d already exists. Please enter a different ID.\n", newId);
		}
		else {
			break; // Neu ko trung.Thi tiep tuc chay
		}
	}

	// Gan ID 
	books[*count].id = newId;

	// Nhap Title
	while (1) {
		char title[100];
		printf("Enter Book Title: ");
		fgets(title, sizeof(title), stdin);
		title[strcspn(title, "\n")] = 0; // Loai bo ky tu xuong dong

		// Kiem tra do dai tieu de
		int titleLength = strlen(title);
		if (titleLength <= 0) {
			printf("Error: Title must be at least 1 characters long.\n");
			continue;
		}
		if (titleLength > 100) {
			printf("Error: Title must not exceed 100 characters.\n");
			continue;
		}

		// Kiem tra trung tieu de
		if (isDuplicateTitle(books, *count, title)) {
			printf("Error: Title already exists. Please enter a different title.\n");
		}
		else {
			//Gan tieu de
			strcpy_s(books[*count].title, sizeof(books[*count].title), title);
			break;
		}
	}

	// Nhap Author
	printf("Enter Author Name: ");
	fgets(books[*count].author, sizeof(books[*count].author), stdin);
	books[*count].author[strcspn(books[*count].author, "\n")] = 0; // Loai bo ky tu xuong dong

	// Nhap Price
	printf("Enter Price: ");
	scanf_s("%d", &books[*count].price);

	(*count)++; // Tang so luong sach
	printf("\nBook added successfully!\n");
	printf("\nPress [0] to return to the main menu...");
	printf("\nEnter your choice: ");
	char choice;
	do {
		scanf_s("%c", &choice);
		if (choice == '0') {
			clearScreen();
			break;
		}
	} while (1);
	return;
}

//Sua sach
void editBook(struct Book books[], int count) {
	clearScreen();
	printf("            ***Edit A book***\n");

	if (count == 0) {
		printf("\nNo books available to edit.\n");
		printf("\nPress [0] to return the main menu\n");
		printf("Enter your choice: ");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	int id;
	printf("Enter the ID of the book you want to edit: ");
	scanf_s("%d", &id);
	getchar(); // Loai bo ky tu newline con lai trong bo đem

	int existsId = 0; // Bien kiem tra ID ton tai
	for (int i = 0; i < count; i++) {
		if (books[i].id == id) {
			existsId = 1;

			// Hien thi thong tin hien tai
			printf("\nCurrent Information:\n");
			printf("ID: %d\n", books[i].id); // ID
			printf("Title: %s\n", books[i].title); // Tieu de
			printf("Author: %s\n", books[i].author); // Tac gia
			printf("Price: %d\n", books[i].price); // Gia 

			// Nhap thong tin moi
			// -- Tieu đe moi
			printf("\nEnter New Title: ");
			fgets(books[i].title, sizeof(books[i].title), stdin);
			books[i].title[strcspn(books[i].title, "\n")] = 0; // Loai bo ky tu newline con sot

			// -- Tac gia moi
			printf("\nEnter New Author: ");
			fgets(books[i].author, sizeof(books[i].author), stdin);
			books[i].author[strcspn(books[i].author, "\n")] = 0; // Loai bo ky tu newline

			// -- Gia moi
			printf("Enter New Price: ");
			scanf_s("%d", &books[i].price);
			getchar();  // Xoa ky tu newline con lai trong bo đem

			printf("\nBook information updated successfully!\n");
			printf("\nPress [0] to return the main menu\n");
			printf("Enter your choice: ");
			char choice;
			do {
				scanf_s("%c", &choice);
				if (choice == '0') {
					clearScreen();
					break;
				}
			} while (1);
			return;
		}
	}

	if (existsId == 0) {
		printf("\nBook with ID %d not found.\n", id);
	}

	printf("\nPress [0] to return the main menu\n");
	printf("Enter your choice: ");
	int choice;
	do {
		scanf_s("%d", &choice);
		if (choice == '0')
			clearScreen();
		break;
	} while (1);
	return;
}
//Xoa sach
void deleteBook(struct Book books[], int* count) {
	clearScreen();
	printf("            ***Delete a Book***\n");

	// Kiem tra neu khong có sach
	if (*count == 0) {
		printf("\nNo books available to delete.\n");
		printf("\nPress [0] to return to the main menu.\n");
		printf("Enter your choice: ");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	// Nhap ID sach can xoa
	int id;
	printf("\nEnter the ID of the book to delete: ");
	scanf_s("%d", &id);

	// Tim sach theo ID
	int index = -1;
	for (int i = 0; i < *count; i++) {
		if (books[i].id == id) {
			index = i;
			break;
		}
	}

	// Xu ly neu khong tim thay sach
	if (index == -1) {
		printf("\nBook with ID %d not found.\n", id);
		printf("\nPress [0] to return to the main menu.\n");
		printf("\nEnter your choice: ");
		char choice;
		do {
			scanf_s(" %c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	//Xac nhan xoa truoc khi thuc hien xoa
	char choiceConfirm;
	while (1) {
		//Xac nhan xoa truoc khi thuc hien xoa
		printf("\nAre you sure want to deleted this book? (Y/N): ");
		scanf_s(" %c", &choiceConfirm);
		if (choiceConfirm == 'Y' || choiceConfirm == 'y') {
			// Xoa sach: Di chuyen cac sach sau vi tri can xoa len truoc
			for (int i = index; i < *count - 1; i++) {
				books[i] = books[i + 1];
			}
			(*count)--; // Giam so luong sach
			printf("\nBook with ID %d deleted successfully!\n", id);
			break;
		}
		else if (choiceConfirm == 'N' || choiceConfirm == 'n') {
			break;
		}
		else {
			printf("\nChoice not define!\n");
		}
	}

	// Quay lai menu chinh
	printf("\nPress [0] to return to the main menu.\n");
	printf("Enter your choice: ");
	char choice;
	do {
		scanf_s("%c", &choice);
		if (choice == '0') {
			clearScreen();
			break;
		}
	} while (1);
	return;
}

// Ham so sanh tang dan theo gia
int compareByPriceAscending(const void* a, const void* b) {
	struct Book* bookA = (struct Book*)a;
	struct Book* bookB = (struct Book*)b;
	return bookA->price - bookB->price; // So sanh tang dan
}

// Ham so sanh giam dan theo gia
int compareByPriceDescending(const void* a, const void* b) {
	struct Book* bookA = (struct Book*)a;
	struct Book* bookB = (struct Book*)b;
	return bookB->price - bookA->price; // So sanh giam dan
}

// Ham sap xep sach theo gia tien
void arrangeBook(struct Book books[], int count) {
	clearScreen();
	printf("            ***Arrange Price By Books***\n");
	if (count == 0) {
		printf("\nNo price by books available to arrange.\n");
		printf("\nPress [0] to return to the main menu\n");
		printf("Enter your choice: ");
		char choice;
		do {
			scanf_s("%c", &choice);
			if (choice == '0') {
				clearScreen();
				break;
			}
		} while (1);
		return;
	}

	// Lua chon sap xep
	int choice;
	do {
		printf("\nChoose your choice:\n");
		printf("[1] Increase Price\n");
		printf("[2] Decrease Price\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		if (choice == 1 || choice == 2) {
			break; // Lua chon hop le
		}
		else {
			printf("\nError choice. Please try again.\n");
		}
	} while (1);

	// Sap xep dua theo lua chon
	if (choice == 1) {
		qsort(books, count, sizeof(struct Book), compareByPriceAscending); // Tang dan
		printf("\nBook increase successfully by price.\n");
	}
	else if (choice == 2) {
		qsort(books, count, sizeof(struct Book), compareByPriceDescending); // Giam dan
		printf("\nBooks dercease successfully by price.\n");
	}

	// Hien thi danh sach da sap xep
	displayBooks(books, count);
}

// Doc file chua thong tin tai khoan
void readAccountFromFile(char* username, char* password) {
	FILE* file = fopen("C:/Users/Lenovo/Desktop/project real/LMS/users.txt", "r");
	if (file == NULL) {
		printf("Error: Unable to open account file.\n");
		return 0;
	}

	// Doc thong tin tai khoan, mat khau
	fscanf_s(file, "%s %s", username, 20, password, 10);
	fclose(file);
}

// Ham xu ly ky tu cua password sang dau "*"
void getPassword(char* password, int maxLen) {
	int i = 0;
	char ch;

	while (1) {
		ch = getch();  // Doc ky tu ma nguoi dung nhap tu ban phim
		if (ch == 13) { // 13 la ky tu Enter (Neu nhan Enter)
			password[i] = '\0'; // Ket thuc chuoi
			break;
		}
		else if (ch == 8 && i > 0) { // 8 la ky tu Backspace (Neu nhan Backspace)
			i--;
			printf("\b \b");  // Xoa ky tu da nhap
		}
		else if (i < maxLen - 1) {
			password[i] = ch;
			i++;
			printf("*");  // Hien thi ky tu '*'
		}
	}
	printf("\n");
}

//Ham dang nhap
int login(const char* storedUsername, const char* storedPassword) {
	char username[20];
	char password[10];

	printf("\n          LOGIN:\n");
	printf("============================\n");
	// Nhap ten dang nhap
	printf("Enter Username: ");
	fgets(username, sizeof(username), stdin);
	username[strcspn(username, "\n")] = 0; // Loai bo ky tu xuong dong

	// Nhap mat khau
	printf("Enter Password: ");
	getPassword(password, 10);
	printf("============================\n");

	// Kiem tra thong tin dang nhap
	if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
		return 1; // Dang nhap thanh cong
	}
	else {
		clearScreen();
		return 0; // Dang nhap tat bai
	}
}