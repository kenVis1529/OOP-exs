//BAI 1.a
#include <iostream>
using namespace std;

struct PHANSO{
    int t;
    int m;
};

void nhap(PHANSO &ps){
    cin >> ps.t >> ps.m;
}
int ucln(PHANSO ps){
    // t = 0, m = 0 -> 0
    // t = 1 -> giu nguyen
    // m =1 -> giu tu
    // t = m -> 1
    //int negative = 0;
    if (ps.t < 0){
        //negative = 1;
        ps.t = abs(ps.t);
    }
    if (ps.m < 0){
        //if (negative == 0) negative = 1;
        ps.m = abs(ps.m);
    }
    if ((ps.t == 0) || (ps.m == 0)) return 0;
    if (ps.t == ps.m) return -1;
    if (ps.t == 1) return 1;
    if (ps.m == 1) return -1;
    while ((ps.m != ps.t) && (ps.m != 0) && (ps.t != 0)) {
        if (ps.m > ps.t) ps.m %= ps.t;
        else ps.t %= ps.m;
    }
    if (ps.t != 0)
        return ps.t;
    else 
        return ps.m;
}
void psToigian(PHANSO &ps, int uc){
    if (uc == 0){
        ps.m = 0;
    }
    else if (uc > 0){
        ps.t = ps.t / uc;
        ps.m = ps.m / uc;
    }
    else {
        if (ps.t == ps.m){
            ps.t = 1;
            ps.m = 1;
        }
    }
}
void xuat(PHANSO ps){
    if (ps.m == 0){
        cout << 0;
    }
    else if (ps.m == 1){
        cout << ps.t;
    }
    else if (ps.t < 0 && ps.m < 0){
        cout << abs(ps.t) << "/" << abs(ps.m);
    }
    else if (ps.m < 0){
        cout << -ps.t << "/" << abs(ps.m);
    }
    else {
        cout << ps.t << "/" << ps.m;
    }
}
void bai1a(){
    PHANSO ps;
    int uc;
    //Nhap
    nhap(ps);
    //Rut gon
    uc = ucln(ps);
    psToigian(ps, uc);
    xuat(ps);
}
void greaterFraction (PHANSO ps1, PHANSO ps2, PHANSO &ps3){
    int tu1 = ps1.t * ps2.m;
    int tu2 = ps2.t * ps1.m;
    if (tu1 > tu2) {
        ps3 = ps1;
    } 
    else ps3 = ps2;
}
void bai1b(){
    PHANSO ps1, ps2, ps3;
    int uc1, uc2;
    //Nhap
    nhap(ps1);
    nhap(ps2);
    //Rut gon
    uc1 = ucln(ps1);
    uc2 = ucln(ps2); 
    psToigian(ps1, uc1);
    psToigian(ps2, uc2);
    //So sanh
    greaterFraction(ps1, ps2, ps3);
    //Xuat
    xuat(ps3);
}
PHANSO sum(PHANSO ps1, PHANSO ps2){
    PHANSO ps3;
    int uc3;
    ps3.t = ps1.t * ps2.m + ps2.t * ps1.m;
    ps3.m = ps1.m * ps2.m;
    uc3 = ucln(ps3);
    psToigian(ps3, uc3);
    return ps3;
}
PHANSO difference(PHANSO ps1, PHANSO ps2){
    PHANSO ps3;
    int uc3;
    ps3.t = ps1.t * ps2.m - ps2.t * ps1.m;
    ps3.m = ps1.m * ps2.m;
    uc3 = ucln(ps3);
    psToigian(ps3, uc3);
    return ps3;

}
PHANSO product(PHANSO ps1, PHANSO ps2){
    PHANSO ps3;
    int uc3;
    ps3.t = ps1.t * ps2.t;
    ps3.m = ps1.m * ps2.m;
    uc3 = ucln(ps3);
    psToigian(ps3, uc3);
    return ps3;
}
PHANSO fraction(PHANSO ps1, PHANSO ps2){
    PHANSO ps3;
    int uc3;
    ps3.t = ps1.t * ps2.m;
    ps3.m = ps1.m * ps2.t;
    uc3 = ucln(ps3);
    psToigian(ps3, uc3);
    return ps3;
}
void bai1c(){
    PHANSO ps1, ps2, tong, hieu, tich, thuong;
    //Nhap
    nhap(ps1);
    nhap(ps2);
    //Tong
    tong = sum(ps1, ps2);
    //Hieu
    hieu = difference(ps1, ps2);
    //Tich
    tich = product(ps1, ps2);
    //Thuong
    thuong = fraction(ps1, ps2);
    //Xuat tong, hieu, tich, thuong
    cout << "Tong: ";
    xuat(tong);
    cout << endl;
    cout << "Hieu: ";
    xuat(hieu);
    cout << endl;
    cout << "Tich: ";
    xuat(tich);
    cout << endl;
    cout << "Thuong: ";
    xuat(thuong); 
}
int main(){
    //bai1a();
    //bai1b();
    //bai1c();
    return 0;
}