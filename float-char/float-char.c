/*编程实现：将两个float类型的值59，622f与92.6327f存入一个长度为4的char数组中，再从该数组中提取出两个float类型的值，使用你能想到的方法，缩小提取出的小数和原来数字之间的差距*/
#include<stdio.h>
#include<math.h>
#include<string.h>
void method1()
{
    float f1 = 59.622f;
    float f2 = 92.6327f;
    char buffer[4];

    //压缩存储
    float avg = (f1 + f2) / 2;
    float diff = f2 - f1;

    unsigned int combined = 0;
    unsigned int avg_bits = *((unsigned int *)(&avg));
    unsigned int diff_bits = *((unsigned int *)(&diff));

    combined = (avg_bits & 0xFFFF0000) |((diff_bits >> 16)&0xFFFF);
    memcpy(buffer,&combined,4);

    //解压缩
    unsigned int extracted;
    memcpy(&extracted,buffer,4);
    unsigned int ext_avg_bits = (extracted & 0xFFFF0000);
    unsigned int ext_diff_bits = (extracted  & 0xFFFF)<<16;

    float ext_avg = *((float *)(&ext_avg_bits));
    float ext_diff = *((float *)(&ext_diff_bits));

    float ext_f1 = ext_avg - ext_diff/2;
    float ext_f2 = ext_avg + ext_diff/2;

    printf("(method1)\noriginal:f1=%.6f f2=%.6f\n",f1,f2);
    printf("extracted:ext_f1=%.6f ext_f2=%.6f\n",ext_f1,ext_f2);
    printf("absolute error:%.6f  %.6f\n",fabs(f1-ext_f1),fabs(f2-ext_f2));
    printf("relative error:%.2f%%  %.2f%%\n",fabs(f1-ext_f1)/f1*100,fabs(f2-ext_f2)/f2*100);
}
void method2()
{
    float f1 = 59.622f;
    float f2 = 92.6327f;
    char buffer[4];

    //压缩存储
    float scale=100.0f;
    short s1 = (short)(scale*f1);
    short s2 = (short)(scale*f2);

    unsigned int combined = (((unsigned int)((unsigned short)s1)) << 16)|((unsigned int)s2);
    memcpy(buffer,&combined,4);
    //解压缩
    unsigned int extracted = *((unsigned int *)buffer);
    short ext_s1 = (short)(extracted >> 16);
    short ext_s2 = (short)(extracted & 0xFFFF);
    
    float ext_f1 = ext_s1/scale;
    float ext_f2 = ext_s2/scale;

    printf("(method2)\noriginal:f1=%.6f f2=%.6f\n",f1,f2);
    printf("extracted:ext_f1=%.6f ext_f2=%.6f\n",ext_f1,ext_f2);
    printf("absolute error:%.6f  %.6f\n",fabs(f1-ext_f1),fabs(f2-ext_f2));
    printf("relative error:%.2f%%  %.2f%%\n",fabs(f1-ext_f1)/f1*100,fabs(f2-ext_f2)/f2*100);
}
int main()
{
    printf("storing two float values (%.6f %.6f)in 4-byte char array\n\n",59.622f,92.6327f);
    method1();
    method2();
    return 0;
}