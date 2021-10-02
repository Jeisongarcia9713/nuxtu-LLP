#include "RSA.hpp"
#include "scanner.hpp"

using namespace std;
using namespace scanner;
using namespace rsa;

namespace rsa
{
    Encrypt::Encrypt() : n(221), e(5)
    {
    }

    Encrypt::Encrypt(long n, long e) : n(n), e(e)
    {
    }

    Encrypt::~Encrypt()
    {
    }
    void Encrypt::calcEncryption(string str2encode)
    {
        encodedData.clear();
        for (char &character : str2encode)
        {
            int ch2long = (int)character; // ascii representation of each character to convert the data to its respective value following the table of the test guidelines.

            long double c; // variable for the encryption related math, long double to reduce the possibility of overflow

            /*Checking that the data that is being encrypted has a representatión following the requeriments of the test*/
            if (ch2long >= rsa::ASCII_A && ch2long <= rsa::ASCII_Z)
            {
                c = ch2long - rsa::ASCII_A + 1; // convert the ascci value to its value in the table
            }
            else if (ch2long == rsa::ASCII_SPACE)
            {
                c = 27; //give the specific value to the space character, because is the only character that isn't possible to convert as other characters
            }
            else
            {
                cout << "Invalid data is triying to be encrypted" << endl;
                exit(0);
            }
            c = pow(c, e);
            c = std::fmod(c, n);
            encodedData.push_back((long)c);
        }
    }

    void Encrypt::calcEncryptionMap(string str2encode)
    {
        encodedData.clear();
        for (char &character : str2encode)
        {
            long double c;
            try
            {
                c = ENCRYPTION_MAP.at(character);
            }
            catch (exception &e)
            {
                cout << "Invalid data is triying to be encrypted" << endl;
                exit(0);
            }
            c = pow(c, e);
            c = std::fmod(c, n);
            encodedData.push_back((long)c);
        }
    }

    /*ostream Output stream objects can write sequences of characters and represent other kinds of data*/
    ostream &operator<<(ostream &os, const Encrypt &Encry)
    {
        if (!Encry.encodedData.empty())
        {
            for (long data : Encry.encodedData)
            {
                os << data << ",";
            }
            os << endl;
        }
        else
        {
            os << "There is no data encoded yet." << endl;
        }
        return os;
    }
}

int main()
{
    long e = Scanner::scanData<long>("e", "long");
    long n = Scanner::scanData<long>("n", "long");
    string str2encode = Scanner::scanData("String to encode");
    Encrypt encr(n, e);
    
    encr.calcEncryption(str2encode);

    cout << "******************************" << endl;
    cout << "The encrypted data is : ";
    cout << encr;
    cout << "******************************" << endl <<endl;

    encr.calcEncryptionMap(str2encode);
    cout << "******************************" << endl;
    cout << "The encrypted data with map representation is : ";
    cout << encr;
    cout << "******************************" << endl;
}