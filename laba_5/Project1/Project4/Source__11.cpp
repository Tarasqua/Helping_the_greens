#include <iostream>
#include <string>
using namespace std;

int numOfWords(string* str, int N)
{
    int count = 0;
    int last_pos = 0;
    while (str[N].find(" ", last_pos) != std::string::npos) {
        last_pos = str[N].find(" ", last_pos + 1);
        count++;
    }

    return count == 0 ? 1 : count;
}

string* resize(const string* str, unsigned size, unsigned new_size)
{
    string* new_str = new string[new_size];
    for (int i = 0; i < size; i++)
    {
        new_str[i] = str[i];
    }
    delete[]str;
    return new_str;
}

int main()
{
    string word;
    int k = 0;
    string* str = new string[k + 1];
    char buf[256];

    while (1)
    {
        cin.getline(buf, 256, '\n');  //getline необходим из-за того что string сам разбивает строки на слова
        word = buf;
        if (word == "done") break;
        str = resize(str, k, k + 1);
        str[k] = word;
        k++;
    }

    for (int i = 0; i < k; i++) {
        cout << numOfWords(str, i) << endl;
    }

    for (int i = 0; i < k; i++)
    {
        cout << str[i] << "\n";
    }

    return 0;
}