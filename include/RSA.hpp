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

        /**
         *  @brief specific method to encrypt the data 
         *  @param str2encode string to be encrypted
         *  @return this function has no return but save the values of every character encrypted in the vector encodeData
         * */
        void calcEncryption(string str2encode);

        /**
         *  @brief overload the operator << to give the objects of the class the posibbility to display in the terminal the vectorencoded
         * */
        friend ostream& operator<<(ostream& os, const Encrypt& dt);
    };
}