# STRUKTUR DATA DAN ALGORITMA

Informasi Mahasiswa
Nama    : Tasya Zahrani
NPM     : 2308107010006
Kelas   : D

Deskripsi Program
Program ini dibuat untuk menyelesaikan tugas mata kuliah Struktur Data dan Algoritma. Tujuan utama program ini adalah mengelompokkan kata-kata berdasarkan huruf awalnya dengan menggunakan kombinasi array dan linked list. Kata-kata diambil dari file dbterms.txt dan dimasukkan ke dalam struktur data yang sesuai.

Program ini menyediakan fitur untuk:
1. Menampilkan kata-kata berdasarkan huruf awal (maksimum 25 kata per tampilan).
2. Menghapus kata tertentu dari linked list.
3. Mengelola memori dengan baik untuk menghindari memory leak.

Struktur Data yang Digunakan
1. Array berukuran 26 untuk menyimpan linked list (masing-masing indeks mewakili huruf dari 'a' hingga 'z').
2. Setiap elemen array adalah pointer ke linked list yang menyimpan kata-kata dengan huruf awal yang sama.

Setiap Node dalam linked list memiliki:
- word  : Kata yang disimpan.
- next  : Pointer ke node berikutnya dalam list.

Cara Menggunakan Program
1. Kompilasi Program
   Gunakan perintah berikut untuk mengompilasi program dengan GCC: gcc Tugas01.c -o Tugas01

2. Jalankan Program
   ./Tugas01

3. Menu Utama
   Saat program dijalankan, pengguna dapat memilih opsi berikut:
   - 1 : Menampilkan kata-kata yang diawali huruf tertentu.
   - 2 : Menghapus kata tertentu dari linked list.
   - 3 : Keluar dari program.

Contoh Penggunaan
Menampilkan Kata Berdasarkan Huruf
Menu Pilihan:
1) Tampilkan kata-kata sesuai huruf pertama yang telah di input
2) Hapus kata tertentu dalam linked list
3) Selesai
Pilihan anda: 1
Masukkan huruf: d

Output:
dbd
demam
dara
dongeng
dapat

Menghapus Kata dari Linked List
Pilihan anda: 2
Masukkan kata yang ingin dihapus: fakta
Output:
Kata 'fakta' dihapus.

Pengelolaan Memori
Setiap memori yang dialokasikan dalam linked list akan dibebaskan sebelum program selesai, untuk mencegah memory leak.

Kesimpulan
Program ini berhasil mengimplementasikan array of linked list untuk pengelompokan kata secara efisien. Semua operasi seperti penambahan, pencarian, dan penghapusan kata telah diuji dan bekerja dengan baik.

Semoga program ini sesuai dengan ketentuan tugas dan mendapatkan nilai maksimal! 🚀
 
(c) 2025 - tasyazahrani

