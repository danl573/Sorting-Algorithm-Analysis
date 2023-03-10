#ifndef DSSTRING
#define DSSTRING

#include <iostream>
#include <cstring>

class DSString{

private:
    char* str;
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/


public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    /**
     * Standard relational operators.  You are free to expand this
     * list if you'd like.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    bool operator== (const char*) const;
    bool operator== (const DSString&) const;
    bool operator> (const DSString&) const;
    bool operator>= (const DSString&) const;
    bool operator< (const DSString&) const;
    bool operator<= (const DSString&) const;
    char& operator[] (const int) const;

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength();

    /**
     * find(char) returns the first index of the character given
     * @return index
     */
    int find(char);

    /**
     * find(char, int) returns the <int> index of the character given
     * @return index
     */
    int find(char, int);

    /**
     * findLast(char) returns the last index of the character given
     * @return index
     */
    int findLast(char);

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     **/
    DSString substring(int start, int numChars);

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    void toLower();

    void toUpper();

    int convertInt();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream& operator<<(std::ostream&, const DSString&);

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.

};


#endif