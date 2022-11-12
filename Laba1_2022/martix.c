#include "martix.h"
#include <stdio.h>
#include <stdlib.h>


#define WRONGSIZE "\nImposible matrix size value\n"



Mat Zero = {-1 , -1 , NULL};

Mat create_filled_mat(int w, int h, int value) {
    Mat mat ={w, h, NULL};

    if(mat.w <= 0 || mat.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    mat.t = malloc(sizeof(*mat.t) * mat.w);
    for (int i = 0; i < mat.w; ++i)
        mat.t[i] = malloc(sizeof(**mat.t) * mat.h);
    for (int i = 0; i < mat.w; ++i)
        for (int j = 0; j < mat.h; ++j)
            mat.t[i][j] = value;
    return mat;
}//done

Mat create_empty_mat(Mat mat) {
    if(mat.w <= 0 || mat.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    mat.t = malloc(sizeof(*mat.t) * mat.w);
    for (int i = 0; i < mat.w; ++i)
        mat.t[i] = malloc(sizeof(**mat.t) * mat.h);
    return mat;
}//done

void print_mat(Mat mat) {
    if (mat.t == NULL || mat.h <= 0 || mat.w <= 0) {
        printf("\nTrying to print empty matrix\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < mat.w; ++i) {
        for (int j = 0; j < mat.h; ++j)
            printf("%d ", mat.t[i][j]);
        printf("\n");
    }
    printf("\n");
}//done

void print_mat_arguments(Mat mat) {
    printf("\nwidth = %d , height = %d\n",mat.w , mat.h);
}//done

void free_mat(Mat mat) {
    for (int i = 0; i < mat.w; ++i) {
        free(mat.t[i]);
    }
    free(mat.t);
}

Mat mat_sum(Mat mat1, Mat mat2) { //добавить проверки
    if(mat1.w <= 0 || mat1.h <= 0 || mat2.w <= 0 || mat2.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    if(mat1.w != mat2.w || mat1.h != mat2.h){
        printf("matrix sum is not possible\n");;
        return Zero;
    }

    Mat result = {mat1.w, mat1.h, NULL};
    result = create_empty_mat(result);
    //if(result.w != mat1.w != mat2.w)
    //return result;
    for (int i = 0; i < result.w; ++i)
        for (int j = 0; j < result.h; ++j)
            result.t[i][j] = mat1.t[i][j] + mat2.t[i][j];
    return result;
}//done?

Mat mat_subtraction(Mat mat1, Mat mat2) {
    if(mat1.w <= 0 || mat1.h <= 0 || mat2.w <= 0 || mat2.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    if(mat1.w != mat2.w || mat1.h != mat2.h){
        printf("matrix subtraction is not possible\n");
        return Zero;
    }
    Mat result = {mat1.w, mat1.h, NULL};
    result = create_empty_mat(result);
    //if(result.w != mat1.w != mat2.w)
    //return result;
    for (int i = 0; i < result.w; ++i)
        for (int j = 0; j < result.h; ++j)
            result.t[i][j] = mat1.t[i][j] - mat2.t[i][j];
    return result;
}//done?

void fill_mat(Mat mat , int range)  {
    if(mat.w <= 0 || mat.h <= 0){
        printf("\nTrying to fill empty matrix\n");
    }
    for (int i = 0; i < mat.w; ++i)
        for (int j = 0; j < mat.h; ++j)
            mat.t[i][j] = rand() % range;
}//done?

Mat mat_multiplication(Mat mat1, Mat mat2) {
    if(mat1.w <= 0 || mat1.h <= 0 || mat2.w <= 0 || mat2.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    if(mat1.h != mat2.w){
        printf("\nmatrix multiplication is not possible\n");;
        return Zero;
    }
    Mat result = {mat1.w, mat2.h, NULL};
    result = create_empty_mat(result);
    //if(result.w != mat1.w != mat2.w)
    //return result;
    for (int i = 0; i < result.w; ++i)
        for (int j = 0; j < result.h; ++j) {
            result.t[i][j] = 0;
            for (int k = 0; k < mat1.h; k++)
                result.t[i][j] += mat1.t[i][k] * mat2.t[k][j];
        }


    return result;
}//done

Mat mat_tran(Mat mat) {
    if(mat.w <= 0 || mat.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }
    Mat result = {mat.h, mat.w, NULL};
    result = create_empty_mat(result);
    //if(result.w != mat1.w != mat2.w)
    //return result;
    for (int i = 0; i < result.w; ++i)
        for (int j = 0; j < result.h; ++j)
            result.t[i][j] = mat.t[j][i];
    return result;
}//done?

Mat copy_mat(Mat mat){
    if(mat.w <= 0 || mat.h <= 0){
        printf(WRONGSIZE);
        return Zero;
    }

    Mat result = {mat.w, mat.h, NULL};
    result = create_empty_mat(result);
    for (int i = 0; i < result.w; ++i)
        for (int j = 0; j < result.h; ++j)
            result.t[i][j] = mat.t[i][j];
    return result;
}//done

void printZero(){
    printf("\nSomething went wrong\n");
}