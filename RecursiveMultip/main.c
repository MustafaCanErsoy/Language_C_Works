#include <stdio.h>
#include <stdlib.h>
int recMultip(int x , int y){
    if((x == 0 || y==0)) return 0;
    else if (y<0) return -x + recMultip(x,y+1);
    else return x+recMultip(x,y-1);


}
int main()
{
    printf("Hello world!\n");
    int a = recMultip(12,-4);
    printf("%d",a);
    return 0;
}
