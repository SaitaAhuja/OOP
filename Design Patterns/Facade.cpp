#include <iostream>
using namespace std;

class CPU
{
public:
    void start()
    {
        cout << "CPU Started\n";
    }
};

class Memory
{
public:
    void load()
    {
        cout << "Memory Loaded\n";
    }
};

class HardDrive
{
public:
    void read()
    {
        cout << "Hard Drive Reading\n";
    }
};

// Facade Class
class Computer
{
private:
    CPU cpu;
    Memory memory;
    HardDrive hd;

public:
    void startComputer()
    {
        cpu.start();
        memory.load();
        hd.read();

        cout << "Computer Ready\n";
    }
};

int main()
{
    Computer pc;
    pc.startComputer();

    return 0;
}
