#include <conio.h>
#include <iostream>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::cin;
using namespace std;


void print_nibble(uint8_t nibble)
{
    char c;
    if (0 <= nibble && nibble <= 9)
    {
        c = '0' + nibble;
        cout << c;
    }
    else if (nibble <= 15)
    {
        c = 'A' + (nibble - 10);
        cout << c;
    }
    else cout<< "error";
}
void print_in_hex(uint8_t byte)
{

    print_nibble(byte >> 4);
    print_nibble(byte & 0x0F);

    cout << ' ';
}
void print_in_hex(const void* data, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if (i!=0 && i%16==0)
        cout<<"\n";
        print_in_hex(((uint8_t*) data)[i]);
    }

}


void print_bit(uint8_t bit)
{
    char c;
    if (bit == 0)
    {
        c = '0';
        cout << c;
    }
    else if (bit == 1)
    {
        c = '1';
        cout << c;
    }
    else cout<< "error";
}
void print_in_binary(uint8_t byte)
{
    for (int i=7; i>=0; i--)
    print_bit((byte>> i)&0x01);
    cout << ' ';
}
void print_in_binary(const void* data, size_t size)
{

    for (int i = 0; i < size; i++)
    {
        if (i!=0 && i%4==0)
        cout<<"\n";
        print_in_binary(((uint8_t*) data)[i]);

    }

}

int main()
{

    int number;

    while (cout<<"Enter number :",cin>>number)
     {
        cout<<"Number in hexadecimal system : ";
        print_in_hex(& number, sizeof(number));
        cout<<"\n";
        cout<<"Number in binary system: ";
        print_in_binary(& number, sizeof(number));
        cout<<"\n";
   }
}

