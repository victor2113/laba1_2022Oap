#include <stdio.h>
#include "martix.h"

int main() {
    Mat mat1 = {2, 4, NULL};
    Mat mat2 = {2, 2, NULL};
    Mat mat3;
    mat1 = create_mat(mat1);
    mat2 = create_mat(mat2);
    fill_mat(mat1);
    fill_mat(mat2);


    print_mat(mat1);
    print_mat(mat2);
    //print_mat(mat3);
    mat3 = mat_sum(mat1 , mat2);
    print_mat(mat3);

    /*
    print_mat(mat2);
    mat3 = sum_mats(mat1 , mat2);
    print_mat(mat3);
    mat3 = mat_multiplication(mat1 , mat2);
    print_mat(mat3); */
    return 0;
}



