#include<stdio.h>



#include<math.h>//chua hang so pi la M_PI

int main()

{float pi,t,n,eps,dau;



printf("Nhap sai so eps=");scanf("%f",&eps);

pi=0;t=4;n=dau=1;

do

{pi+=dau*t; n=n+2;

dau=-dau; t=4/n;

}while (t>=eps);

printf("\nSo PI tinh duoc voi sai so %12.10f, PI=%12.10f\n",eps,pi);

printf("\nSo PI cua Turbo C++, PI=%12.10f\n",M_PI);


}