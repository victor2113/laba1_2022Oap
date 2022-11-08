#include <stdio.h>
#include "martix.h"

int main() {
    Mat mat1 = {4, 2, NULL};
    Mat mat2 = {2, 4, NULL};
    Mat mat3;
    //Функция создания матрицы с выделением памяти

    mat1 = create_mat(mat1);
    mat2 = create_mat(mat2);

    //Заполнение матрицы рандомом в заданном диапазоне

    fill_mat(mat1);
    fill_mat(mat2);

    print_mat(mat1);
    print_mat(mat2);

    // Сложение и вычитание матриц с возвращением новой матрицы в качестве результата

    mat3 = mat_sum(mat1 , mat2);
    print_mat(mat3);
    mat3 = mat_subtraction(mat1 , mat2);
    print_mat(mat3);

    //Матричное умножение с возвращением новой матрицы

    mat3 = mat_multiplication(mat1 , mat2);
    print_mat(mat3);

    //Транспонирование матрицы с возвращением новой матрицы

    mat2 = mat_tran(mat2);
    print_mat(mat2);

    //Удаление матрицы (освобождение памяти)
    mat3 = copy_mat(mat2);
    free_mat(mat3);



    /*Все функции должны проверять на ошибки с размерами матриц
      и т.д. В качестве ошибки из функции можно возвращать матрицу
      с NULL по массиву данных и -1 по размерам.
    */

    Mat mat4 = {0 , 0 , NULL};
    fill_mat(mat4);
    mat4 = mat_tran(mat4);
    print_mat(mat4);




    return 0;
}



