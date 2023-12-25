#include <stdio.h>
#include <stdbool.h>
bool asalMi(int sayi, int bolen) {
    if (sayi < 2) {
        return false;
    }
    if (bolen == sayi) {
        return true;
    }
    if (sayi % bolen == 0) {
        return false;
    }
    return asalMi(sayi, bolen + 1);
}
int main() {
    int sayi;

    printf("Bir sayi girin: ");
    scanf("%d", &sayi);
    if (asalMi(sayi, 2)) {
        printf("%d asal sayidir.\n", sayi);
    } else {
        printf("%d asal sayi degildir.\n", sayi);
    }
    return 0;
}
