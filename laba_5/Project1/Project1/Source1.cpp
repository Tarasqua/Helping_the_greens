#include <iostream>
#include <cstring>
#include <string_view>

const char* delims = "!'\";:?-., ";

int strToWords(const char str[81], char* words[40], int wordLength[40])
{
    int word = strcspn(str, delims);
    int ignore = strspn(str, delims);
    int count = 0;
    while (word || ignore)
    {
        if (word)
        {
            words[count] = const_cast<char*>(str);
            wordLength[count] = word;
            ++count;
        }
        str += word + ignore;
        word = strcspn(str, delims);
        ignore = strspn(str, delims);
    }
    return count;
}

int main()
{
    const char str[81] = "fuuck, qweqw-qwe! dsasd\"dsa";
    char* words[40]{};
    int wordLength[40]{};

    int count = strToWords(str, words, wordLength);

    for (int i = 0; i < count; ++i)
        std::cout << words[i] << std::endl;
}