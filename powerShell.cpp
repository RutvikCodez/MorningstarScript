#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;

void printWelcomeMessage()
{
    cout << "Simple Shell v1.0" << endl;
    cout << "Type 'exit' to exit the shell" << endl;
    cout << "Type 'color <bg_color> <fg_color>' to change the background and foreground color" << endl;
    cout << "Available colors: 0 = Black, 1 = Blue, 2 = Green, 3 = Aqua, 4 = Red, 5 = Purple, 6 = Yellow, 7 = White, 8 = Gray, 9 = Light Blue, A = Light Green, B = Light Aqua, C = Light Red, D = Light Purple, E = Light Yellow, F = Bright White" << endl;
}

vector<string> splitString(const string &str)
{
    istringstream iss(str);
    vector<string> tokens;
    string token;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}

void executeCommand(const string &command)
{
    int result = system(command.c_str());
    if (result == -1)
    {
        cerr << "Command execution failed." << endl;
    }
}

string autoCompleteCommand(const string &input, const vector<string> &commands)
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

void changeConsoleColor(const string &bgColor, const string &fgColor)
{
    string validColors = "0123456789ABCDEF";
    if (validColors.find(bgColor) == string::npos || validColors.find(fgColor) == string::npos)
    {
        cerr << "Invalid color code. Please use hex digits from 0 to F." << endl;
        return;
    }

    string colorCommand = "color " + bgColor + fgColor;
    executeCommand(colorCommand);
}

int main()
{
    printWelcomeMessage();

    vector<string> commonCommands = {
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

    string prompt = "$ ";

    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);
        if (input == "exit")
        {
            break;
        }

        vector<string> args = splitString(input);

        if (args.empty())
        {
            continue;
        }

        // Check if the user needs auto-completion
        string command = autoCompleteCommand(args[0], commonCommands);
        
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
    cout << "Bye!" << endl;
    return 0;
}