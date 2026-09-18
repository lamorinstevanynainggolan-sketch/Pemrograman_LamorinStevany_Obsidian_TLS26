#include <iostream>
using namespace std;

int main() {
    char pesan[100];
    char hasil[100];

    cout << "Masukkan pesan: ";
    cin >> pesan;

    int i = 0;

    // Menentukan panjang pesan
    while (pesan[i] != '\0') {
        i++;
    }

    int panjang = i;

    // Huruf pertama tetap
    hasil[0] = pesan[0];

    // Proses huruf berikutnya
    for (i = 1; i < panjang; i++) {

        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

        // Jika melewati Z
        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        // Mengubah nilai kembali menjadi huruf
        hasil[i] = 'A' + nilaiBaru - 1;
    }

    // Menutup array hasil dengan '\0'
    hasil[panjang] = '\0';

    cout << "Pesan hasil sandi: " << hasil << endl;

    return 0;
}