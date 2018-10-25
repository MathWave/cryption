#include <fstream>

void Encrypt(std::string file, std::string code)
{
    std::ifstream fin(file);
    std::ofstream fout(file + ".crypt");
    std::string full_string = "";
    std::string buffer = "";
    while (getline(fin, buffer))
        full_string += (buffer + '\n');
    full_string.pop_back();
    std::string mask = "";
    while (mask.size() < full_string.size())
        mask += code;
    while (mask.size() > full_string.size())
        mask.pop_back();
    std::string new_string = "";
    for (int i = 0; i < mask.size(); i++)
        new_string += full_string[i] ^ mask[i];
    fout << new_string;
    fin.close();
    fout.close();
}

void Decrypt(std::string file, std::string code)
{
    std::ifstream fin(file);
    std::string new_name = file;
    for (int i = 0; i < 6; i++)
        new_name.pop_back();
    std::ofstream fout(new_name);
    std::string full_string = "";
    std::string buffer = "";
    while (getline(fin, buffer))
        full_string += (buffer + '\n');
    full_string.pop_back();
    std::string mask = "";
    while (mask.size() < full_string.size())
        mask += code;
    while (mask.size() > full_string.size())
        mask.pop_back();
    std::string new_string = "";
    for (int i = 0; i < mask.size(); i++)
        new_string += full_string[i] ^ mask[i];
    fout << new_string;
    fin.close();
    fout.close();
}

int main()
{
    std::string file = "";
    std::string code = "";
    //Encrypt(file, code);
    //Decrypt(file, code);
}
