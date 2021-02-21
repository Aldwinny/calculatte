#include <cmath>  //For fabs()
#include <cfloat> //For FLT_EPSILON

using namespace std;

class calc
{
public:
    static float sum(float &x, float &y)
    {
        return x + y;
    }

    static float diff(float &x, float &y)
    {
        return x - y;
    }

    static float prod(float &x, float &y)
    {
        if (validate(x, y, 'm'))
            return x * y;
        else
            Error('m');
        return 0;
    }

    static float quot(float &x, float &y)
    {
        if (validate(x, y, 'd'))
            return x / y;
        else
            Error('d');
        return 0;
    }

    static float sum(float x, float y)
    {
        return x + y;
    }

    static float diff(float x, float y)
    {
        return x - y;
    }

    static float prod(float x, float y)
    {
        if (validate(x, y, 'm'))
            return x * y;
        else
            Error('m');
        return 0;
    }

    static float quot(float x, float y)
    {
        if (validate(x, y, 'd'))
            return x / y;
        else
            Error('d');
        return 0;
    }

private:
    static bool validate(float &x, float &y, char op)
    {
        float result;

        //Case multiplication of x & y
        if (op == 'm')
        {
            //Checks if any is 0
            if (x == 0 || y == 0)
            {
                return true;
            }

            //Computes for result and checks if result did not overflow
            //by comparing to the precision value
            result = x * y;
            if (fabs(result - (x * y)) <= FLT_EPSILON)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Case division of x & y
        else if (op == 'd')
        {
            if (y == 0)
                return false;
            return true;
        }
        return false;
    }

    static void Error(char op)
    {
        if (op == 'm')
        {
            throw "Math Error: Product reached float precision limit!";
        }
        else if (op == 'd')
        {
            throw "Math Error: Division by Zero";
        }
        else
        {
            throw "Math Error!";
        }
    }
};