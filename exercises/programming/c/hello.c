#include<stdio.h>

int main(){

printf("hello, world! \n");

int a;
int *p;
int *q;
int *diff;
a = 6;
p = &a;

*p=8;


printf("a is %d\n",a);
printf("address p is            %p\n", p);
//p++;
q=p++;

diff = p-q;

printf("next address after p is %p\n", p);
printf("next address after q is %p\n", q);

printf("difference between q and p is  %p\n", diff);



printf("value pointed by p is %d\n", *p);

}
