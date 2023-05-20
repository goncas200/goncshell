#include "iostream"
#include "unistd.h"
using namespace std;

int main() {
        bool loop = true;
        while (loop)
        {
                string command;
                string s;
                bool cd = false;
                bool cdtraz = false;
                bool compilec = false;
                bool compilecpp = false;
                char dir[216];
                getcwd(dir, sizeof(dir));
                cout << dir << "> ";
                getline(cin, command);
                for (char l : command)
                {
                        if (compilecpp && l == '.')
                        {
                                break;
                        }
                        if (compilec && l == '.')
                        {
                                break;
                        }
                        s += l;
                        if (s == "cd " || s == "chdir ")
                        {
                                s = "";
                                cd = true;
                        }
                        else if (s == "cd..")
                        {
                                cdtraz = true;
                                break;
                        }
                        else if (s == "compilec++ ")
                        {
                                compilecpp = true;
                                s = "";
                        }
                        else if (s == "compilec ")
                        {
                                compilec = true;
                                s = "";
                        }
                        else if (s == "exit")
                        {
                                return 0;
                        }
                }
                if (cd)
                {
                        chdir(s.c_str());
                }
                else if (cdtraz)
                {
                        chdir("..");
                }
                else if (compilecpp)
                {
                        command = "g++ -o " + s + ".exe " + s + ".cpp";
                        system(command.c_str());
                }
                else if (compilec)
                {
                        command = "gcc -o " + s + ".exe " + s + ".c";
                        system(command.c_str());
                }
                else
                {
                        system(command.c_str());
                }
        }
        return 1;
}
