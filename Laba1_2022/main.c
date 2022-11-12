#include <stdio.h>
#include "martix.h"

int main() {
    Mat mat1;
    Mat mat2;
    Mat mat3;
    int range = 10;
    //Функция создания матрицы с выделением памяти

    mat1 = create_filled_mat(1 , 3, 2);
    mat2 =  create_filled_mat(3 , 1, 0);

    //Заполнение матрицы рандомом в заданном диапазоне

    //fill_mat(mat1 , range);
    fill_mat(mat2 , range);

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

    Mat mat4 = create_filled_mat(0 , 0 , 100);
    fill_mat(mat4 , range);
    mat4 = mat_tran(mat4);
    print_mat(mat4);




    return 0;
}
