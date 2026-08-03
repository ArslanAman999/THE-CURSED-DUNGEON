#pragma once
/*
    StringUtility Class:    This class provides helper functions for handling
                            char* using manual memory management.
*/
class StringUtility
{
    static int stringlen(const char* s)
    {
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }
        return len;
    }
public:
    // Creates a deep copy
    static char* copy(const char* source)
    {
        if (!source)
        {
            return nullptr;
        }

        int length = stringlen(source);

        char* newStr = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            newStr[i] = source[i];
        }

        newStr[length] = '\0';
        return newStr;
    }

    // Combines two char* strings into a new string
    static char* concat(const char* first, const char* second)
    {
        if (!first || !second)
        {
            return nullptr;
        }

        int len1 = stringlen(first);
        int len2 = stringlen(second);

        char* result = new char[len1 + len2 + 1];

        for (int i = 0; i < len1; i++)
        {
            result[i] = first[i];
        }

        for (int i = 0; i < len2; i++)
        {
            result[len1 + i] = second[i];
        }

        result[len1 + len2] = '\0';
        return result;
    }

    // Destroies char* memory
    static void destroy(char* str)
    {
        if (str)
        {
            delete[] str;
        }
    }
};

