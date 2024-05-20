#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

void printWelcomeMessage()
{
    std::cout << "Simple Shell v1.0" << std::endl;
    std::cout << "Type 'exit' to exit the shell" << std::endl;
}

std::vector<std::string> splitString(const std::string &str)
{
    std::istringstream iss(str);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}

void executeCommand(const std::string &command)
{
    int result = std::system(command.c_str());
    if (result == -1)
    {
        std::cerr << "Command execution failed." << std::endl;
    }
}

std::string autoCompleteCommand(const std::string &input, const std::vector<std::string> &commands)
{
   for(const auto &cmd : commands) {
     if (cmd.find(input) == 0) {
       return cmd;
     }
   }
   return input;
}


int main()
{
    printWelcomeMessage();

    std::vector<std::string> commanCommands = {
        "ls",
        "cd",
        "pwd",
        "mkdir",
        "rmdir",
        "rm",
        "cp",
        "mv",
        "cat",
        "touch",
        "chmod",
        "chown",
        "chmod",
        "chgrp",
        "ln",
        "find",
        "grep",
        "ps",
    };

    std::string prompt = "$ ";

    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input == "exit")
        {
            break;
        }

        std::vector<std::string> args = splitString(input);

        if (args.empty())
        {
            continue;
        }
        std::string command;
        for (const auto &arg : args)
        {
            command += arg + " ";
        }
        executeCommand(command);
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
