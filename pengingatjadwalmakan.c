#include <stdio.h>
#include <unistd.h> //untuk sleep

int main() {
    char input[6]; //untuk menyimpan input user dalam bentuk string seperti format 07:00
    int jam, menit; // untuk menyimpan nilai  jam dan menit hasil parsing dari input
    char pilihan; //untuk menyimpan pilihan user apakah akan menampilkan pengingat ulang atau tidak

    //loop sampai input waktu valid
    while (1) {
        printf("Masukkan jam sekarang (hh:mm): ");
        scanf("%5s", input); // Membaca string waktu maksimal 5 karakter seperti 07:00

        // Parsing dengan sscanf
        if (sscanf(input, "%d:%d", &jam, &menit) == 2 && jam >= 0 && jam <= 23 && menit >= 0 && menit <= 59) {
            break; // keluar dari loop jika format valid dan jam/menit berada dalam rentang yang benar
        } else {
            printf("\nInput waktu tidak valid. Silahkan masukan ulang.\n");
        }

        // Membersihkan buffer agar tidak terjadi masalah input berikutnya
        while (getchar() != '\n');
    }

    //mengecek waktu makan yang sudah ditentukan
    if (jam == 7 & menit ==0) {
        printf("\nHai selamat pagi, waktunya sarapan\n");
    } else if (jam == 12 & menit ==0) {
        printf("\nSekarang sudah pukul 12:00, jangan lupa makan siang ya\n");
    } else if (jam ==18 & menit == 0) {
        printf("\nGimana aktivitas kamu? jangan lupa makan malam ya\n");
    } else {
        printf("\nIni bukan waktu makan kamu yaa\n"); //jika bukan jam makan, program selesai
        return 0;
    }

    // Memberi tahu user bahwa akan ada pengingat ulang
    printf("Pengingat ulang akan muncul dalam 2 menit lagi.\n");
    printf("Jika ingin membatalkan pengingat ulang, tekan 's'\n");
    printf("Jika tidak ingin membatalkan, tekan huruf selain 's' lalu enter\n");

    getchar(); // Buang newline sisa input sebelumnya
    pilihan = getchar(); // Ambil input karakter dari user

    if (pilihan == 's' || pilihan == 'S') {
        printf("Pengingat ulang dibatalkan.\n");
    } else {
        printf("Tunggu 2 menit lagi\n");
        sleep(120); // Tunggu 2 menit (120 detik)
        printf("Pengingat ulang: Jangan lupa makan ya, kalo nggak nanti kamu sakit lohh!\n");
    }

    return 0;
}
