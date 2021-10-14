#include <iostream>
#include <map>
#include <string>

struct Command {
    int data;
};

struct CommandIdentifier
{
    std::string commandNamespace;
    std::string commandName;

    bool operator <(const CommandIdentifier& rhs) const
    {
        std::cout << "compare\n";
        return (commandNamespace + commandName).compare(rhs.commandNamespace + rhs.commandName) < 0;
    }
};

int main()
{
    std::map<CommandIdentifier, Command> commands;

    commands.insert(std::make_pair<CommandIdentifier, Command>({ "isaac", "spawn" }, { 2 }));
    commands.insert(std::make_pair<CommandIdentifier, Command>({ "isaac", "delete" }, { 4 }));
    commands.insert(std::make_pair<CommandIdentifier, Command>({ "hedron", "spawn" }, { 3 }));
    
    const Command& c = commands.at({ "isaac", "spawn" });
    std::cout << c.data << std::endl;

    return 0;
}
