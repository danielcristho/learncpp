#include <stdio.h>//tambahkan library
#include <stdlib.h>
 
int main(void)
{
    int a,b,hasil, menu;
    int x, y,z;//variabel untuk membuat fungsi ttg perpangkatan
    int total=1;//variabel untuk membuat fungsi ttg perpangkatan
    int opsilanjut;
    float c, d, hasilbagi; 
        do {

    //tampilan awal dari kalkulator
    printf("******************************************************\n"); 
    printf("Selamat datang di\n");
    printf("    Program Kalkulator by Daniel \n");
    printf("******************************************************\n");
    printf("\tSilahkan pilih operasi yang di inginkan : \n");

    //opsi melakukan operasi
    printf("\t1. Penjumlahan(+)\n");
    printf("\t2. Pengurangan(-)\n");
    printf("\t3. Perkalian(x)\n");
    printf("\t4. Pembagian(:)\n");
    printf("\t5. Modulus(sisa pembagian)\n");
    printf("\t6. Perpangkatan\n");
    printf("\t0. Keluar");


    printf("*****************************************************\n");
    printf("silahkan pilih menu(menggunakan angka(1,2,3,4,5,6)) : \n");
    scanf("%d",&menu);
    printf("*****************************************************\n");

    switch(menu) {
        case 1: // operasi penjumlahan
            printf("\n1.Penjumlahan : \n");
            printf("Masukan angka pertama :");
            scanf("%d", &a);
            printf("Masukan angka kedua :");
            scanf("%d", &b);
            hasil = a + b;   //membuat fungsi a+b
            printf("Hasil: \t%d\n", hasil);
            break;

        case 2: //operasi pengurangan
            printf("\n2.Pengurangan: \n");
            printf("Masukan angka pertama :");
            scanf("%d", &a);
            printf("Masukan angka kedua :");
            scanf("%d", &b);
            hasil = a - b;   //membuat fungsi a-b
            printf("Hasil: \t%d\n", hasil);
            break;

        case 3: //operasi pengurangan
            printf("\n3.Perkalian: \n");
            printf("Masukan angka pertama :");
            scanf("%d", &a);
            printf("Masukan angka kedua :");
            scanf("%d", &b);
            hasil = a * b;   //membuat fungsi a*b
            printf("Hasil: \t%d\n", hasil);
            break;

        case 4: //operasi pembagian
            printf("\n4.Pembagian: \n");
            printf("Masukan angka pertama :");
            scanf("%f", &c);
            printf("Masukan angka kedua :");
            scanf("%f", &d);
            hasilbagi = c / d;   //membuat fungsi c/d
            printf("Hasil: \t%.2f\n", hasilbagi);
            break;

        case 5: //operasi modulus(%)
            printf("\n5. Modulus: \n");
            printf("Masukan angka pertama :");
            scanf("%d", &a);
            printf("Masukan angka kedua :");
            scanf("%d", &b);
            hasil = a / b;   //membuat fungsi modulus(sisa pembagian)
            printf("Hasil: \t%d\n", hasil);
            break;

        case 6: //operasi perpangkatan
            printf("\n6. Perpangkatan: \n");
            printf("Masukan angka : ");
            scanf("%i", &x);
            printf("Masukan Pangkat : ");
            scanf("%i", &y);

            //membuat fungsi perulangan utk perpangkatan

            // 1. awalnya z = 0
            // 2. For statement akan memeriksa nilai z apakah kurang dari y
            // 3. Apabila TRUE maka jalankan kode dalam for block, yakni total=total * x
            for(z=1;z<=y;z++) { 
                total=total*x;
            }
            //hasil = a^b;   //membuat fungsi perpangkatan
            printf("Hasil: %d\n", total);
            return 0;
            break;
                      
        default: //else(jika tidak memilih opsi diatas)    
            printf("Angka yang diInputkan salah.");
    }    
            //break;

        printf("Apakah ingin melanjutkan lagi, ya(1) dan tidak (0)?\n");   
        scanf("%d",&opsilanjut);
    }   while (opsilanjut==1);
    return 0;
      
}    
