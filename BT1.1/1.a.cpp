//BAI 1.a
#include <iostream>
#define MAX 10000
using namespace std;

void ascending(int &a, int &b){
    if (a > b){
        int t = a;
        a = b;
        b = t;
    }

}

int main() {
    int a[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < i; j++){
            ascending(a[j], a[i]);
        }
    }
    
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}

