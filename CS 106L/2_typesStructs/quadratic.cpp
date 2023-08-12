#include <string>
#include <iostream>
#include <cmath> //gives us pow and sqrt!

using std::string; using std::cout;
using std::cin; using std::pow;
using std::sqrt; using std::endl;

//want: a function named quadratic that will take in 3 doubles and return
//a combination of: does a solution exist, and if so, what is it?
	//get radical, test if negative, return indicating no roots
	// radical = b^2 - 4ac
	
	//otherwise get roots and return
	// root1 = (-b + sqrt(radical)) divided by 2a
    // root2 = (-b - sqrt(radical)) divided by 2a
std::pair<bool, std::pair<double, double> > quadratic(double a, double b, double c) {
    double radical = pow(b, 2) - (4 * a * c);

    if (radical < 0) {
        return std::make_pair(false, std::make_pair(0, 0));
    } else {
        double root_1 = (-1 * b + sqrt(radical)) / (2 * a);
        double root_2 = (-1 * b - sqrt(radical)) / (2 * a);
        return std::make_pair(true, std::make_pair(root_1, root_2));
    }
}

int main(){
    //get 3 doubles (ax^2 + bx + c)
    double a, b, c;
    cout << "Input coefficients" << endl;
    cin >> a >> b >> c;
    auto result = quadratic(a, b, c);
    if (result.first) {
        cout << "The root 1 is " << result.second.first << " and the root 2 is " << result.second.second << "." << endl;
    } else {
        cout << "No real root." << endl;
    }

    return 0;
}




// Test: x^2 + 5x + 6 = 0, roots = -3, -2

// To run: first compile code --> make quadratic, 
// then run the compiled code --> ./quadratic