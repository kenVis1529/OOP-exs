//BAI 2
#include <iostream>
#include <math.h>
using namespace std;

struct POINT{
    float x = 0;
    float y = 0;
};

void coutPoints(int p1, int p2, int n, POINT points[]){
    cout << "All of points: \n";
    for (int i=0; i<n; i++){
        cout << points[i].x << " " << points[i].y << endl;
    }
    cout << "Two points with the longest distance: \n";
    cout << points[p1].x << " " << points[p1].y << endl;
    cout << points[p2].x << " " << points[p2].y << endl;
}

void setDiem(int n, POINT points[]){
    //ESTABLISH POINT LOCATIONS
    for (int i = 0; i<n; i++){
        switch (i%3)
        {
        case /* constant-expression */0:
            /* code */
            cout << "x and y of point " << i << " : ";
            cin >> points[i].x >> points[i].y;
            break;
        case 1:
            cout << "x of point " << i << " : ";
            cin >> points[i].x;
            break;
        case 2:
            cout << "y of point " << i << " : ";
            cin >> points[i].y;
            break;
        }
    }
    
    //FIND LONGEST DISTANCE BETWEEN 2 POINTS
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
    coutPoints(point1, point2, n, points);
}

int main(){
    int n, p1, p2;
    cin >> n;
    POINT points[n];
    setDiem(n, points);
    return 0;
}