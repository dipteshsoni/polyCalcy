// including header files
#include <bits/stdc++.h>
#include <string>
using namespace std;

// Creating mapping to number and string in a map (Globally )
map<int, string> choices;

// Mapping the number and string in a map using a function
map<int, string> functionToFillMap()
{

    choices.insert({1, "BasicCalculation"});
    choices.insert({2, "HCF"});
    choices.insert({3, "LCM "});
    choices.insert({4, "Determinant"});
    choices.insert({5, "LinearEquation"});
    choices.insert({6, "QuadraticEquation"});
    choices.insert({7, "PowerCalculation"});
    choices.insert({8, "Factorial"});
    choices.insert({9, "DistanceBetweenTwoPoints"});
    choices.insert({10, "BinarytoDecimalConversion"});
    choices.insert({11, "DecimaltoBinaryConversion"});
    choices.insert({12, "DecimaltoHexadecimalConversion"});
    choices.insert({13, "SumofArithmeticProgressionSeries"});
    choices.insert({14, "SumofGeometricProgressionSeries"});
    choices.insert({15, "Prime Number List"});
    choices.insert({16, "Prime Factors "});
    choices.insert({17, "MultiplicationTableCreation"});
    choices.insert({18, "Mean"});
    choices.insert({19, "Median"});
    choices.insert({20, "Mode"});
    return choices;
}

// This will show choices to user
void showCompulsorilyToUser()
{
    cout << "\nWelcome.. User" << endl;
    cout << "Here we are, to help you in solving your complex calculation easily. " << endl;
    cout << endl;

    cout << "We do " << endl;
    cout << " 1. Basic Calculation \t 2. HCF \t 3. LCM \t 4. Determinant \t 5. Linear Equation \n\n 6. Quadratic Equation \t 7. Power Calculation \t 8. Factorial \t 9. Distance Between Two Points \n\n 10. Binary to Decimal Conversion \t 11. Decimal to Binary Conversion \t 12. Decimal to Hexadecimal Conversion \n 13. Sum of Arithmetic Progression Series \t 14. Sum of Geometric Progression Series \t 15. Prime Number List \t 16. Prime Factorisation \t 17. Multiplication Table Creation \n\n 18. Mean \t 19. Median \t 20. Mode \n\n";
}

// Ask for choices from the user
void askUsersChoice()
{
    cout << "\n----/-/---------/---/-------/------/------/-----------/----------/----------------/---------------/-------\n";
    cout << "\nNote :: When entering numbers in a list , enter them with just space separated not comma or anything else. Thankyou" << endl;
    cout << "Enter '0' to exit \t\n";
    cout << "Enter the digit corresponding to your desired operation ";
}

// Factorial Class
class factorial
{

public:
    int n;
    int result = 1;

    // Calculating Factorial
    void calculateFactorial()
    {
        if (n < 0)
            result = -1;
        if (n == 0 || n == 1)
            result = 1;
        else
        {
            for (int i = 1; i < n + 1; i++)
            {
                result = result * i;
            }
        }
    }

    // function to display Output
    void displayResult()
    {
        cout << "Factorial of " << n << " is " << result << endl;
    }

    // getting number from the user
    void getNumber()
    {
        try
        {
            cout << "\nEnter no ";
            cin >> n;
            if (n > 12)
                throw(n);
            calculateFactorial(); // calling inside getnumber
            displayResult();
        }
        catch (int n)
        {
            cout << "\nSorry !! This calculator supports till  12! \n ";
        }
    }
};

// Power Calculation
class powerCalculation
{

public:
    float n;
    int x;
    double result;

    void getNumber()
    {
        cout << "\nEnter in sequence 'base' 'exponent' : " << endl;
        cin >> n >> x;
    }
    // using Recursion
    void calculatePower()
    {
        if (x == 0)
        {
            result = 1.0;
        }
        if (x < 0)
        {
            n = 1 / n;
            x = -x;
        }
        result = (x % 2 == 0) ? pow(n * n, x / 2) : n * pow(n * n, x / 2);
    }
    void displayResult()
    {
        cout << n << " raised to the power " << x << " is " << result << endl;
    }

    void callerFunction()
    {
        getNumber();
        calculatePower();
        displayResult();
    }
};

// Lcm and Hcf Calculator
class lcmHcf
{
public:
    int n;
    vector<int> vec;
    int var1, var2;
    lcmHcf() // making a constructor to take input in every case
    {
        cout << "\nEnter the count of Number you want to find LCM / HCF ";
        cin >> n;
        if (n > 0)
        {
            cout << "\nEnter the elements ";
            for (int i = 0; i < n; i++)
            {
                int a;
                cin >> a;
                vec.push_back(a);
            }

            if (n >= 2)
            {
                var1 = vec[0];
                var2 = vec[1];
            }
        }
    }
    // designing hcf calculator for 2 numbers
    int hcfCalculatorFor2Numbers(int var1, int var2)
    {

        int maxm = max(var1, var2);
        int minm = min(var1, var2);
        int gcd;

        if (minm == 0)
            return maxm;
        while (maxm % minm != 0)
        {

            int temp = maxm;
            maxm = minm;
            minm = temp % minm;
        }
        gcd = minm;
        return gcd;
    }

    int lcmCalculatorFor2Numbers() // of two numbers
    {

        int prod = var1 * var2;
        int gcd = hcfCalculatorFor2Numbers(var1, var2);
        int lcm = prod / gcd;
        return lcm;
    }

    int lcmCalculatorForMoreThan2Numbers()
    {
        int lcm = hcfCalculatorFor2Numbers(vec[0], vec[1]);
        for (int i = 2; i < vec.size(); i++)
        {
            lcm = (lcm * vec[i]) / (hcfCalculatorFor2Numbers(lcm, vec[i]));
        }

        return lcm;
    }

    int hcfCalculatorForMoreThan2Numbers()
    {
        int GCD = hcfCalculatorFor2Numbers(vec[0], vec[1]);
        for (int i = 2; i < vec.size(); i++)
        {
            if (GCD == 1)
                break;

            GCD = hcfCalculatorFor2Numbers(vec[i], GCD);
        }
        return GCD;
    }

    void callerFunctionForLcm()
    {
        if (n <= 1)
            cout << "\nPlease Provide atleast 2 numbers" << endl;

        else if (n == 2)
        {
            int ans = lcmCalculatorFor2Numbers();
            cout << "Result is " << ans << endl;
        }
        else if (n > 2)
        {
            int ans = lcmCalculatorForMoreThan2Numbers();
            cout << "Result is " << ans << endl;
        }
    }
    void callerFunctionForHcf()
    {
        if (n <= 1)
            cout << "\nPlease Provide atleast 2 numbers" << endl;

        else if (n == 2)
        {
            int ans = hcfCalculatorFor2Numbers(var1, var2);
            cout << "Result is " << ans << endl;
        }
        else if (n > 2)
        {
            int ans = hcfCalculatorForMoreThan2Numbers();
            cout << "Result is " << ans << endl;
        }
        exit;
    }
};

// Determinant Calculation
class determinant
{
public:
    int n;
    // vector<vector<int>> matrix;
    int matrix[12][12];
    determinant()
    {
        try
        {
            cout << "\nEnter the Number of Rows & column ";
            cin >> n;
            if (n > 12 || n < 2)
            {
                throw n;
            }
            cout << "\nEnter the elem row wise " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter row no '" << i + 1 << "'  : ";
                for (int j = 0; j < n; j++)
                    cin >> matrix[i][j];
            }
        }
        catch (int n)
        {
            cout << "ERROR !! We Support Calculation from n = 2 to n = 12 due to memory issue. ThankYou for using.";
        }
    }

    int determinantCalculator(int matrix[12][12], int n)
    {
        int det = 0;
        int subMatrix[12][12];
        if (n == 2)
        {
            return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
        }

        else
        {
            for (int x = 0; x < n; x++)
            {
                int subi = 0;
                for (int i = 1; i < n; i++)
                {
                    int subj = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (j == x)
                            continue;
                        subMatrix[subi][subj] = matrix[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * matrix[0][x] * determinantCalculator(subMatrix, n - 1));
            }
        }
        return det;
    }

    void callerFunctionForDeterminant()
    {
        if (n <= 12 && n > 1)
        {
            cout << "\nYour Matrix Was " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

            int ans = determinantCalculator(matrix, n);
            cout << "\nAns is " << ans;
        }
        else
        {
            cout << "\nProceed with Correct Values" << endl;
        }
    }
};

// conversion
class conversion
{
public:
    bool checkbinary(long long n)
    {
        string s;

        s = to_string(n);

        bool ans = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '0' && s[i] != '1')
            {
                ans = 0;
                break;
            }
        }
        if (!ans)
            cout << "\nError : Entered no is not binary !!" << endl;
        return ans;
    }

    bool checkDecimal(long long n)
    {
        string s;
        s = to_string(n);
        bool ans = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                ans = 0;
        }
        if (!ans)
            cout << "\nPlease Enter valid Decimal number . Thank you !!" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "Error !! Invalid Input ." << endl;
        }

        return ans;
    }

    void binaryToDecimal()
    {
        long long s;
        cout << "\nEnter the number in binary : ";
        cin >> s;
        bool result = checkbinary(s);
        if (result)
        {
            int decimal = 0;
            int i = 0, rem;
            while (s != 0)
            {
                rem = s % 10;
                s /= 10;
                decimal += rem * pow(2, i);
                ++i;
            }
            cout << "\nThe number in decimal is : " << decimal << endl;
        }
        else
        {
            cout << "Please Try Again!! and Enter Correct values !!" << endl;
        }
    }

    void decimalToBinary()
    {
        long long s;
        cout << "\nEnter the number in decimal : ";
        cin >> s;
        bool result = checkDecimal(s);

        if (result)
        {
            vector<int> binaryNumber;
            int i = 0;
            while (s > 0)
            {
                binaryNumber.push_back(s % 2);
                s = s / 2;
                i++;
            }
            reverse(binaryNumber.begin(), binaryNumber.end());

            cout << "\nThe binary conversion is ";
            for (int i = 0; i < binaryNumber.size(); i++)
            {
                cout << binaryNumber[i];
            }
            cout << endl;
        }
    }
};

// Prime number list
class prime
{

public:
    long long int n;
    int s;
    const int N = 1e6;
    vector<int> primeList;

    prime()
    {
        cout << "\nWanna check the primality ( enter 1 for it ) or want to get the list of Prime from 1 till N(enter 2 for it). ";
        cin >> s;
        if (s == 1)
        {
            cout << "\nEnter the Number of which you want to check primality : ";
            cin >> n;
            int a = checkPrime();
            if (!a)
            {
                vector<int> primeFact = primeFactorisation();
                cout << "\nWanna know its prime factorisation (enter 1 for yes / 0 for no) ?? ";
                bool variable;
                cin >> variable;
                if (variable)
                {
                    for (int i = 0; i < primeFact.size(); i++)
                        cout << primeFact[i] << " ";
                }
            }
        }
        else if (s == 2)
        {
            cout << "\nEnter the Number upto which you need to find the prime number : ";
            cin >> n;
            callerFunction();
        }
        else
        {
            cout << "\nEnter the Number upto which you need to find the prime number : ";
        }
    }
    // finding PrimeFactorisation also
    vector<int> primeFactorisation()
    {
        vector<int> primeFact;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                primeFact.push_back(i);
                n = n / i;
            }
        }
        if (n != 1)
            primeFact.push_back(n);

        return primeFact;
    }

    // defining calculatePrime using sieve of eratosthenes;
    void calculatePrime()
    {
        for (int i = 1; i < n + 1; i++)
        {
            primeList.push_back(1);
        }
        primeList[1] = 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (primeList[i] == 1)
            {
                for (int j = i; i * j <= n; j++)
                {
                    primeList[i * j] = 0;
                }
            }
        }
    }

    void displayList()
    {
        cout << "\nThe Prime Number list is as follows" << endl;
        cout << endl;
        for (int i = 1; i < primeList.size(); i++)
        {
            if (primeList[i])
                cout << i << " ";
        }
    }

    void callerFunction()
    {
        calculatePrime();
        displayList();
    }

    int checkPrime()
    {
        int cnt = 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                cnt++;
        }
        if (cnt == 0)
        {
            cout << "\nYes !! The number " << n << " is Prime . ";
            return 1;
        }
        else
        {
            cout << "\nNo !! The number " << n << " is not Prime." << endl;
            return 0;
        }
    }
};

// Multiplication Table Creation
class mTable
{
public:
    long long int n, u = 20, s = 1;
    mTable()
    {
        int c;
        cout << "\nEnter the number of which you want to find Multiplication table ";
        cin >> n;
        cout << "\nWanna give starting and ending point (by default start from 1 and ends at 20 ) ? Enter 0 or 1 for no or yes . ";
        cin >> c;
        if (c)
        {
            cout << "\nFrom (starting point)";
            cin >> s;
            cout << "\nUpto which Number (ending point)";
            cin >> u;
        }
    }
    void tableCalc()
    {
        while (s <= u)
        {
            cout << n << " x " << s << " = " << n * s << endl;
            s++;
        }
    }
};

// Prime Factorisation
class primeFactors
{
public:
    long long int n;
    primeFactors()
    {
        cout << "\nEnter the number of which you want to find prime factorisation ";
        cin >> n;
    }
    // finding PrimeFactorisation also
    vector<int> primeFactorisation()
    {
        vector<int> primeFact;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                primeFact.push_back(i);
                n = n / i;
            }
        }
        if (n != 1)
            primeFact.push_back(n);

        return primeFact;
    }

    void displayVec()
    {
        vector<int> vec = primeFactorisation();
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
    }
};

// quadratic equations
class quadratic
{
public:
    double a, b, c, d, r1, r2;
    quadratic()
    {
        cout << "\nEnter the quadratic equation values of a, b, and c by compairing it with ax^2 + bx + c = 0. ";
        cin >> a >> b >> c;
    }
    void Dcalc()
    {
        d = sqrt(b * b - 4 * a * c);
        r1 = (-1 * b + d) / (2 * a);
        r2 = (-1 * b - d) / (2 * a);
    }
    void displayResult()
    {
        if (a == 0)
        {
            cout << "\nError !! 'a' can't be zero !!";
        }
        else if(b*b<4*a*c){
            cout << "\nError !! b^2 should be greater than or equal to 4*a*c !!";
        }
        else
        {
            Dcalc();
            cout << "\na is " << a << " b is " << b << " c is " << c << " D is " << d << endl;
            if (to_string(d) == "nan")
                cout << "\nError!!";
            else
                cout << "\nThe roots are " << r1 << " and " << r2 << endl;
        }
    }
};

int main()
{
    showCompulsorilyToUser();
    choices = functionToFillMap();
    int x = 1;
    while (x)
    {
        askUsersChoice();
        try
        {
            int inputChoice;
            cin >> inputChoice;
            if (inputChoice == 0)
                break;
            if (inputChoice > 20)
                throw(inputChoice);

            auto itr = choices.find(inputChoice);
            cout << "\nYou Chose For : ";
            cout << itr->second;

            switch (inputChoice)
            {
            case 2:
            {
                lcmHcf h1;
                h1.callerFunctionForHcf();
                break;
            }

            case 3:
            {
                lcmHcf l1;
                l1.callerFunctionForLcm();
                break;
            }

            case 4:
            {
                determinant d1;
                d1.callerFunctionForDeterminant();
                break;
            }

            case 6:
            {
                quadratic q1;
                q1.displayResult();
                break;
            }
            case 7:
            {
                powerCalculation pc1;
                pc1.callerFunction();
                break;
            }

            case 8:
            {
                factorial f1;
                f1.getNumber();
                break;
            }

            case 10:
            {
                conversion c1;
                c1.binaryToDecimal();
                break;
            }

            case 11:
            {
                conversion c2;
                c2.decimalToBinary();
                break;
            }

            case 15:
            {
                prime p1;
                break;
            }
            case 16:
            {
                primeFactors pf1;
                pf1.displayVec();
                break;
            }
            case 17:
            {
                mTable mt1;
                mt1.tableCalc();
                break;
            }

            default:
                cout << " The number which doesnot coincide with available choices . Kindly enter 'correct value' " << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << "Error !! Error !! Input invalid ." << endl;
                }
            }
        }
        catch (int inputChoice)
        {
            cout << "Please enter only the choice given . Thankyou." << endl;
        }
        cout << "\nThankyou !! " << endl;
        cout << "\n\n\nTo finish the execution cycle for 1 round ,You will have to Press 'f' : ";
        char s;
        cin >> s;
        // cout<<"entered value is "<<s<<endl;
        if (s == 'f')
        {
            x = 1;
            cout << "\nExecution for next round begins  " << endl;
        }
        else
        {
            cout << "\nYou Pressed " << s << " during your last Calculation which resulted into Non-Compliance with our Protocol. Hence Program has been shut down.";
            x = 0;
        }
    }

    return 0;
}