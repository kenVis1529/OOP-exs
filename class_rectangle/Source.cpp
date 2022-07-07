#include "Rectangle.cpp"
template <typename T>
int main(){
    Rectangle hcn[100];
    int n, tong;
    cout << "Nhập n: ";
    cin >> n;
    tong = 0;
    for (int i = 0; i < n; i++)
    {
        hcn[i].Nhap();
        hcn[i].display();
    }
    cout << "Tổng diện tích: " << Rectangle::tong;
}