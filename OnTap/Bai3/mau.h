#include <iostream>

using namespace std;

class Mau
{
private:
    string nhomMau;
    string* nhomCho;
    string* nhomNhan;
public:
    Mau(){};
    Mau(string, string*, string*);
    ~Mau();
    string getNhomMau();
    string getNhomCho();
    string getNhomNhan();
};

Mau::Mau(string mau, string* cho, string* nhan)
{
    nhomMau = mau;
    nhomCho = cho;
    nhomNhan = nhan;
}

Mau::~Mau()
{
    delete[] nhomCho;
    delete[] nhomNhan;
}
