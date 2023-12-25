#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*20360859046-Mustafa Can Ersoy Veri yap�lar� vize �devi 22.11.2023*/

/* Burada ��renci bilgilerini i�eren d���m yap�s�n� olu�turdum*/
struct OgrenciNode {
    int ogrenciNo;
    char ad[50];
    char soyad[50];
    char bolum[50];
    int sinif;
    struct OgrenciNode* onceki;
    struct OgrenciNode* sonraki;
};

/* Burada ba�l� liste olu�turdum*/
struct BagliListe {
    struct OgrenciNode* bas;
    struct OgrenciNode* son;
};

/* Yeni bir ��renci d���m� olu�turma menusunu yapt�m */
struct OgrenciNode* nodeOlustur(int ogrenciNo, const char* ad, const char* soyad, const char* bolum, int sinif) {
    struct OgrenciNode* yeniDugum = (struct OgrenciNode*)malloc(sizeof(struct OgrenciNode));
    yeniDugum->ogrenciNo = ogrenciNo;
    strcpy(yeniDugum->ad, ad);
    strcpy(yeniDugum->soyad, soyad);
    strcpy(yeniDugum->bolum, bolum);
    yeniDugum->sinif = sinif;
    yeniDugum->onceki = NULL;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

/* Ba�l� liste yap�s�n� olu�turdum*/
void listeOlustur(struct BagliListe* liste) {
    liste->bas = NULL;
    liste->son = NULL;
    printf("Bagli liste olusturuldu.\n");
}

/* Ba�l� listenin yap�s�n� yok etme (bellekten silme) olu�turdum*/
void listeYokEt(struct BagliListe* liste) {
    while (liste->bas != NULL) {
        struct OgrenciNode* temp = liste->bas;
        liste->bas = liste->bas->sonraki;
        free(temp);
    }
    liste->son = NULL;
    printf("Bagli liste yok edildi\n");
}

/* Ba�l� listeye yeni bir d���m ekleme olu�turdum*/
void dugumEkle(struct BagliListe* liste, struct OgrenciNode* yeniDugum) {
    if (liste->bas == NULL) {
        liste->bas = yeniDugum;
        liste->son = yeniDugum;
    } else {
        yeniDugum->onceki = liste->son;
        liste->son->sonraki = yeniDugum;
        liste->son = yeniDugum;
    }
    printf("Ogrenci eklendi.\n");
}

/* ��renciyi listeden silme */
void dugumSil(struct BagliListe* liste, int ogrenciNo) {
    struct OgrenciNode* gecerli = liste->bas;
    while (gecerli != NULL) {
        if (gecerli->ogrenciNo == ogrenciNo) {
            if (gecerli->onceki != NULL) {
                gecerli->onceki->sonraki = gecerli->sonraki;
            } else {
                liste->bas = gecerli->sonraki;
            }
            if (gecerli->sonraki != NULL) {
                gecerli->sonraki->onceki = gecerli->onceki;
            } else {
                liste->son = gecerli->onceki;
            }
            free(gecerli);
            printf("Ogrenci silindi.\n");
            return;
        }
        gecerli = gecerli->sonraki;
    }
    printf("Ogrenci bulunamadi.\n");
}

/* ��renciyi listede arama*/
struct OgrenciNode* dugumAra(struct BagliListe* liste, int ogrenciNo) {
    struct OgrenciNode* gecerli = liste->bas;
    while (gecerli != NULL) {
        if (gecerli->ogrenciNo == ogrenciNo) {
            return gecerli;
        }
        gecerli = gecerli->sonraki;
    }
    return NULL;
}

/* ��rencileri ekrana yazd�rma */
void listeGoster(struct BagliListe* liste) {
    struct OgrenciNode* gecerli = liste->bas;
    printf("Ogrenci listesi\n");
    while (gecerli != NULL) {
        printf("Ogrenci No: %d\nAd: %s\nSoyad: %s\nBolum: %s\nSinif: %d\n",
               gecerli->ogrenciNo, gecerli->ad, gecerli->soyad, gecerli->bolum, gecerli->sinif);
        printf("--------------------\n");
        gecerli = gecerli->sonraki;
    }
}

int main() {
    struct BagliListe ogrenciListesi;
    listeOlustur(&ogrenciListesi);

    int secim;
    do {
        printf("\nMenu:\n");
        printf("1-Bagli liste olustur\n");
        printf("2-Bagli liste kaldir\n");
        printf("3-Ogrenci ekle\n");
        printf("4-Ogrenci sil\n");
        printf("5-Ogrenci ara\n");
        printf("6-Liste goster\n");
        printf("0-Cikis\n");
        printf("Secim yapiniz: ");
        scanf("%d", &secim);
/* Burada men�y� olu�turdum switch-case yap�s� kulland�m*/
        switch (secim) {
            case 1:
                listeOlustur(&ogrenciListesi);
                break;
            case 2:
                listeYokEt(&ogrenciListesi);
                break;
            case 3: {
                int ogrenciNo, sinif;
                char ad[50], soyad[50], bolum[50];
                printf("Ogrenci No: ");
                scanf("%d", &ogrenciNo);
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Bolum: ");
                scanf("%s", bolum);
                printf("Sinif: ");
                scanf("%d", &sinif);

                struct OgrenciNode* yeniDugum = nodeOlustur(ogrenciNo, ad, soyad, bolum, sinif);
                dugumEkle(&ogrenciListesi, yeniDugum);
                break;
            }
            case 4: {
                int ogrenciNo;
                printf("Silinecek ogrenci no");
                scanf("%d", &ogrenciNo);
                dugumSil(&ogrenciListesi, ogrenciNo);
                break;
            }
            case 5: {
                int ogrenciNo;
                printf("Aranacak ogrenci no");
                scanf("%d", &ogrenciNo);
                struct OgrenciNode* arananDugum = dugumAra(&ogrenciListesi, ogrenciNo);
                if (arananDugum != NULL) {
                    printf("��renci bulundu:\n");
                    printf("��renci No: %d\nAd: %s\nSoyad: %s\nB�l�m: %s\nS�n�f: %d\n",
                           arananDugum->ogrenciNo, arananDugum->ad, arananDugum->soyad, arananDugum->bolum, arananDugum->sinif);
                } else {
                    printf("Ogrenci Bulunamadi\n");
                }
                break;
            }
            case 6:
                listeGoster(&ogrenciListesi);
                break;
            case 0:
                printf("Programdan cikiliyor\n");
                break;
            default:
                printf("Gecersiz secim yaptiniz tekrar deneyiniz.\n");
                break;
        }

    } while (secim != 0);

    return 0;
}
