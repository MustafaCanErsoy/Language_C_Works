#include <stdio.h>
#include <stdlib.h>
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};
struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}
int bagliListeUzunlugu(struct Dugum* dugum) {
    if (dugum == NULL) {
        return 0;
    } else {
        return 1 + bagliListeUzunlugu(dugum->sonraki);
    }
}
int main() {
    struct Dugum* bas = dugumOlustur(1);
    bas->sonraki = dugumOlustur(2);
    bas->sonraki->sonraki = dugumOlustur(3);
    bas->sonraki->sonraki->sonraki = dugumOlustur(4);
    bas->sonraki->sonraki->sonraki->sonraki = dugumOlustur(5);
    bas->sonraki->sonraki->sonraki->sonraki->sonraki = dugumOlustur(6);
    int uzunluk = bagliListeUzunlugu(bas);
    printf("Bagli Listenin Uzunlugu: %d\n", uzunluk);
    struct Dugum* simdiki = bas;
    struct Dugum* sonraki;
    while (simdiki != NULL) {
        sonraki = simdiki->sonraki;
        free(simdiki);
        simdiki = sonraki;
    }

    return 0;
}
