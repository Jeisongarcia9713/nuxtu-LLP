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
    const map<char, int> ENCRYPTION_MAP={{'A', 1},
                                             {'B', 2},
                                             {'C', 3},
                                             {'D', 4},
                                             {'E', 5},
                                             {'F', 6},
                                             {'G', 7},
                                             {'H', 8},
                                             {'I', 9},
                                             {'J', 10},
                                             {'K', 11},
                                             {'L', 12},
                                             {'M', 13},
                                             {'N', 14},
                                             {'O', 15},
                                             {'P', 16},
                                             {'Q', 17},
                                             {'R', 18},
                                             {'S', 19},
                                             {'T', 20},
                                             {'U', 21},
                                             {'V', 22},
                                             {'W', 23},
                                             {'X', 24},
                                             {'Y', 25},
                                             {'Z', 26},
                                             {' ', 27},};
                                             
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
         *  @brief specific method to encrypt the data but using a map to  get the representation of every character
         *  @param str2encode string to be encrypted
         *  @return this function has no return but save the values of every character encrypted in the vector encodeData
         * */
        void calcEncryptionMap(string str2encode);

        /**
         *  @brief overload the operator << to give the objects of the class the posibbility to display in the terminal the vectorencoded
         * */
        friend ostream& operator<<(ostream& os, const Encrypt& dt);

        /**
         *  @brief getter of attribute n
         * */
        long getN();

        /**
         *  @brief getter of attribute e
         * */
        long getE();

        /**
         *  @brief getter of attribute encodedData
         * */
        vector<long > getEncodedData();

        /**
         *  @brief setter of attribute n
         * */
        void setN(long n);

        /**
         *  @brief getter of attribute e
         * */
        void setE(long e);
    };
}