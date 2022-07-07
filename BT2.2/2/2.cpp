#include <iostream>

using namespace std;

struct DATE{
    int day;
    int month;
    int year;
};
struct HOCSINH
{
    char hoten[30];
    float toan;
    float van;
};

void nhapDATE(DATE &ngay){
    cin >> ngay.day >> ngay.month >> ngay.year;
}
void xuatDATE(DATE ngay){
    cout << "Ngay/thang/nam: ";
    cout << ngay.day << "/" << ngay.month << "/" << ngay.year;
}
DATE FindNextDay(DATE ngay){
    // Ngay = 29/2 or 30/(4,6,9,11) or 31/(1,3,5,7,8,10,12),
    switch (ngay.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (ngay.day == 31){
            if (ngay.month == 12){
                ++ngay.year;
                ngay.day = 1;
                ngay.month = 1;
            }
            else {
                ++ngay.month;
                ngay.day = 1;
            }
        }
        else ++ngay.day;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (ngay.day == 30){
                ++ngay.month;
                ngay.day = 1;
        }
        else ++ngay.day;
        break;
    case 2:
        if (ngay.year % 4 == 0){
        //Nam nhuan
            if (ngay.day == 29){
                ++ngay.month;
                ngay.day = 1;
            }
            else ++ngay.day;
        }
        else {
        //Nam khong nhuan
            if (ngay.day == 28){
                ++ngay.month;
                ngay.day = 1;
            }
            else ++ngay.day;
        } 
        break;
    }
    return ngay;
}
void bai2a(){
    DATE today, tomorrow;
    nhapDATE(today);
    tomorrow = FindNextDay(today);
    cout << "Ngày mai: \n";
    xuatDATE(tomorrow);
}
void nhapHOCSINH(HOCSINH &kien){
    cin.getline(kien.hoten, 30);
    cin >> kien.toan >> kien.van;
}
float diemTB(HOCSINH kien){
    return (kien.toan + kien.van) / 2;
}
void xuatKetQua(HOCSINH kien){
    cout << "Điểm trung bình của em " << kien.hoten << " : ";
    cout << diemTB(kien);
}
void bai2b(){
    HOCSINH kien;
    nhapHOCSINH(kien);
    xuatKetQua(kien);
}
int main(){
    //bai2a();
    //bai2b();
    return 0;
}