//BAI 1.b
#include <iostream>
#include <math.h>
using namespace std;

struct POINT{
    float x;
    float y;
};

void cout2points(int p1, int p2,POINT points[]){
    cout << "Point 1: ";
    cout << points[p1].x << " " << points[p1].y << endl;
    cout << "Point 2: ";
    cout << points[p2].x << " " << points[p2].y << endl;
}

void maxGapPoints(int n, POINT points[]){
    int point1, point2;
    float gap, maxGap = -999999;
    //Compare each points with the others
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            //Distance betwen 2 points
            gap = sqrt(pow(points[i].x-points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            //Find the longest distance.
            if (gap > maxGap){
                maxGap = gap; 
                point1 = i;
                point2 = j;
            };
        }
    }
    cout2points(point1, point2, points);
}

int main(){
    int n, p1, p2;
    cin >> n;
    POINT points[n];
    for (int i = 0; i < n; i++){
        cin >> points[i].x;
        cin >> points[i].y;
    };
    maxGapPoints(n, points);
    return 0;
}