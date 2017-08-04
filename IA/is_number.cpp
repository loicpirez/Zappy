#include <cstring>
#include <iostream>

#include "../include/Client.hh"

int is_number(char *str)
{
    for (size_t i = 0; i < std::strlen(str); i++)
        {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);    
        }
    return (0);
}
