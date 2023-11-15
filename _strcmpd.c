#include "shell.h" 
/**
 *  You may need to include any necessary header files.
 *  */

int _strcmpd(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
/**
 * both strings are equal
 * */ 
    return 0; 
}