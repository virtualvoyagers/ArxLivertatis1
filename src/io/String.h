
#ifndef ARX_IO_STRING_H
#define ARX_IO_STRING_H

#include <string>

/**
 * Converts a given string into uppercase characters
 * @param A reference to the string being converted
 * @return A copy of the converted string
 */
std::string MakeUpcase(std::string & str);

bool IsIn(const std::string & strin, const std::string & str);
bool NC_IsIn(std::string strin, std::string str);
int strcasecmp(const std::string & str1, const std::string & str2);
int strcmp(const std::string & str1, const std::string & str2);

/**
 * Converts a given string to an integer using stringstream
 * @param str The string to be converted
 * @return The integer created by stringstream
 */
int atoi( const std::string& str );

/**
 * Converts a given integer to a string using stringstream
 * @param i The integer to be converted
 * @return The string create by stringstream
 */
std::string itoa( int i );

/**
 * Checks if a string (seek) is at the start of another string (text)
 * returns 0 if "seek" is at the start of "text"
 * else returns 1
 */
long specialstrcmp(const std::string & text, const std::string & seek);

void SAFEstrcpy(char * dest, const char * src, unsigned long max);

#endif // ARX_IO_STRING_H
