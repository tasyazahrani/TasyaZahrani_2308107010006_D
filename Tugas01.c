#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PANJANG_KATA_MAKS 100
#define MAKS_TAMPILAN 25

// Struktur node untuk linked list
typedef struct Simpul {
    char kata[PANJANG_KATA_MAKS];
    struct Simpul* berikutnya;
} Simpul;

// Fungsi untuk membuat node baru
Simpul* buatSimpul(const char* kata) {
    Simpul* simpulBaru = (Simpul*)malloc(sizeof(Simpul));
    if (!simpulBaru) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    strcpy(simpulBaru->kata, kata);
    simpulBaru->berikutnya = NULL;
    return simpulBaru;
}

// Array dari linked list
Simpul* kamus[26] = { NULL };

// Fungsi untuk menambahkan kata ke dalam kamus
void tambahKata(const char* kata) {
    char hurufPertama = tolower(kata[0]);
    if (hurufPertama >= 'a' && hurufPertama <= 'z') {
        int indeks = hurufPertama - 'a';
        Simpul* simpulBaru = buatSimpul(kata);
        simpulBaru->berikutnya = kamus[indeks];
        kamus[indeks] = simpulBaru;
    }
}

// Fungsi untuk menampilkan kata berdasarkan huruf pertama
void tampilkanKata(char huruf) {
    huruf = tolower(huruf);
    if (huruf >= 'a' && huruf <= 'z') {
        int indeks = huruf - 'a';
        Simpul* sekarang = kamus[indeks];
        int jumlah = 0;
        if (!sekarang) {
            printf("Kata dengan huruf awal %c tidak ditemukan.\n", huruf);
        } else {
            while (sekarang && jumlah < MAKS_TAMPILAN) {
                printf("%s\n", sekarang->kata);
                sekarang = sekarang->berikutnya;
                jumlah++;
            }
        }
    }
}

// Fungsi untuk menghapus kata dari kamus
void hapusKata(const char* kata) {
    char hurufPertama = tolower(kata[0]);
    if (hurufPertama >= 'a' && hurufPertama <= 'z') {
        int indeks = hurufPertama - 'a';
        Simpul* sekarang = kamus[indeks];
        Simpul* sebelumnya = NULL;

        while (sekarang && strcmp(sekarang->kata, kata) != 0) {
            sebelumnya = sekarang;
            sekarang = sekarang->berikutnya;
        }

        if (!sekarang) {
            printf("Kata '%s' tidak ditemukan.\n", kata);
        } else {
            if (sebelumnya) {
                sebelumnya->berikutnya = sekarang->berikutnya;
            } else {
                kamus[indeks] = sekarang->berikutnya;
            }
            free(sekarang);
            printf("Kata '%s' dihapus.\n", kata);
        }
    }
}

int main() {
    FILE* file = fopen("dbterms.txt", "r");
    if (!file) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    char kata[PANJANG_KATA_MAKS];
    while (fscanf(file, "%s", kata) != EOF) {
        tambahKata(kata);
    }
    fclose(file);

    int pilihan;
    char huruf;
    char kataHapus[PANJANG_KATA_MAKS];

    while (1) {
        printf("\nMenu Pilihan:\n");
        printf("1) Menampilkan kata-kata sesuai huruf pertama yang ditentukan\n");
        printf("2) Menghapus kata tertentu dalam linked list\n");
        printf("3) Selesai\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Masukkan huruf: ");
            scanf(" %c", &huruf);
            tampilkanKata(huruf);
        } else if (pilihan == 2) {
            printf("Masukkan kata yang ingin dihapus: ");
            scanf("%s", kataHapus);
            hapusKata(kataHapus);
        } else if (pilihan == 3) {
            break;
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori
    for (int i = 0; i < 26; ++i) {
        Simpul* sekarang = kamus[i];
        while (sekarang) {
            Simpul* temp = sekarang;
            sekarang = sekarang->berikutnya;
            free(temp);
        }
    }

    printf("Program selesai.\n");
    return 0;
}
