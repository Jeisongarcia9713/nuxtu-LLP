#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

namespace rsa
{
    constexpr int ASCII_A='A';
    constexpr int ASCII_Z='Z';
    constexpr int ASCII_SPACE= 32;
    
    class Decrypt
    {
    private:
        
    public:
        Decrypt();
        ~Decrypt();
    };

    class Encrypt
    {
    private:
        long  n;
        long  e;
        vector<long > encodedData;
    public:
        Encrypt();
        Encrypt(long  n, long  e);
        ~Encrypt();

        void calcEncryption(string str2encode);
        friend ostream& operator<<(ostream& os, const Encrypt& dt);
    };
}