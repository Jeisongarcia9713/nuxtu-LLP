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
        for (char &character : str2encode)
        {
            int ch2long = (int)character;
            long double c;
            if (ch2long >= rsa::ASCII_A && ch2long <= rsa::ASCII_Z)
            {
                c = ch2long - rsa::ASCII_A + 1;
            }
            else if (ch2long == rsa::ASCII_SPACE)
            {
                c = 27;
            }
            else
            {
                cout << "Invalid data is triying to be encrypted" << endl;
                exit(0);
            }
            c = pow(c, e); 
            c = std::fmod(c,n);
            encodedData.push_back((long)c);
        }
    }

    ostream& operator<<(ostream &os, const Encrypt &Encry)
    {
        for (long data : Encry.encodedData)
        {
            os << data << ",";
        }
        os << endl;
        return os;
    }
}

int main()
{

    long e=Scanner::scanData<long>("e", "long");
    long n=Scanner::scanData<long>("n", "long");
    string str2encode=Scanner::scanData("String to encode");
    Encrypt encr(n,e);
    encr.calcEncryption(str2encode);
    cout<<encr;
}