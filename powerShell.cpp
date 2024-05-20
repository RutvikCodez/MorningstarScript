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
    std::cout << "Type 'color <bg_color> <fg_color>' to change the background and foreground color" << std::endl;
    std::cout << "Available colors: 0 = Black, 1 = Blue, 2 = Green, 3 = Aqua, 4 = Red, 5 = Purple, 6 = Yellow, 7 = White, 8 = Gray, 9 = Light Blue, A = Light Green, B = Light Aqua, C = Light Red, D = Light Purple, E = Light Yellow, F = Bright White" << std::endl;
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
    for (const auto &cmd : commands)
    {
        if (cmd.find(input) == 0)
        {
            return cmd;
        }
    }
    return input;
}

void changeConsoleColor(const std::string &bgColor, const std::string &fgColor)
{
    std::string validColors = "0123456789ABCDEF";
    if (validColors.find(bgColor) == std::string::npos || validColors.find(fgColor) == std::string::npos)
    {
        std::cerr << "Invalid color code. Please use hex digits from 0 to F." << std::endl;
        return;
    }

    std::string colorCommand = "color " + bgColor + fgColor;
    executeCommand(colorCommand);
}

int main()
{
    printWelcomeMessage();

    std::vector<std::string> commonCommands = {
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

        // Check if the user needs auto-completion
        std::string command = autoCompleteCommand(args[0], commonCommands);
        
        // If the command is "color", handle it separately
        if (command == "color" && args.size() == 3)
        {
            changeConsoleColor(args[1], args[2]);
            continue;
        }

        // Reconstruct the command with possible auto-completion
        for (size_t i = 1; i < args.size(); ++i)
        {
            command += " " + args[i];
        }

        executeCommand(command);
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
