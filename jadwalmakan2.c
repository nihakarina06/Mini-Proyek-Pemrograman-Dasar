#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // untuk sleep()

int main() {
    char input[6];
    int jam, menit;
    char pilihan;

    //looping sampai input yang user masukan benar
    while (1) { 
    printf("Masukkan jam sekarang (hh:mm): ");
    scanf("%5s", input);

    // Parsing dengan sscanf
    if (sscanf(input, "%d:%d", &jam, &menit) != 2) {
        printf("Format waktu tidak valid.\n");
        return 1;
    }

    // Mengecek waktu makan
    if (jam == 7 && menit == 0) {
        printf("Hai selamat pagi, waktunya sarapan!\n");
    } else if (jam == 12 && menit == 0) {
        printf("Gimana aktivitas kamu? jangan lupa makan siang ya!\n");
    } else if (jam == 18 && menit == 0) {
        printf("Waktunya makan malam!\n");
    } else {
        printf(" Ini bukan waktu makan kamu.\n");
        return 0;
    }

    printf("Pengingat ulang akan muncul dalam 2 menit lagi.\n");
    printf("Jika ingin membatalkan pengingat ulang, tekan 's', jika tidak tekan huruf selain 's' lalu enter sekarang.\n");

    getchar(); // buang newline
    pilihan = getchar();

    if (pilihan == 's' || pilihan == 'S') {
        printf("Pengingat dibatalkan.\n");
    } else {
        printf("Tunggu 2 menit lagi\n");
        sleep(120);
        printf("Pengingat ulang: Jangan lupa makan ya, kalo nggak nanti kamu sakit!\n");
    }

    return 0;
}
}