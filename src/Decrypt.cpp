#include "scanner.hpp"
using namespace std;
using namespace scanner;


namespace rsa{

}

int main(){
    vector<int> array;
    bool error=false;
    Scanner::scanData<bool>("bool","bool");
    Scanner::scanData<int>("int","int");
    Scanner::scanData<float>("float","float");
    Scanner::scanData("string");
    do{
        try{
            array= Scanner::splitData(Scanner::scanData("array int"));
            error=false;
        }catch(std::exception& e){
            cout<<"invalid data must enter just numbers separate each them by commas"<<endl;
            error=true;
        }
    }while(error);
    

}