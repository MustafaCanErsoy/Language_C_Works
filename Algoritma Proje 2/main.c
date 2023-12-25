#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//Taslakda verilen bigram ve trigram değerleri
const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};
const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};
const char languages[2][8]={"english", "german"};



//İngilizce dilinin frekans değerleri
const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
//Almanca dilinin frekans değerleri
const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };

//

float calculated_frequencies[20];
float distances [2]={0,0};

//Filtreleme işlemini gerçekleştiren fonksiyon

void filter_str(char str[]);

//Frekans matrisleri arasındaki uzaklığın hesaplanması

void calculate_distances();

//Bigram ve trigramların frekans değerlerini hesaplanması ve yazdırılması

void calculate_frequencies_bi(char str[]);
void calculate_frequencies_tri(char str[]);

//Metnin yazıldığı dilin tahmin edilmesi

void detect_lang();

//Burada metnin filtrelenmesini sağladık

void filter_str(char str[]){
    char ascii_denetim[61];
    int k = 0;
    for(char m = 'a'; m <= 'z';m++){
        ascii_denetim[k] = m;k++;
    }
    for(char h = 'A'; h <= 'Z';h++){
        ascii_denetim[k] = h;k++;
    }

    ascii_denetim[k] = ' ';
    for(int l = 0,j;l < strlen(str);l++){
        for(j = 0;j < k + 1;j++){
            if(str[l] == ascii_denetim[j]){break;
    }
        }
        if(j == (k + 1)) ; {  str[l] = ' ';}
    }
    printf("\n Bu metnin filtrelenmis versiyonudur:\n\n\t") ; puts(str) ;

}

//Kullanıcıdan metnin alınması ve alınan metnin frekans değerlerinin hesaplanması

int main(void)
{
    char girdi[999];
    printf("Lutfen Metni Giriniz:\t\n\n\t");
    gets(girdi);
    filter_str(girdi);
    calculate_frequencies_bi(girdi);
    calculate_frequencies_tri(girdi);
    calculate_distances();
    detect_lang();
    return 0;
}



//Bigramın hesaplanması
void calculate_frequencies_bi(char str[]){
char denetim[3], girdiX[3];
float hesap = 0.0;
for(int i = 0,c = 0;i < 10;i++){
    for(int j = 0;j < 2;j++){
        denetim[j] = matrix_bigram_strings[i][j];
    }
    denetim[2] = '\0';
    hesap = 0.0;
    c = 0;
    while(c != strlen(str)-1){
        for(int m = 0;m < 2;m++){
            girdiX[m] = str[c];
            c++;
        }
        girdiX[2] = '\0';
        c -= 1;
        if(strcmp(girdiX,denetim) == 0){
            hesap++;
        }
    }
    calculated_frequencies[i] = hesap;
}

printf("\nAsagidakiler bigram'in frekanslaridir :\n\t\n");

for(int i = 0;i < 10;i++){
   printf(" %.2f, ",calculated_frequencies[i]);
}


}

//Trigramin Hesaplanması

void calculate_frequencies_tri(char str[]){
printf("\n");
char denetim[4], girdiX[4];
float hesap = 0.0;
for(int i = 0,c = 0;i < 10;i++){
    for(int j = 0;j < 3;j++){
        denetim[j] = matrix_trigram_strings[i][j];
    }
    denetim[3] = '\0';
    hesap = 0.0;
    c = 0;
    while(c != strlen(str)-2){
        for(int m = 0;m < 3;m++){
            girdiX[m] = str[c];
            c++;
        }
        girdiX[3] = '\0' ;
        c -= 2 ;
        if(strcmp(girdiX,denetim) == 0){
            hesap++;
        }
    }
    calculated_frequencies[i + 10] = hesap;
}
printf("\n Asagidakiler trigramin frekanslaridir :\n\t\n");
for(int i = 10;i < 20;i++){
   printf(" %.2f, ",calculated_frequencies[i]);
}
}
void calculate_distances()

// Metnin Almanca ve İngilizce için değerler arası uzaklıkları

{
    float toplam = 0.0;
    for(int i = 0;i < 20;i++){
        toplam += pow((calculated_frequencies[i] - frequency_eng[i]),2);
    }
    distances[0] = sqrt(toplam);
    printf("\n \n Metnin ingilizce ile arasindaki uzaklik :\n\n");
    printf("~~~ %f\n",distances[0]);
    toplam = 0.0;
    for(int i = 0;i < 20;i++){
        toplam += pow((calculated_frequencies[i] - frequency_germ[i]),2);
    }
    distances[1] = sqrt(toplam);
    printf("\n Metnin almanca ile arasindaki uzaklik :\n\n");
    printf("~~~ %f\n",distances[1]);
}

//Metnin yazıldığı dilin ekrana yazdırılması

void detect_lang(){

 if(distances[1] > distances[0]){
    printf("~~~ Bu metnin yazildigi dil : %s.",languages[0]);
 }
 else{
    printf("~~~ Bu metnin yazildigi dil : %s",languages[1]);
 }

}
