#include <iostream>

using namespace std;

// xPlusY     x2y2
//(x + y)(x2 - xy + y2)
int solve(int xPlusY, int x2y2){
    int medium = xPlusY / 2;
    int result = 0;
    for (int x = 0; x < medium + 1; x++){
        int y = xPlusY - x;
        if(x * x - x * y + y * y){
            result += 2;
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    int counter = 0;
    for (int z = 0; z < n + 1; z++){
        int z3 = z * z * z;
        int delta = n - z3;
        if(delta == 0){
            counter++;
            continue;
        }
        float deltaSqrt = sqrt(delta);

        for (int xPlusY = 1; xPlusY < deltaSqrt + 1; xPlusY++){
            if(delta % xPlusY == 0){
                int x2y2 = delta / xPlusY;
                counter += solve(xPlusY, x2y2);
                if(xPlusY != x2y2){
                    counter += solve(x2y2, xPlusY);
                }
            }
        }
    }
    cout << counter;
}

// for (int xPlusY = 1; xPlusY < deltaSqrt + 1; xPlusY++){
//     if(delta % xPlusY == 0){
//         int x2y2 = delta / xPlusY;
//         int medium = floor(xPlusY / 2);
//         for (int x = 0; x < medium + 1; x++){
//             int y = xPlusY - x;
//             if(x * x - x * y + y * y == x2y2)
//                 counter += 2;
//         }

//         if(xPlusY != x2y2){
//             int swch = x2y2;
//             x2y2 = xPlusY;
//             xPlusY = swch;

//             medium = floor(xPlusY / 2);
//             for (int x = 0; x < medium + 1; x++){
//                 int y = xPlusY - x;
//                 if(x * x - x * y + y * y == x2y2)
//                     counter += 2;
//             }
//         }
//     }
// }