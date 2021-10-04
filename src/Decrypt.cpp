#include "scanner.hpp"
#include "RSA.hpp"
using namespace std;
using namespace scanner;
using namespace rsa;

namespace rsa
{

    Decrypt::Decrypt() : n(221), d(77) //default values to test impementation
    {
    }

    Decrypt::Decrypt(long n, long d) : n(n), d(d)
    {
    }

    Decrypt::~Decrypt()
    {
    }

    void Decrypt::calcDecryption(vector<long> str2decode)
    {
        decryptedData.clear();
        for (long &character : str2decode)
        {

            long c = modpow(character, d, n);
            /*Checking that the data that was decrypted has a representatión following the requeriments of the test*/
            if (c >= rsa::ENCR_A && c <= rsa::ENCR_Z)
            {
                c = c + rsa::ASCII_A - 1; // convert to ascci value
            }
            else if (c == rsa::ENCR_SPACE)
            {
                c = ' '; //give the specific value to the space character, because is the only character that isn't possible to convert as other characters
            }
            else
            {
                cout << "Invalid data is triying to be decrypted with value:" << c << endl;
                exit(0);
            }
            decryptedData += (char)c;
        }
    }

    void Decrypt::calcDecryptionMap(vector<long> str2decode)
    {
        decryptedData.clear();
        for (long &character : str2decode)
        {
            long c = modpow(character, d, n);
            try
            {
                c = DECRYPTION_MAP.at(c);
                decryptedData += (char)c;
            }
            catch (exception &e)
            {
                /*Exception out of range indicates that there is no value for the entered key*/
                cout << "Invalid data is triying to be decrypted with value:" << c << endl;
                exit(0);
            }
        }
    }

    bool Decrypt::checkD_NData()
    {
        int errors = 0;
        if (d < 1)
        {
            cout << "d must greater than 0" << endl;
            errors++;
        }
        if (n < 221)
        {
            cout << "n must be greater or equal to 221 " << endl; //this having in consideration the guideline where P>=13 and Q>=17
            errors++;
        }
        else
        {
            long p = found_first_factor(n);
            long q = n / p;
            if (p != q && (!is_prime(p) || !is_prime(q,p)))
            {
                cout << "n is no the product of two prime numbers" << endl;
                errors++;
            }
        }
        if (errors)
            return false;
        return true;
    }

    /*ostream Output stream objects can write sequences of characters and represent other kinds of data*/
    ostream &operator<<(ostream &os, const Decrypt &Encry)
    {
        if (!Encry.decryptedData.empty())
        {

            os << Encry.decryptedData << endl;
        }
        else
        {
            os << "There is no data decrypted yet." << endl;
        }
        return os;
    }

    long Decrypt::getN()
    {
        return n;
    }

    long Decrypt::getD()
    {
        return d;
    }

    string Decrypt::getDecryptedData()
    {
        return decryptedData;
    }

    void Decrypt::setN(long n)
    {
        this->n = n;
    }

    void Decrypt::setD(long d)
    {
        this->d = d;
    }
}

int main()
{

    long d = Scanner::scanData<long>("d", "long");
    long n = Scanner::scanData<long>("n", "long");
    Decrypt decr(n, d);
    if (!decr.checkD_NData())
        exit(0);

    bool error = false;
    vector<long> str2decode;
    do
    {
        try
        {
            str2decode = Scanner::splitData(Scanner::scanData("Encrypted"));
            error = false;
        }
        catch (std::exception &e)
        {
            cout << "invalid data must enter just numbers separate each them by commas" << endl;
            error = true;
        }
    } while (error);

    decr.calcDecryption(str2decode);
    cout << "******************************" << endl;
    cout << "The decrypted data is : ";
    cout << decr;
    cout << "******************************" << endl
         << endl;

    decr.calcDecryptionMap(str2decode);
    cout << "******************************" << endl;
    cout << "The decrypted data using the map representation is : ";
    cout << decr;
    cout << "******************************" << endl;
}