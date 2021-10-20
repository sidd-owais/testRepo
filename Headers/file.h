#include <stdio.h>
void print_gap (int gap_size, int printf_return)
{
    for (int i = 0; i < gap_size - printf_return; i++)
    {
        printf (" ");
    }
}
void print_file_data_colored (FILE *file_pointer)
{
    printf ("\033[1;4;36mstructure_ptr:\033[m \033[1;31m%p\033[m \033[1;30m(%d)\033[m \n", file_pointer, file_pointer);
    printf ("char *_ptr: %p (%d) \n", file_pointer->_ptr, file_pointer->_ptr);
    printf ("int _cnt: %d \n", file_pointer->_cnt);
    printf ("char *_base: %p (%d) \n", file_pointer->_base, file_pointer->_base);
    printf ("int _flag: %d \n", file_pointer->_flag);
    printf ("int _file: %d \n", file_pointer->_file);
    printf ("int _charbuf: %d \n", file_pointer->_charbuf);
    printf ("int _bufsiz: %d \n", file_pointer->_bufsiz);
    printf ("char *_tmpfname: %p (%d) \n", file_pointer->_tmpfname, file_pointer->_tmpfname);
    printf ("\033[36m------------------------------------->>->>->>->>->>->>->>->>->>->>->>\33[m \n");
}
void print_file_data (FILE *file_pointer)
{
    printf ("\033[1;4;36mstructure_ptr:\033[m \033[1;31m%p\033[m \033[1;30m(%d)\033[m \n", file_pointer, file_pointer);
    printf ("char *_ptr: %p (%d) \n", file_pointer->_ptr, file_pointer->_ptr);
    printf ("int _cnt: %d \n", file_pointer->_cnt);
    printf ("char *_base: %p (%d) \n", file_pointer->_base, file_pointer->_base);
    printf ("int _flag: %d \n", file_pointer->_flag);
    printf ("int _file: %d \n", file_pointer->_file);
    printf ("int _charbuf: %d \n", file_pointer->_charbuf);
    printf ("int _bufsiz: %d \n", file_pointer->_bufsiz);
    printf ("char *_tmpfname: %p (%d) \n", file_pointer->_tmpfname, file_pointer->_tmpfname);
    printf ("------------------------------------->>->>->>->>->>->>->>->>->>->>->> \n");
}
void print_initial_final_file_data (FILE *file_pointeri, FILE *file_pointerf)
{
    int gap = 40;
    print_gap(gap, printf ("\033[1;4;36mInitial File Structure:\033[m ") - 12);
    printf ("\033[1;4;36mFinal File Structure:\033[m \n");
    print_gap (gap, printf ("char *_ptr: %p (%d) ", file_pointeri->_ptr, file_pointeri->_ptr));
    printf ("char *_ptr: %p (%d) \n", file_pointerf->_ptr, file_pointerf->_ptr);
    print_gap (gap, printf ("int _cnt: %d ", file_pointeri->_cnt));
    printf ("int _cnt: %d \n", file_pointerf->_cnt);
    print_gap (gap, printf ("char *_base: %p (%d) ", file_pointeri->_base, file_pointeri->_base));
    printf ("char *_base: %p (%d) \n", file_pointerf->_base, file_pointerf->_base);
    print_gap (gap, printf ("int _flag: %d ", file_pointeri->_flag));
    printf ("int _flag: %d \n", file_pointerf->_flag);
    print_gap (gap, printf ("int _file: %d ", file_pointeri->_file));
    printf ("int _file: %d \n", file_pointerf->_file);
    print_gap (gap, printf ("int _charbuf: %d ", file_pointeri->_charbuf));
    printf ("int _charbuf: %d \n", file_pointerf->_charbuf);
    print_gap (gap, printf ("int _bufsiz: %d ", file_pointeri->_bufsiz));
    printf ("int _bufsiz: %d \n", file_pointerf->_bufsiz);
    print_gap (gap, printf ("char *_tmpfname: %p (%d) ", file_pointeri->_tmpfname, file_pointeri->_tmpfname));
    printf ("char *_tmpfname: %p (%d) \n", file_pointerf->_tmpfname, file_pointerf->_tmpfname);
    printf ("\033[33m==================================================================\33[m \n");
}