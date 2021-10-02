#include "scanner.hpp"
using namespace std;
using namespace scanner;


namespace rsa{

}

int main(){
    Scanner scanner;
    vector<int> array;
    bool error=false;
    scanner.scanData<bool>("bool","bool");
    scanner.scanData<int>("int","int");
    scanner.scanData<float>("float","float");
    scanner.scanData("string");
    do{
        try{
            array= scanner.splitData(scanner.scanData("array int"));
            error=false;
        }catch(std::exception& e){
            cout<<"invalid data must enter just numbers separate each them by commas"<<endl;
            error=true;
        }
    }while(error);
    

}