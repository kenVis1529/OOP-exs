#include <iostream>
#include <string>
using namespace std;

struct NHANVIEN
{
    char manhanvien[8];
    char hoten[20];
    char phongban[10];
    unsigned long long luong;
    unsigned long long thuong;
    unsigned long long thuclanh;
};
void nhap(int n, NHANVIEN kien[]){
    cout << endl;
    for (int i = 0; i<n; i++){
        cin.ignore();
        cin.getline(kien[i].manhanvien, 8);
        cin.getline(kien[i].hoten, 20);
        cin.getline(kien[i].phongban, 10);
        cin >> kien[i].luong;
        cin >> kien[i].thuong;
        kien[i].thuclanh = kien[i].luong + kien[i].thuong;
        cout << kien[i].thuclanh;
        cout << endl;
    }

}
int TongThucLanhThang(int n, NHANVIEN kien[]){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += kien[i].thuclanh;
    }
    return sum;
}
void InDanhSachLuongThapNhat(int n, NHANVIEN kien[]){
    int min = kien[0].luong;
    int *check = new int[n]{0};
    check[0] = 1;
    for (int i = 1; i < n; i++){
        if (kien[i].luong == min){
            check[i] = 1;
        }
        else if (kien[i].luong < min){
            min = kien[i].luong;
            //Thiết lập lại danh sách
            delete[] check;
            check = new int[n]{0};
            check[0] = 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (check[i] == 1){
            cout << kien[i].hoten << endl;
        }
    }
}
int DemThuong(int n, NHANVIEN kien[]){//Thưởng >= 1200000
    int amount = 0;
    for (int i = 0; i < n; i++){
        if (kien[i].thuong >= 1200000){
            ++amount;
        }
    }
    return amount;
}
void sapxepManhanvien(int vt1, int vt2, NHANVIEN kien[]){
    //Giam dan
    for (int i = vt1; i < vt2-1; i++){
        for (int j = i+1; j < vt2; j++){
            if (stoi(kien[i].manhanvien) < stoi(kien[j].manhanvien)){
                NHANVIEN temp;
                temp = kien[i];
                kien[i] = kien[j];
                kien[j] = temp;
            }
        }
    }
}
void sapxepBan(int n, NHANVIEN kien[]){
    //Tang dan
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (stoi(kien[i].phongban) >= stoi(kien[j].phongban)){
                NHANVIEN temp;
                temp = kien[i];
                kien[i] = kien[j];
                kien[j] = temp;
            }
        }
    }
}
void sapxep(int n, NHANVIEN kien[]){
    int vt1 = -1, vt2 = -1;
    sapxepBan(n, kien);
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (kien[i].phongban == kien[j].phongban){
                if (vt1 == -1){
                    vt1 = i;      
                }
                vt2 = j;
            }
            else {
                if (vt1 != -1){
                    sapxepManhanvien(vt1, vt2, kien);
                }
                vt1 = -1;
                vt2 = -1;
            }
        }
    }
}
void InDanhSachNhanVien(int n, NHANVIEN kien[]){
    sapxep(n, kien);
    cout << "Tên\tPhòng Ban\tMã nhân viên\n";
    for (int i = 0; i < n; i++){
        cout << kien[i].hoten << "\t" << kien[i].phongban << "\t" << kien[i].manhanvien << endl;
    }
}
int main(){
    int sonhanvien, tongthuclanh;
    cin >> sonhanvien;
    NHANVIEN kien[sonhanvien];
    //Nhap
    nhap(sonhanvien, kien);

    //3A
    cout << "Tổng thực lãnh tháng của tất cả nhân viên trong công ty: ";
    cout << TongThucLanhThang(sonhanvien, kien) << endl;

    //3B
    cout << "Danh sách nhân viên có mức lương cơ bản thấp nhất: \n";
    InDanhSachLuongThapNhat(sonhanvien, kien);

    //3C
    cout << "Số lượng nhân viên có mức thưởng >= 1200000: \n";
    cout << DemThuong(sonhanvien, kien) << endl;
    
    //3D
    cout << "Danh sách các nhân viên: \n";
    InDanhSachNhanVien(sonhanvien, kien);
    return 0;
}