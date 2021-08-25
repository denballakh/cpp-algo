#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "x = (-inf, +inf)" << endl;
            } else {
                cout << "x = {}" << endl;
            }
        } else {
            double x = -c / b;
            cout << "x = " << x << endl;
        }
    } else {
        double d = b * b - 4 * a * c;

        if (d < 0) {
            cout << "x = {}" << endl;
        } else if (d == 0) {
            double x = -b / (2 * a);
            cout << "x = " << x << endl;
        } else {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            cout << "x = {" << x1 << ", " << x2 << "}" << endl;
        }
    }
}
