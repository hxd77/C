#include<stdio.h>
int main()
{
    float h,r,l,s,sq,vq,vz;
    float pi=3.141526;
    printf("请输入圆半径r,圆柱高h: ");
    scanf("%f,%f",&r,&h);
    l=2*pi*r;       //计算圆周长
    s=r*r*pi;       //计算圆面积
    sq=4*pi*r*r;    //计算圆球表面积
    vq=3.0/4.0*pi*r*r*r;    //计算圆球体积vq
    vz=pi*r*r*h;            //计算圆柱体vz
    printf("圆周长为:       l=%6.2f\n", l);
    printf("圆面积为:       s=%6.2f\n",s);
    printf("圆球表面积为:    sq=%6.2f\n",sq);
    printf("圆球体积为:      vq=%6.2f\n",vq);
    printf("圆柱体积为:      vz=%6.2f\n",vz);
    return 0;
    

}