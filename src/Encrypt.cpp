#include "RSA.hpp"
#include "scanner.hpp"

using namespace std;
using namespace scanner;
using namespace rsa;

namespace rsa
{
    Encrypt::Encrypt() : n(221), e(5) //default values to test impementation
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
            uint64_t c; // variable for the encryption related math, long double to reduce the possibility of overflow
            try
            {
                c = ENCRYPTION_MAP.at(character);
            }
            catch (exception &e)
            {
                /*Exception out of range indicates that there is no value for the entered key*/
                cout << "Invalid data is triying to be encrypted" << endl;
                exit(0);
            }
            c = modpow(c, (uint64_t)e, (uint64_t)n);
            encodedData.push_back((long)c);
        }
    }

    bool Encrypt::checkE_NData()
    {
        int errors = 0;
        long p;
        long q;
        long phi = 0;
        if (n < 221)
        {
            cout << "n must be greater or equal to 221 " << endl; //this having in consideration the guideline where P>=13 and Q>=17
            errors++;
        }
        else
        {
            p = found_first_factor(n);
            q = n / p;
            if (p != q && (!is_prime(p) || !is_prime(q, p)))
            {
                cout << "n is no the product of two prime numbers" << endl;
                errors++;
            }
            else
            {
                phi = (p - 1) * (q - 1);
            }
        }
        if (e < 2)
        {
            cout << "e must be greater than 1 " << endl;
            errors++;
        }
        else
        {
            if (phi)
            {
                if (phi % e == 0)
                {
                    cout << "phi is divisible by e" << endl;
                    errors++;
                }
                if (e>=phi){
                    cout << "e must be less than phi" << endl;
                    errors++;
                }
            }
        }

        if (errors)
            return false;
        return true;
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

    long Encrypt::getN()
    {
        return n;
    }

    long Encrypt::getE()
    {
        return e;
    }

    vector<long> Encrypt::getEncodedData()
    {
        return encodedData;
    }

    void Encrypt::setN(long n)
    {
        this->n = n;
    }

    void Encrypt::setE(long e)
    {
        this->e = e;
    }

}

int main()
{
    long e = Scanner::scanData<long>("e", "long");
    long n = Scanner::scanData<long>("n", "long");
    Encrypt encr(n, e);
    if (!encr.checkE_NData())
        exit(0);

    string str2encode = Scanner::scanData("String to encode");

    encr.calcEncryption(str2encode);
    cout << "******************************" << endl;
    cout << "The encrypted data is : ";
    cout << encr;
    cout << "******************************" << endl
         << endl;

    encr.calcEncryptionMap(str2encode);
    cout << "******************************" << endl;
    cout << "The encrypted data using the map representation is : ";
    cout << encr;
    cout << "******************************" << endl;
}