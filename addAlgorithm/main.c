#include <stdio.h>
#include <stdlib.h>
float ekleN(float sayi){
    if(sayi==1){
        return 1;
    }
    else{
            /*if(sayi<=0){
                printf("sayi 1 veya daha büyük olmalidir");
            }*/
        return (1/sayi+ekleN(sayi-1));

    }

}
int main()
{
    float a = ekleN(11);
    printf("%f cevaptir",a);
}
