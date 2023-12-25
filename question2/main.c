#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool palindromMu(char* kelime, int baslangic, int bitis) {
    if (baslangic >= bitis) {
        return true;
    }

    if (kelime[baslangic] != kelime[bitis]) {
        return false;
    }
    return palindromMu(kelime, baslangic + 1, bitis - 1);
}
int main() {
    char kelime[100];
    printf("Bir kelime girin: ");
    scanf("%s", kelime);
    if (palindromMu(kelime, 0, strlen(kelime) - 1)) {
        printf("%s palindromdur.\n", kelime);
    } else {
        printf("%s palindrom degildir.\n", kelime);
    }
    return 0;
}
