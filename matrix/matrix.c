#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct MParam{
    uint8_t row;
    uint8_t colume;
    float **data;
};
typedef struct MParam Matrix;
void func();
int main()
{
    func();
    return 0;
}
void func()
{
    Matrix origin_mat;
    printf("please enter the row and colume of the matrix:");
    scanf("%hhu%hhu",&origin_mat.row,&origin_mat.colume);

    origin_mat.data=(float **)malloc(origin_mat.row*sizeof(float *));
    for(int i=0;i<origin_mat.row;i++)
    origin_mat.data[i] = (float *)malloc(origin_mat.colume*sizeof(float));

    //输入矩阵元素
    printf("now please enter the elements of the matrix:");
    for(int i=0;i<origin_mat.row;i++)
    {
        for(int j=0;j<origin_mat.colume;j++)
            scanf("%f",&origin_mat.data[i][j]);
    }

    Matrix rev_mat;
    rev_mat.row=origin_mat.colume;
    rev_mat.colume=origin_mat.row;
    
    rev_mat.data=(float **)malloc(rev_mat.row*sizeof(float *));
    for(int i=0;i<rev_mat.row;i++)
    rev_mat.data[i] = (float *)malloc(rev_mat.colume*sizeof(float));

    for(int i=0;i<rev_mat.row;i++)
    {
        for(int j=0;j<rev_mat.colume;j++)
        rev_mat.data[i][j]=origin_mat.data[j][i];
    }

    Matrix result_mat;
    result_mat.row=origin_mat.row;
    result_mat.colume=rev_mat.colume;
    
    result_mat.data = (float **)malloc(result_mat.row*sizeof(float *));
    for(int i=0;i<result_mat.row;i++)
    result_mat.data[i] = (float *)malloc(result_mat.colume*sizeof(float));


    for(int i=0;i<result_mat.row;i++)
    {
        for(int j=0;j<result_mat.colume;j++)
        {
            result_mat.data[i][j]=0.0;
            for(int k=0;k<origin_mat.colume;k++)
            {
                result_mat.data[i][j]+=origin_mat.data[i][k]*rev_mat.data[k][j];
            }
        }
    }
    printf("the result_matrix:\n");
    for(int i=0;i<result_mat.row;i++)
    {
        for(int j=0;j<result_mat.colume;j++)
        printf("%.2f ",result_mat.data[i][j]);
        printf("\n");
    }
    for(int i=0;i<origin_mat.row;i++)
    {
        free(origin_mat.data[i]);
        origin_mat.data[i]=NULL;
    }
    for(int i=0;i<rev_mat.row;i++)
    {
        free(rev_mat.data[i]);
        rev_mat.data[i]=NULL;
    }
    for(int i=0;i<result_mat.row;i++)
    {
        free(result_mat.data[i]);
        result_mat.data[i]=NULL;
    }
    free(origin_mat.data);
    origin_mat.data=NULL;
    free(rev_mat.data);
    rev_mat.data=NULL;
    free(result_mat.data);
    result_mat.data=NULL;
}
