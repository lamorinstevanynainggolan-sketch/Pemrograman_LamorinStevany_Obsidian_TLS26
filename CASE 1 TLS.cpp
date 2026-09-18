#include <iostream>
using namespace std;

int main() {
    long long N, K;

    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;

    cout << "Masukkan nilai K: ";
    cin >> K;

    if (N <= 0 || K < 1) {
        cout << "Input tidak valid." << endl;
        return 0;
    }

    // Membuat circular linked list secara manual
    // next[i] menyimpan nomor astronaut setelah astronaut i
    long long* next = new long long[N + 1];

    for (long long i = 1; i < N; i++) {
        next[i] = i + 1;
    }

    next[N] = 1;

    long long current = 1;
    long long previous = N;
    long long remaining = N;

    cout << "\nUrutan eliminasi: ";

    while (remaining > 1) {

        // Karena berbentuk lingkaran,
        // langkah dapat diperkecil dengan modulo
        long long steps = (K - 1) % remaining;

        // Bergerak sampai astronaut ke-K
        for (long long i = 0; i < steps; i++) {
            previous = current;
            current = next[current];
        }

        long long eliminated = current;

        cout << eliminated << " ";

        // Menghapus astronaut dari lingkaran
        next[previous] = next[current];

        // Perhitungan berikutnya dimulai
        // dari astronaut setelah yang dieliminasi
        current = next[current];

        remaining--;

        // Mengubah nilai K
        if (eliminated % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;

            if (K < 2) {
                K = 2;
            }
        }
    }

    cout << "\nAstronaut terakhir: " << current << endl;

    delete[] next;

    return 0;
}