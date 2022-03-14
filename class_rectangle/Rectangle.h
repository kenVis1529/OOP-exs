#include <iostream>
using namespace std;

class Rectangle
{
private:
    int chieuDai;
    int chieuRong;
public:
    static int tong;
    void Nhap();
    int TinhDienTich();
    void display();
    int getChieuDai();
    void setChieuDai(int);
};
