/* this is a header file made in C language (also works with C++)
** it contains many earlier functions that have been discontinued (can be enabled by uncommenting them)
** the macro _BITS_N_BYTES is used as an include guard for the entire header file (make sure not to use any such macro in other files)
** using the macro anywhere else (in the program) can result in the non-inclusion of the header file
*/
#ifndef _BITS_N_BYTES
#define _BITS_N_BYTES 1
#include <stdio.h>
int border_color ()//works for box-func only
{
    printf ("\033[31m");
    return 0;
}
int decoded_text_col ()//works for box-func only
{
    printf ("\033[34m");
    return 0;
}
//bits_n_bytes color-formatting:-
int _bits_n_bytes_border_color ()//works for box-func only
{
    printf ("\033[33m");
    return 0;
}
int _bits_n_bytes_offset_col ()//works for box-func only
{
    printf ("\033[31m");
    return 0;
}
int _bits_n_bytes_hex_col ()//works for box-func only
{
    printf ("\033[90m");
    return 0;
}
int _bits_n_bytes_binary_col ()//works for box-func only
{
    printf ("\033[35m");
    return 0;
}
int _bits_n_bytes_decoded_text_col ()//works for box-func only
{
    printf ("\033[36m");
}
int _bits_n_bytes_invalid_text_col ()//works for box-func only
{
    printf ("\033[35m");
}
int _bits_n_bytes_pointer_col ()//works for box-func only
{
    printf ("\033[34m");
}
int _bits_n_bytes_integer_col ()//works for box-func only
{
    printf ("\033[34m");
}
//some mathematical functions:-
int _power_calc (int base, int power)
{
    if (power < 0)
    {
        return -1;
    }
    int answer = 1;
    for (int i = 0; i < power; i++)
    {
        answer = answer * base;
    }
    return answer;
}
int _char_to_int (char *address)
{
    char _char_array[4];
    _char_array[0] = *address;
    _char_array[1] = 0;
    _char_array[2] = 0;
    _char_array[3] = 0;
    int *_int_ptr = (int *) (_char_array);
    return *_int_ptr;
}
int _byte_to_binary_int (void *address)
{
    char *ptr = (char *) (address);
    int _integer = _char_to_int (ptr);
    int _binary_num = 0;
    for (int i = 0; _integer != 0; i++, _integer = (_integer / 2))
    {
        _binary_num = _binary_num + (_integer % 2) * (_power_calc (10, i));
    }
    return _binary_num;
}
/*int hex_viewer_col (void *start, int num_of_bytes)// discontinued
{
    unsigned char *st_ptr = (unsigned char *) (start);
    int counter1 = 0;
    int counter2 = 0;
    printf ("\033[32m<offset>\033[31m|\033[32m00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\033[m\033[31m|\033[m\033[32m<<Decoded Text>>\033[31m|\033[m \n");
    printf ("\033[31m--------\033[31m|\033[31m-----------------------------------------------\033[31m|\033[31m----------------\033[31m|\033[m \n");
    for (; (counter1 < num_of_bytes) || ((counter1 % 16) != 0); counter1++)
    {
        if (counter1 % 16 == 0)
        {
            if (counter1 != 0)
            {
                printf ("\b\033[31m|\033[m\033[33m");
                for (int j = 0; j < 16; counter2++, j++)
                {
                    if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                    {
                        printf ("\033[36m.\033[33m");
                    }
                    else
                    {
                        printf ("%c", *(st_ptr + counter2));
                    }
                }
                printf ("\033[m\033[31m|\033[m \n");
            }
            printf ("%p\033[31m|\033[m", counter1);
        }
        if (counter1 < num_of_bytes)
        { 
            printf ("%02x ", *(st_ptr + counter1));
        }
        else 
        {
            printf ("\033[30m--\033[m ");
        }
    }
    if (counter2 < counter1)
    {
        printf ("\b\033[31m|\033[m\033[33m");
        for (; counter2 < counter1; counter2++)
        {
            if (num_of_bytes <= counter2)
            {
                printf ("\033[30m.\033[m"); 
            }
            else
            {
                if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                {
                    printf ("\033[36m.\033[33m");
                }
                else
                {
                    printf ("%c", *(st_ptr + counter2));
                }
            }
            
        }
        printf ("\033[m\033[31m|\033[m \n");
    }  
}*/
/*int hex_viewer_col_box (void *start, int num_of_bytes)// discontinued
{
    unsigned char *st_ptr = (unsigned char *) (start);
    int counter1 = 0;
    int counter2 = 0;
    border_color ();
    printf ("\325\315\315\315\315\315\315\315\315\321\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\321\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\033[m \n");
    border_color ();
    printf ("\263\033[32m<offset>");
    border_color ();
    printf ("\263\033[m\033[32m00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\033[m");
    border_color ();
    printf ("\263\033[m\033[32m<<Decoded Text>>");
    border_color ();
    printf ("\263\033[m \n");
    border_color ();
    printf ("\306\315\315\315\315\315\315\315\315\330\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\330\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\265\033[m \n");
    for (; (counter1 < num_of_bytes) || ((counter1 % 16) != 0); counter1++)
    {
        if (counter1 % 16 == 0)
        {
            if (counter1 != 0)
            {
                printf ("\b\033[31m\263\033[m");
                decoded_text_col ();
                for (int j = 0; j < 16; counter2++, j++)
                {
                    if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                    {
                        printf ("\033[m");
                        printf ("\033[35m.");
                        printf ("\033[m");
                        decoded_text_col ();
                    }
                    else
                    {
                        printf ("%c", *(st_ptr + counter2));
                    }
                }
                printf ("\033[m");
                border_color ();
                printf ("\263\033[m");
                printf (" \n");//newline occurs here <<-- <<-- <<-- <<-- <<-
            }
            border_color ();
            printf ("\263\033[m");
            printf ("\033[36m%p\033[31m\263\033[m", counter1);
        }
        if (counter1 < num_of_bytes)
        { 
            printf ("\033[35m%02x\033[m ", *(st_ptr + counter1));
        }
        else 
        {
            printf ("\033[35mxx\033[m ");
        }
    }
    if (counter2 < counter1)
    {
        printf ("\b");
        border_color ();
        printf ("\263\033[m");
        decoded_text_col ();
        for (; counter2 < counter1; counter2++)
        {
            if (num_of_bytes <= counter2)
            {
                printf ("\033[m");
                printf ("\033[30mx\033[m"); 
            }
            else
            {
                if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                {
                    printf ("\033[35m.");
                    printf ("\033[m");
                    decoded_text_col ();
                }
                else
                {
                    printf ("%c", *(st_ptr + counter2));
                }
            }
            
        }
        printf ("\033[m");
        border_color ();
        printf ("\263\033[m \n");
    }
    border_color ();
    printf ("\324\315\315\315\315\315\315\315\315\317\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\317\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\276\033[m \n");
}*/
int _trace_bytes (void *_start, int _byte_group_size, int _num_of_bytes)
{
    
    if ((_byte_group_size != 4) && (_byte_group_size != 8) && (_byte_group_size != 16) && (_byte_group_size != 24))
    {
        printf ("\033[31merror\033[33m: \033[35minvalid _byte_group_size value\033[33m, \033[31mchoices\033[33m: \033[35m{\033[36m4\033[35m, \033[36m8\033[35m, \033[36m16\033[35m, \033[36m24\033[35m}\033[m \n");
        return 0;
    }
    
    unsigned char *_st_ptr = (unsigned char *) (_start);
    printf ("\033[3;34m_start_pointer: \033[35m%x\033[36m; \033[m", _st_ptr);
    printf ("\033[3;34m_end_pointer: \033[35m%x\033[m \n", _st_ptr+ _num_of_bytes - 1);
    printf ("\033[3;34mnumber of bytes printed:\033[35m %d \033[31m(\033[34m%06x \033[33m+ \033[32m%02x\033[31m);\033[m \n", _num_of_bytes, ((_num_of_bytes - 1) / _byte_group_size) * _byte_group_size, (_num_of_bytes - 1) % _byte_group_size);
    int counter1 = 0;
    int counter2 = 0;
    //top-line1 start:
    border_color ();
    printf ("\325");
    printf ("\315\315\315\315\315\315\321");
    for (int i = 0; i < 2 * _byte_group_size + _byte_group_size - 1; i++)
    {
        printf ("\315");
    }
    printf ("\321");
    for (int i = 0; i < _byte_group_size; i++)
    {
        printf ("\315");
    }
    printf ("\270\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-line1 end;
    //toptext start:
    border_color ();
    printf ("\263\033[32moffset");
    border_color ();
    printf ("\263\033[m\033[32m");
    for (int i = 0; i < _byte_group_size; i++)
    {
        printf ("%02x ", i);
    }
    printf ("\b\033[m");
    border_color ();
    printf ("\263\033[m\033[32m");
    switch (_byte_group_size)
    {
        case 4:
        {
            printf ("Text");
            break;
        }
        case 8:
        {
            printf ("< Text >");
            break;
        }
        case 16:
        {
            printf ("< Decoded Text >");
            break;
        }
        case 24:
        {
            printf (" <<-- Decoded Text -->> ");
            break;
        }
    }
    printf ("\033[m");
    border_color ();
    printf ("\263\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-text end;
    //top-line2 start:
    border_color ();
    printf ("\306\315\315\315\315\315\315\330");
    for (int i = 0; i < 2 * _byte_group_size + _byte_group_size - 1; i++)
    {
        printf ("\315");
    }
    printf ("\330");
    for (int i = 0; i < _byte_group_size; i++)
    {
        printf ("\315");
    }
    printf ("\265\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-line2 end;
    for (; (counter1 < _num_of_bytes) || ((counter1 % _byte_group_size) != 0); counter1++)
    {
        if (counter1 % _byte_group_size == 0)
        {
            if (counter1 != 0)
            {
                printf ("\b\033[31m\263\033[m");
                decoded_text_col ();
                for (int j = 0; j < _byte_group_size; counter2++, j++)
                {
                    if (*(_st_ptr + counter2) == 0 || *(_st_ptr + counter2) == 255 || *(_st_ptr + counter2) == 27 || *(_st_ptr + counter2) == 13 || (*(_st_ptr + counter2) >= 7 && *(_st_ptr + counter2) <= 10))
                    {
                        printf ("\033[m");
                        printf ("\033[35m.");
                        printf ("\033[m");
                        decoded_text_col ();
                    }
                    else
                    {
                        printf ("%c", *(_st_ptr + counter2));
                    }
                }
                printf ("\033[m");
                border_color ();
                printf ("\263\033[m");
                printf (" \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
            }
            border_color ();
            printf ("\263\033[m");
            printf ("\033[36m%06x\033[31m\263\033[m", counter1);
        }
        if (counter1 < _num_of_bytes)
        { 
            printf ("\033[35m%02x\033[m ", *(_st_ptr + counter1));
        }
        else 
        {
            printf ("\033[35mxx\033[m ");
        }
    }
    if (counter2 < counter1)
    {
        printf ("\b");
        border_color ();
        printf ("\263\033[m");
        decoded_text_col ();
        for (; counter2 < counter1; counter2++)
        {
            if (_num_of_bytes <= counter2)
            {
                printf ("\033[m");
                printf ("\033[30mx\033[m"); 
            }
            else
            {
                if (*(_st_ptr + counter2) == 0 || *(_st_ptr + counter2) == 255 || *(_st_ptr + counter2) == 27 || *(_st_ptr + counter2) == 13 || (*(_st_ptr + counter2) >= 7 && *(_st_ptr + counter2) <= 10))
                {
                    printf ("\033[35m.");
                    printf ("\033[m");
                    decoded_text_col ();
                }
                else
                {
                    printf ("%c", *(_st_ptr + counter2));
                }
            }
            
        }
        printf ("\033[m");
        border_color ();
        printf ("\263\033[m \n");
    }
    //bottom-border start:
    border_color ();
    printf ("\324\315\315\315\315\315\315\317");
    for (int i = 0; i < 2 * _byte_group_size + _byte_group_size - 1; i++)
    {
        printf ("\315");
    }
    printf ("\317");
    for (int i = 0; i < _byte_group_size; i++)
    {
        printf ("\315");
    }
    printf ("\276\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
}
int _trace_bits_n_bytes (void *start, int _num_of_bytes)
{
    if ((_num_of_bytes % 4) != 0)
    {
        printf ("\033[31merror\033[33m: \033[35mthe number of bytes must be a multiple of 4\033[m \n");
        return 0;
    }
    unsigned char *_st_ptr = (unsigned char *) (start);
    printf ("\033[3;34m_start_pointer: \033[35m%x\033[36m; \033[m", _st_ptr);
    printf ("\033[3;34m_end_pointer: \033[35m%x\033[m \n", _st_ptr + _num_of_bytes - 1);
    printf ("\033[34mnumber of bytes printed:\033[35m %d \033[31m(\033[34m%06x \033[33m+ \033[32m%02x\033[31m);\033[m \n", _num_of_bytes, ((_num_of_bytes - 1) / 4) * 4, (_num_of_bytes - 1) % 4);
    int _offset_counter = 0;
    int _hex_counter = 0;
    int _binary_counter = 0;
    int _text_counter = 0;
    //top-line1 start:
    _bits_n_bytes_border_color ();
    printf ("\325");
    printf ("\315\315\315\315\315\315\321");//offset
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//in hexadecimal
    printf ("\321");
    printf ("\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315");//in binary
    printf ("\321");
    printf ("\315\315\315\315");//as text
    printf ("\321");
    printf ("\315\315\315\315\315\315\315\315");//as a pointer
    printf ("\321");
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//as an integer
    printf ("\270\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-line1 end;
    //top-text start:
    _bits_n_bytes_border_color ();
    printf ("\263\033[m");
    printf ("\033[32moffset\033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m\033[32m");
    for (int i = 0; i < 4; i++)
    {
        printf ("%02x ", i);
    }
    printf ("\b\033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m\033[32m");
    printf (" <<--   converted to binary   -->> \033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m\033[32m");
    printf ("text\033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m\033[32m");
    printf (">pointer\033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m\033[32m");
    printf (" [integer] \033[m");
    _bits_n_bytes_border_color ();
    printf ("\263\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-text end;
    //top-line2 start:
    _bits_n_bytes_border_color ();
    printf ("\306");
    printf ("\315\315\315\315\315\315");//offset
    printf ("\330");
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//in hexadecimal
    printf ("\330");
    printf ("\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315");//in binary
    printf ("\330");
    printf ("\315\315\315\315");//as text
    printf ("\330");
    printf ("\315\315\315\315\315\315\315\315");//as a pointer
    printf ("\330");
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//as an integer
    printf ("\265\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //top-line2 end;
    _bits_n_bytes_border_color ();
    for (; _offset_counter < _num_of_bytes; )
    {
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        _bits_n_bytes_offset_col ();
        printf ("%06x\033[m", _offset_counter);
        _offset_counter = _offset_counter + 4;
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        for (; _hex_counter < _offset_counter; _hex_counter++)
        {
            _bits_n_bytes_hex_col ();
            printf ("%02x\033[m ", *(_st_ptr + _hex_counter));
        }
        printf ("\b");
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        for (; _binary_counter < _offset_counter; _binary_counter++)
        {
            _bits_n_bytes_binary_col ();
            printf ("%08d\033[m ", _byte_to_binary_int (_st_ptr + _binary_counter));
        }
        printf ("\b");
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        for (; _text_counter <_offset_counter; _text_counter++)
        {
            if (*(_st_ptr + _text_counter) == 0 || *(_st_ptr + _text_counter) == 255 || *(_st_ptr + _text_counter) == 27 || *(_st_ptr + _text_counter) == 13 || (*(_st_ptr + _text_counter) >= 7 && *(_st_ptr + _text_counter) <= 10))
            {
                _bits_n_bytes_invalid_text_col ();
                printf (".\033[m");
            }
            else
            {
                _bits_n_bytes_decoded_text_col ();
                printf ("%c", *(_st_ptr + _text_counter));
            }
        }
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        _bits_n_bytes_pointer_col ();
        printf ("%08x\033[m", *((void **) (_st_ptr + _offset_counter - 4)));
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        _bits_n_bytes_integer_col ();
        printf ("%+011d\033[m", *((int *) (_st_ptr + _offset_counter - 4)));
        _bits_n_bytes_border_color ();
        printf ("\263\033[m");
        printf (" \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    }
    //bottom-line start:
    _bits_n_bytes_border_color ();
    printf ("\324");
    printf ("\315\315\315\315\315\315");//offset
    printf ("\317");
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//in hexadecimal
    printf ("\317");
    printf ("\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315");//in binary
    printf ("\317");
    printf ("\315\315\315\315");//as text
    printf ("\317");
    printf ("\315\315\315\315\315\315\315\315");//as a pointer
    printf ("\317");
    printf ("\315\315\315\315\315\315\315\315\315\315\315");//as an integer
    printf ("\276\033[m \n");//newline occurs here <<-- <<-- <<-- <<-- <<--
    //bottom-line end;
}

/*int hex_viewer (void *start, int num_of_bytes)
{
    unsigned char *st_ptr = (unsigned char *) (start);
    int counter1 = 0;
    int counter2 = 0;
    printf ("<offset>|00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f|<<Decoded Text>>| \n");
    printf ("--------|-----------------------------------------------|----------------| \n");
    for (; (counter1 < num_of_bytes) || ((counter1 % 16) != 0); counter1++)
    {
        if (counter1 % 16 == 0)
        {
            if (counter1 != 0)
            {
                printf ("\b|");
                for (int j = 0; j < 16; counter2++, j++)
                {
                    if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                    {
                        printf (".");
                    }
                    else
                    {
                        printf ("%c", *(st_ptr + counter2));
                    }
                }
                printf ("| \n");
            }
            printf ("%p|", counter1);
        }
        if (counter1 < num_of_bytes)
        { 
            printf ("%02x ", *(st_ptr + counter1));
        }
        else 
        {
            printf ("-- ");
        }
    }
    if (counter2 < counter1)
    {
        printf ("\b|");
        for (; counter2 < counter1; counter2++)
        {
            if (num_of_bytes <= counter2)
            {
                printf ("."); 
            }
            else
            {
                if (*(st_ptr + counter2) == 0 || *(st_ptr + counter2) == 255 || *(st_ptr + counter2) == 27 || *(st_ptr + counter2) == 13 || (*(st_ptr + counter2) >= 7 && *(st_ptr + counter2) <= 10))
                {
                    printf (".");
                }
                else
                {
                    printf ("%c", *(st_ptr + counter2));
                }
            }
            
        }
        printf ("| \n");
    }  
}*/
#endif