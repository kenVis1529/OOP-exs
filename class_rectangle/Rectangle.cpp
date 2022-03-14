#include "Rectangle.h"
int Rectangle::tong = 0;
void Rectangle::Nhap()
{
    cin >> chieuDai;
    cin >> chieuRong;
}
int Rectangle::TinhDienTich()
{
    return chieuDai*chieuRong;
}
void Rectangle::display()
{
    int s = TinhDienTich();
    tong += s;
    cout << "Chiều dài: " << chieuDai << endl;
    cout << "Chiều rộng: " << chieuRong << endl;
    cout << "Diện tích: " << s << endl;
}
int Rectangle::getChieuDai()
{
    return chieuDai;
}
void Rectangle::setChieuDai(int dai)
{
    chieuDai = dai;
}