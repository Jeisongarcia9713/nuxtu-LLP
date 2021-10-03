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
    constexpr int ASCII_SPACE= ' ';
    constexpr int ENCR_A=1;
    constexpr int ENCR_Z=26;
    constexpr int ENCR_SPACE= 27;
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
                                             {' ', 27}};
    
    const map<char, int> DECRYPTION_MAP={{1,'A'},
                                             {2,'B'},
                                             {3,'C'},
                                             {4,'D'},
                                             {5,'E'},
                                             {6,'F'},
                                             {7,'G'},
                                             {8,'H'},
                                             {9,'I'},
                                             {10,'J'},
                                             {11,'K'},
                                             {12,'L'},
                                             {13,'M'},
                                             {14,'N'},
                                             {15,'O'},
                                             {16,'P'},
                                             {17,'Q'},
                                             {18,'R'},
                                             {19,'S'},
                                             {20,'T'},
                                             {21,'U'},
                                             {22,'V'},
                                             {23,'W'},
                                             {24,'X'},
                                             {25,'Y'},
                                             {26,'Z'},
                                             {27,' '}};

    class Decrypt
    {
    private:
        long  n; 
        long  d;
        string decryptedData;
    public:
        Decrypt();
        Decrypt(long n, long d);
        ~Decrypt();
        
        /**
         *  @brief specific method to decrypt the data 
         *  @param str2encode string to be decrypted
         *  @return this function has no return but save the values of characters decrypted in the string decryptedData
         * */
        void calcDecryption(vector<long> str2decode);

        /**
         *  @brief specific method to decrypt the data but using a map to  get the representation of every character
         *  @param str2decode string to be decrypted
         *  @return this function has no return but save the values of characters decrypted in the string decryptedData
         * */
        void calcDecryptionMap(vector<long> str2decode);

        bool checkD_NData();

        /**
         *  @brief overload the operator << to give the objects of the class the posibbility to display in the terminal the decryptedData
         * */
        friend ostream& operator<<(ostream& os, const Decrypt& dt);

        /**
         *  @brief getter of attribute n
         * */
        long getN();

        /**
         *  @brief getter of attribute d
         * */
        long getD();

        /**
         *  @brief getter of attribute encryptedData
         * */
        string getDecryptedData();

        /**
         *  @brief setter of attribute n
         * */
        void setN(long n);

        /**
         *  @brief getter of attribute d
         * */
        void setD(long d);
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

        bool checkE_NData();

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