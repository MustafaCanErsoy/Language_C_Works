#include <stdio.h>
void carpanlaraAyir(int sayi, int bolen) {
    if (sayi == 1) {
        return;
    }
    if (sayi % bolen == 0) {
        printf("%d ", bolen);
        carpanlaraAyir(sayi / bolen, bolen);
    } else {
        carpanlaraAyir(sayi, bolen + 1);
    }
}
int main() {
    int sayi;
    printf("Bir sayi girin: ");
    scanf("%d", &sayi);
    printf("%d sayisinin carpanlari: ", sayi);
    carpanlaraAyir(sayi, 2);
    return 0;
}
