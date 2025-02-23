#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DISPLAY 25

// Struktur node untuk linked list
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

// Array dari linked list
Node* dictionary[26] = { NULL };

// Fungsi untuk menambahkan kata ke dalam file dbterms.txt
void addWord(const char* word) {
    char firstLetter = tolower(word[0]);
    if (firstLetter >= 'a' && firstLetter <= 'z') {
        int index = firstLetter - 'a';
        Node* newNode = createNode(word);
        newNode->next = dictionary[index];
        dictionary[index] = newNode;
    }
}

// Fungsi untuk menampilkan kata berdasarkan huruf pertama
void displayWords(char letter) {
    letter = tolower(letter);
    if (letter >= 'a' && letter <= 'z') {
        int index = letter - 'a';
        Node* current = dictionary[index];
        int count = 0;
        if (!current) {
            printf("Tidak ada kata yang ditemukan dengan huruf awal %c.\n", letter);
        } else {
            while (current && count < MAX_DISPLAY) {
                printf("%s\n", current->word);
                current = current->next;
                count++;
            }
        }
    }
}

// Fungsi untuk menghapus kata dari dbterms.txt
void deleteWord(const char* word) {
    char firstLetter = tolower(word[0]);
    if (firstLetter >= 'a' && firstLetter <= 'z') {
        int index = firstLetter - 'a';
        Node* current = dictionary[index];
        Node* previous = NULL;

        while (current && strcmp(current->word, word) != 0) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            printf("Kata '%s' tidak ditemukan.\n", word);
        } else {
            if (previous) {
                previous->next = current->next;
            } else {
                dictionary[index] = current->next;
            }
            free(current);
            printf("Kata '%s' dihapus.\n", word);
        }
    }
}

int main() {
    FILE* file = fopen("dbterms.txt", "r");
    if (!file) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        addWord(word);
    }
    fclose(file);

    int choice;
    char letter;
    char wordToDelete[MAX_WORD_LENGTH];

    while (1) {
        printf("\nMenu Pilihan:\n");
        printf("1) Tampilkan kata-kata sesuai huruf pertama yang telah di input\n");
        printf("2) Hapus kata tertentu dalam linked list\n");
        printf("3) Selesai\n");
        printf("Pilihan anda: ");
        if (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka antara 1-3.\n");
            while (getchar() != '\n'); // Bersihkan buffer
            continue;
        }

        if (choice == 1) {
            printf("Masukkan huruf: ");
            while (getchar() != '\n'); // Bersihkan buffer sebelum membaca karakter
            scanf("%c", &letter);
            displayWords(letter);
        } else if (choice == 2) {
            printf("Masukkan kata yang ingin dihapus: ");
            scanf("%s", wordToDelete);
            deleteWord(wordToDelete);
        } else if (choice == 3) {
            break;
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori
    for (int i = 0; i < 26; ++i) {
        Node* current = dictionary[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    printf("Program selesai.\n");
    return 0;
}
