// Problem : spoj MMASS
// Link : https://www.spoj.com/problems/MMASS/

/*
A molecule can be defined as a sequence of atoms and represented 
by a chemical formula consisting of letters denoting these atoms. 
E.g. letter H denotes atom of hydrogen, C denotes atom of carbon, 
O denotes atom of oxygen, formula COOH represents molecule consisting 
of one atom of carbon, two atoms of oxygen and one atom of hydrogen.

To write some formulas efficiently, we use the following rules. 
Letters denoting some atoms can be grouped by enclosing in 
parentheses, e.g. formula CH(OH) contains group OH. 
Groups can be nested – a group can also contain other groups. 
To simplify a formula, consecutive occurrences of the same letter 
can be replaced with that letter followed by a number of these 
occurrences. E.g. formula COOHHH can be written as CO2H3 and it 
represents a molecule consisting of one atom of carbon, 
two atoms of oxygen and three atoms of hydrogen. Furthermore, 
consecutive occurrences of the same group can be replaced with that 
group followed by a number of these occurrences. E.g. formula 
CH (CO2H) (CO2H) (CO2H) can be written as CH(CO2H)3 and molecule 
represented by both those formulas consists of four atoms of carbon, 
four atoms of hydrogen and six atoms of oxygen. A number written 
after a letter or a group is always greater than or equal to 2 and 
less than or equal to 9. A mass of a molecule is a sum of masses of 
all its atoms. One atom of hydrogen has mass 1, one atom of carbon 
has mass 12 and one atom of oxygen has mass 16.

Write a program that will calculate a mass of a molecule.

Input
The first and only line of input file contains a formula of a molecule 
whose mass needs to be determined. A formula of a molecule will consist 
of characters H, C, O, (, ) , 2, 3, ..., 9 only. Its length will be 
less or equal to 100 characters.

Output
The first and only line of output file should contain a mass of a 
molecule represented with a given formula. The result will always 
be less than or equal to 10,000.

Sample Input 
COOH

Sample Output 
45
 
Sample Input 
CH(CO2H)3

Sample Output 
148
 
Sample Input 
((CH)2(OH2H)(C(H))O)3

Sample Output 
222

*/

#include <iostream>
#include <stack>
using namespace std;

bool isCHO(char c) {
    if (c == 'C' or c == 'H' or c == 'O')
        return true;
    else
        return false;
}

bool isDigit(char c) {
    if (c >= '1' and c <= '9')
        return true;
    else
        return false;
}

int getWeight(char c) {
    if (c == 'C')
        return 12;
    else if (c == 'H')
        return 1;
    else if (c == 'O')
        return 16;
    else
        return 0;
}

int getDigit(char c) {
    return c - '0';
}

int main() {

    // input expression
    string exp;
    cin >> exp;

    stack<int> stk;

    // use -10101 to denote (

    for (int i = 0 ; i < exp.length(); i++) {
        if (exp[i] == '(')
            stk.push(-10101);

        else if (exp[i] == ')') {
            int accum = 0;

            while (stk.top() != -10101) {
                accum += stk.top();
                stk.pop();
            }

            stk.pop();
            stk.push(accum);
        }

        else if (isCHO(exp[i])) {
            stk.push(getWeight(exp[i]));
        }

        else if (isDigit(exp[i])) {
            int x = stk.top(); stk.pop();
            x = x * getDigit(exp[i]);
            stk.push(x);
        }
    }

    int ans = 0;

    while (stk.empty() == false) {
        ans += stk.top();
        stk.pop();
    }

    cout << ans << "\n";

    return 0;
}
