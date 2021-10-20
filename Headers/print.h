#ifndef _FLAG_PRINT
#define _FLAG_PRINT 1
#include <iostream>
#include <vector>
int _print_matrix_border_col ()
{
    printf ("\033[1;31m");
    return 0;
}
int _print_matrix_text_col ()
{
    printf ("\033[36m");
    return 0;
}
int _print_matrix_highlighted_text_conditon ()
{
    
    return 1; // 0 means condition is false!
}
int _print_matrix_highlighted_text_col ()
{
    printf ("\033[35m");
    return 0; // 0 means condition is false!
}
int _num_of_chars (int x)
{
    int count {0};
    if (x < 0)
    {
        x = ((-1) * x);
        count++;
    }
    for (; x != 0; x /= 10)
    {
        count++;
    }
    return count;
}
int _print_array_of_int (int arr[], int n)
{
    printf ("\033[31m{\033[m");
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf ("\033[36m%d\033[m\033[31m,\033[m ", arr[i]);
        else
            printf ("\033[36m%d\033[m", arr[i]);
    }
    printf ("\033[31m}\033[m \n");
}
int _print_matrix_of_int (void *m, int r, int c)
{
    int (*matrix)[c] = (int (*)[c]) (m);
    int _max_num_of_characters_in_a_column[c] {0};
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (_max_num_of_characters_in_a_column[i] < _num_of_chars (matrix[j][i]))
                _max_num_of_characters_in_a_column[i] = _num_of_chars (matrix[j][i]);
        }
    }
    // starting border:
    _print_matrix_border_col ();
    printf ("\332");
    printf ("\033[m");
    for (int i = 0; i < c; i++)
    {
        printf ("%*c", _max_num_of_characters_in_a_column[i], ' ');
        if (i != c - 1)
            printf (" ");
        else;
    }
    _print_matrix_border_col ();
    printf ("\277");
    printf ("\033[m \n"); // <<-- newline here;
    // internal text:
    for (int i = 0; i < r; i++)
    {
        _print_matrix_border_col ();
        printf ("\263\033[m");
        for (int j = 0; j < c; j++)
        {
            _print_matrix_text_col ();
            printf ("%*d", _max_num_of_characters_in_a_column[j], matrix[i][j]);
            printf ("\033[m");
            if (j != c - 1)
                printf (" ");
            else;
        }
        _print_matrix_border_col ();
        printf ("\263\033[m");
        printf (" \n"); // <<-- newline here;
    }
    //ending border:
    _print_matrix_border_col ();
    printf ("\300");
    printf ("\033[m");
    for (int i = 0; i < c; i++)
    {
        printf ("%*c", _max_num_of_characters_in_a_column[i], ' ');
        if (i != c - 1)
            printf (" ");
        else;
    }
    _print_matrix_border_col ();
    printf ("\331");
    printf ("\033[m \n"); // <<-- newline here;
    // printf ("\033[35m\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\033[m \n");
    // printf ("\033[35m\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\033[m \n");
    return 0;
}
int _print_vector_of_vec_of_int (std::vector <std::vector <int>> vec)
{
    std::cout << "\033[32m<\033[m" << std::endl;
    for (int i = 0; i < vec.size (); i++)
    {
        std::cout << "  \033[31m<\033[m";
        for (int j = 0; j < (vec.at (i)).size (); j++)
        {
            if (j != ((vec.at (i)).size ()) - 1)
                std::cout << "\033[36m" << (vec.at (i)).at (j) << "\033[m" << "\033[31m,\033[m ";
            else
                std::cout << "\033[36m" << (vec.at (i)).at (j) << "\033[m";
        }
        std::cout << "\033[31m>\033[m\033[32m;\033[m " << std::endl;
    }
    std::cout << "\033[32m>\033[m" << std::endl;
    return 0;
}
int _print_int_into_binary (int num, int _num_of_digits_ = -1)
{
    unsigned int n = (unsigned int) (num);
    int arr[32];
    int i {0};
    for (; n != 0; n >>= 1, i++)
    {
        arr[i] = (n & 0x1);  
    }
    int ret = i;
    if (_num_of_digits_ > ret)
    {
        std::cout << "\033[90m";
        for (int a = 0; a < _num_of_digits_ - ret; a++)
        {
            std::cout << "0";
        }
        std::cout << "\033[m";
    }
    i--;
    for (; i >= 0; i--)
    {    
        if (arr[i] == 0)
            printf ("\033[90m%d\033[m", arr[i]);
        else
            printf ("\033[32m%d\033[m", arr[i]);
    }
    return ret;
}
#endif