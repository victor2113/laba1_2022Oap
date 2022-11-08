#ifndef LABA1_2022_MARTIX_H
#define LABA1_2022_MARTIX_H

#endif //LABA1_2022_MARTIX_H


typedef struct myMat {
    int w;//width
    int h;//height
    int **t;//table
} Mat;

void printZero();
Mat create_mat(Mat mat);

void print_mat(Mat mat);

void fill_mat(Mat mat);

Mat free_mat(Mat mat);

Mat mat_sum(Mat mat1, Mat mat2);

Mat mat_multiplication(Mat mat1, Mat mat2);

Mat mat_tran(Mat mat);

Mat copy_mat(Mat mat);

Mat mat_subtraction(Mat mat1, Mat mat2);

