#include <stdio.h>
#include <math.h>
#define MAX 20

typedef struct polynomial
{
    double coefficient_of_x;
    double exponent_of_x;
}polynomial;

typedef struct exponential
{
    double coefficient_of_x;
    double exponent_of_x;
    double coefficient_of_function;
    double exponent_of_function;
    double base;
}exponential;

typedef struct logarithmic
{
    double coefficient_of_x;
    double exponent_of_x;
    double coefficient_of_function;
    double exponent_of_function;
    double base;
}logarithmic;

enum trigfuncs
{
    Sin,
    Cos,
    Tan,
    Cot
};

typedef struct trigonometric
{   
    enum trigfuncs trig;
    double coefficient_of_x;
    double exponent_of_x;
    double coefficient_of_function;
    double exponent_of_function;
}trigonometric;

typedef struct inverseTrigonometric
{
    enum trigfuncs trig;
    double coefficient_of_x;
    double exponent_of_x;
    double coefficient_of_function;
    double exponent_of_function;
}inverseTrigonometric;

typedef struct functionTypes
{
    struct polynomial polynomial;
    struct exponential exponential;
    struct logarithmic logarithmic;
    struct trigonometric trigonometric;
    struct inverseTrigonometric inverseTrigonometric;
}functionTypes;

void getFunctionParameters(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void printFunction(struct functionTypes functions[], int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
double calculateFunction(double *value, struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void bisectionMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void regulaFalsi(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void newtonRaphson(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void getMatrix(double Matrix[MAX][MAX], int *N);
void printMatrix(double Matrix[MAX][MAX], int N);
void setIdentityMatrix(double identityMatrix[MAX][MAX], int *N);
void numericalDifferentiation(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void simpsonMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void trapezoidalMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void gregoryNewtonsInterpolation();
void forwardDifferenceTable(double ax[MAX], double ay[MAX][MAX], int inputCount);
void printForwardDifferenceTable(double ax[MAX], double ay[MAX][MAX], int inputCount);
double calculateCentralDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
double calculateForwardDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
double calculateBackwardDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount);
void inverseMatrix();
void getAugmentedMatrix(double Matrix[MAX][MAX], int *N);
void printAugmentedMatrix(double Matrix[MAX][MAX], int N);
void GaussElimination();
void GaussSeidal();
char* getTrigName(struct functionTypes functions[], int i);
char* getInverseTrigName(struct functionTypes functions[], int i);

int main()
{   int choice, degree, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount;
    struct functionTypes functions[MAX];
    double sum, value;

    do
    {
        printf("\n\nPlease select the operation you want to perform:\n\n");
        printf("Quit:  0\n");
        printf("Bisection Method:  1\n");
        printf("Regula-Falsi Method:  2\n");
        printf("Newton Raphson:  3\n");
        printf("Inverse Matrix:  4\n");
        printf("Gauss Elimination:  5\n");
        printf("Gauss-Seidal:  6\n");
        printf("Numerical Differentiation:  7\n");
        printf("Simpson's Rule:  8\n");
        printf("Trapezoidal Rule:  9\n");
        printf("Gregory-Newton's Interpolation:  10\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            bisectionMethod(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 2:
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            regulaFalsi(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 3:
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            newtonRaphson(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 4:
            inverseMatrix();
            break;
        case 5:
            GaussElimination();
            break;
        case 6:
            GaussSeidal();
            break;
        case 7: 
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            numericalDifferentiation(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 8:
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            simpsonMethod(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 9:
            getFunctionParameters(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            printFunction(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            trapezoidalMethod(functions, &polynomialCount, &exponentialCount, &logarithmicCount, &trigonometricCount, &inverseTrigonometricCount);
            break;
        case 10:
            gregoryNewtonsInterpolation();
        }
    } while (choice!=0);
    
    
    return 0;
}

void getFunctionParameters(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount)
{   
    printf("\nHow many polynomial terms are there in the equation?\n");
    scanf(" %d", &*polynomialCount);
    printf("\nHow many exponential terms are there in the equation?\n");
    scanf(" %d", &*exponentialCount);
    printf("\nHow many logarithmic terms are there in the equation?\n");
    scanf(" %d", &*logarithmicCount);
    printf("\nHow many trigonometric terms are there in the equation?\n");
    scanf(" %d", &*trigonometricCount);
    printf("\nHow many inverse trigonometric terms are there in the equation?\n");
    scanf(" %d", &*inverseTrigonometricCount);

    int i = 0;
    int sequenceNumber = *polynomialCount;
    for (i; i < sequenceNumber; i++)//Get polynomial function's parameters
    {   
        printf("\nPolynomial: x_coef * x ^ x_exp");

        printf("\n\nx's coefficient (x_coef):\n");
        scanf(" %lf", &functions[i].polynomial.coefficient_of_x);

        printf("\nx's exponent (x_exp):\n");
        scanf(" %lf", &functions[i].polynomial.exponent_of_x);

        printf("\nAdded: %lf * x ^ %lf", functions[i].polynomial.coefficient_of_x, functions[i].polynomial.exponent_of_x);
    }
    sequenceNumber += *exponentialCount;

    for (i; i < sequenceNumber; i++)//Get exponential function's parameters
    {
        printf("\nExponential: fn_coef * (base ^ (x_coef * x ^ x_exp)) ^ fn_exp");

        printf("\n\nx's coefficient (x_coef):\n");
        scanf(" %lf", &functions[i].exponential.coefficient_of_x);

        printf("\nx's exponent (x_exp):\n");
        scanf(" %lf", &functions[i].exponential.exponent_of_x);

        printf("\nFunction coefficient (fn_coef):\n");
        scanf(" %lf", &functions[i].exponential.coefficient_of_function);

        printf("\nFunction exponent (fn_exp):\n");
        scanf(" %lf", &functions[i].exponential.exponent_of_function);

        printf("\nBase (base):\n");
        scanf(" %lf", &functions[i].exponential.base);

        printf("\nAdded: %lf * (%lf ^ (%lf * x ^ %lf)) ^ %lf", functions[i].exponential.coefficient_of_function, functions[i].exponential.base, functions[i].exponential.coefficient_of_x, 
            functions[i].exponential.exponent_of_x, functions[i].exponential.exponent_of_function);
    }
    sequenceNumber += *logarithmicCount;

    for (i; i < sequenceNumber; i++)//Get logarithmic's function's parameters
    {
        printf("\nLogarithmic: fn_coef * (log_base (x_coef * x ^ x_exp)) ^ fn_exp");

        printf("\n\nx's coefficient (x_coef):\n");
        scanf(" %lf", &functions[i].logarithmic.coefficient_of_x);

        printf("\nx's exponent (x_exp):\n");
        scanf(" %lf", &functions[i].logarithmic.exponent_of_x);

        printf("\nFunction coefficient (fn_coef):\n");
        scanf(" %lf", &functions[i].logarithmic.coefficient_of_function);

        printf("\nFunction exponent (fn_exp):\n");
        scanf(" %lf", &functions[i].logarithmic.exponent_of_function);

        printf("\nBase (log_base):\n");
        scanf(" %lf", &functions[i].logarithmic.base);

        printf("\nAdded: %lf * (log_%lf (%lf * x ^%lf)) ^ %lf", functions[i].logarithmic.exponent_of_function, functions[i].logarithmic.base, functions[i].logarithmic.coefficient_of_x,
            functions[i].logarithmic.exponent_of_x, functions[i].logarithmic.exponent_of_function);
    }
    sequenceNumber += *trigonometricCount;

    for (i; i < sequenceNumber; i++)//Get trigonometric function's parameters
    {
        printf("\nTrigonometric: fn_coef * <trig_fn>(x_coef * x ^ x_exp) ^ fn_exp");

        printf("\nTrigonometric function (trif_fn):\n");
        printf("sin: 0, cos: 1, tan: 2, cot:3\n");
        scanf(" %u", &functions[i].trigonometric.trig);

        printf("\n\nx's coefficient (x_coef):\n");
        scanf(" %lf", &functions[i].trigonometric.coefficient_of_x);

        printf("\nx's exponent (x_exp):\n");
        scanf(" %lf", &functions[i].trigonometric.exponent_of_x);

        printf("\nFunction coefficient (fn_coef):\n");
        scanf(" %lf", &functions[i].trigonometric.coefficient_of_function);

        printf("\nFunction exponent (fn_exp):\n");
        scanf(" %lf", &functions[i].trigonometric.exponent_of_function);

        printf("\nAdded: %lf * <%s>(%lf * x ^ %lf) ^ %lf\n", functions[i].trigonometric.coefficient_of_function, getTrigName(functions, i), functions[i].trigonometric.coefficient_of_x,
            functions[i].trigonometric.exponent_of_x, functions[i].trigonometric.exponent_of_function);
    }
    sequenceNumber += *inverseTrigonometricCount;

    for (i; i < sequenceNumber; i++)// Get inverse trigonometric function's parameters
    {
        printf("\nInverse trigonometric: fn_coef * arctrig_fn>(x_coef * x ^ x_exp) ^ fn_exp");
        printf("\narcsin: 0, arccos: 1, arctan: 2, arccot:3\n");
        scanf(" %u", &functions[i].inverseTrigonometric.trig);
        printf("\n\nx's coefficient (x_coef):\n");
        scanf(" %lf", &functions[i].inverseTrigonometric.coefficient_of_x);

        printf("\nx's exponent (x_exp):\n");
        scanf(" %lf", &functions[i].inverseTrigonometric.exponent_of_x);

        printf("\nFunction coefficient (fn_coef):\n");
        scanf(" %lf", &functions[i].inverseTrigonometric.coefficient_of_function);

        printf("\nFunction exponent (fn_exp)\n");
        scanf(" %lf", &functions[i].inverseTrigonometric.exponent_of_function);

        printf("\nAdded: %lf * <%s>(%lf * x ^ %lf) ^ %lf\n", functions[i].inverseTrigonometric.coefficient_of_function, getInverseTrigName(functions, i), functions[i].inverseTrigonometric.coefficient_of_x,
            functions[i].inverseTrigonometric.exponent_of_x, functions[i].inverseTrigonometric.exponent_of_function);
    }
}

void printFunction(struct functionTypes functions[], int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount)
{
    int i = 0;
    int sequenceNumber = *polynomialCount;

    printf("\n\nFunction:");

    for(i; i < sequenceNumber; i++)//Print polynomial
    {
        printf(" %lf * x ^ %lf +", functions[i].polynomial.coefficient_of_x, functions[i].polynomial.exponent_of_x);
    }
    sequenceNumber += *exponentialCount;

    for (i; i < sequenceNumber; i++)//Prrint exponential
    {
        printf(" %lf * (%lf ^ (%lf * x ^ %lf)) ^ %lf +", functions[i].exponential.coefficient_of_function, functions[i].exponential.base, functions[i].exponential.coefficient_of_x, 
            functions[i].exponential.exponent_of_x, functions[i].exponential.exponent_of_function);
    }
    sequenceNumber += *logarithmicCount;

    for (i; i < sequenceNumber; i++)//Print logarithmic
    {
        printf(" %lf * (%lf (%lf * x ^%lf)) ^ %lf +", functions[i].logarithmic.exponent_of_function, functions[i].logarithmic.base, functions[i].logarithmic.coefficient_of_x,
            functions[i].logarithmic.exponent_of_x, functions[i].logarithmic.exponent_of_function);
    }
    sequenceNumber += * trigonometricCount;

    for (i; i < sequenceNumber; i++)//Print trigonometric
    {
        printf(" %lf * <%s>(%lf * x ^ %lf) ^ %lf +", functions[i].trigonometric.coefficient_of_function, getTrigName(functions, i), functions[i].trigonometric.coefficient_of_x,
            functions[i].trigonometric.exponent_of_x, functions[i].trigonometric.exponent_of_function);
    }
    sequenceNumber += *inverseTrigonometricCount;

    for (i; i < sequenceNumber; i++)//Print inverse trigonometric
    {
        printf(" %lf * <%s>(%lf * x ^ %lf) ^ %lf +", functions[i].inverseTrigonometric.coefficient_of_function, getInverseTrigName(functions, i), functions[i].inverseTrigonometric.coefficient_of_x,
            functions[i].inverseTrigonometric.exponent_of_x, functions[i].inverseTrigonometric.exponent_of_function);
    }
}

double calculateFunction(double *value, struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount)
{   
    int i = 0;
    double sum = 0;
    
    int sequenceNumber = *polynomialCount;
    for (i; i < sequenceNumber; i++)//Calculate polynomial function
    {   
        sum += functions[i].polynomial.coefficient_of_x * pow(*value, functions[i].polynomial.exponent_of_x);
    }
    sequenceNumber += *exponentialCount;
    for (i; i < sequenceNumber; i++)//Calculate exponential function
    {
        sum += functions[i].exponential.coefficient_of_function * pow((pow(functions[i].exponential.base, functions[i].exponential.coefficient_of_x * (pow(*value, functions[i].exponential.exponent_of_x)))), functions[i].exponential.exponent_of_function);
    }
    sequenceNumber += *logarithmicCount;
    for (i; i < sequenceNumber; i++)
    {
        sum += functions[i].logarithmic.coefficient_of_function * pow(log10(functions[i].logarithmic.coefficient_of_x * pow(*value, functions[i].logarithmic.exponent_of_x))/log10(functions[i].logarithmic.base), functions[i].logarithmic.exponent_of_function);
    }
    sequenceNumber += *trigonometricCount;
    for (i; i < sequenceNumber; i++)//Calculate trigonometric function
    {   
        switch(functions[i].trigonometric.trig){
            case 0:
                sum += functions[i].trigonometric.coefficient_of_function * pow(sin(functions[i].trigonometric.coefficient_of_x * pow(*value, functions[i].trigonometric.exponent_of_x)), functions[i].trigonometric.exponent_of_function);
                break;
            case 1:
                sum += functions[i].trigonometric.coefficient_of_function * pow(cos(functions[i].trigonometric.coefficient_of_x * pow(*value, functions[i].trigonometric.exponent_of_x)), functions[i].trigonometric.exponent_of_function);
                break;
            case 2:
                sum += functions[i].trigonometric.coefficient_of_function * pow(tan(functions[i].trigonometric.coefficient_of_x * pow(*value, functions[i].trigonometric.exponent_of_x)), functions[i].trigonometric.exponent_of_function);
                break;
            case 3:
                sum += functions[i].trigonometric.coefficient_of_function * pow(1/tan(functions[i].trigonometric.coefficient_of_x * pow(*value, functions[i].trigonometric.exponent_of_x)), functions[i].trigonometric.exponent_of_function);
                break;
        }
    }      
    sequenceNumber += *inverseTrigonometricCount;
    for (i; i < sequenceNumber; i++)//Calculate inverse trigonometric function
    {   
        switch(functions[i].trigonometric.trig){
            case 0:
                sum += functions[i].inverseTrigonometric.coefficient_of_function * pow(asin(functions[i].inverseTrigonometric.coefficient_of_x * pow(*value, functions[i].inverseTrigonometric.exponent_of_x)), functions[i].inverseTrigonometric.exponent_of_function);
                break;
            case 1:
                sum += functions[i].inverseTrigonometric.coefficient_of_function * pow(acos(functions[i].inverseTrigonometric.coefficient_of_x * pow(*value, functions[i].inverseTrigonometric.exponent_of_x)), functions[i].inverseTrigonometric.exponent_of_function);
                break;
            case 2:
                sum += functions[i].inverseTrigonometric.coefficient_of_function * pow(atan(functions[i].inverseTrigonometric.coefficient_of_x * pow(*value, functions[i].inverseTrigonometric.exponent_of_x)), functions[i].inverseTrigonometric.exponent_of_function);
                break;
            case 3:
                sum += functions[i].inverseTrigonometric.coefficient_of_function * pow(1/atan(functions[i].inverseTrigonometric.coefficient_of_x * pow(*value, functions[i].inverseTrigonometric.exponent_of_x)), functions[i].inverseTrigonometric.exponent_of_function);
                break;
        }
    }  
    return sum; 
}

void bisectionMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){   
    
    double start, end, mid, epsilon, f0, f1, f2;
    int maxIteration;
    int iteration = 1;
    
    do{
        printf("\nEnter the starting point:\n");
        scanf(" %lf", &start);

        printf("\nEnter the ending point:\n");
        scanf(" %lf", &end);
        f0 = calculateFunction(&start, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        f1 = calculateFunction(&end, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        if (f0 * f1 > 0)
        {
            printf("\nIncorrect values, please try again...\n");
        }
        
    }while(f0 * f1 > 0);

    printf("\nEnter the epsilon value:\n");
    scanf(" %lf", &epsilon);

    printf("\nEnter the maximum iteration to be allowed:\n");
    scanf("%d", &maxIteration);
    while (((end - start) > epsilon) && iteration<=maxIteration)
    {
        mid = (start + end)/2;
        f2 = calculateFunction(&mid, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        printf("\n\nstart: %lf", start);
        printf("\nend: %lf", end);
        printf("\nmid: %lf", mid);
        printf("\nf(start): %lf", f0);
        printf("\nf(end): %lf", f1);
        printf("\nf(mid): %lf", f2);
        printf("\niteration: %d", iteration);

        if(f0 * f2 < 0){
            end = mid;
        }
        else{
            start = mid;
        }
        iteration++;
    }
    printf("\nResult: %lf", mid);  
}

void regulaFalsi(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    double start, end, mid, epsilon, f0, f1, f2;
    int maxIteration;
    int iteration = 1;
    
    do{
        printf("\nEnter the starting point:\n");
        scanf(" %lf", &start);

        printf("\nEnter the ending point:\n");
        scanf(" %lf", &end);
        f0 = calculateFunction(&start, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        f1 = calculateFunction(&end, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        if (f0 * f1 > 0)
        {
            printf("\nIncorrect values, please try again...\n");
        }
        if (f0 == 0)
        {
            printf("\nThe root is already the input value, which is %lf.\n", start);
        }
        if (f1 == 0)
        {
            printf("\nThe root is already the input value, which is %lf.\n", end);
        }
    }while(f0 * f1 > 0);

    printf("\nEnter the epsilon value:\n");
    scanf(" %lf", &epsilon);

    printf("\nEnter the maximum iteration to be allowed:\n");
    scanf("%d", &maxIteration);
    while (((end - start) > epsilon) && iteration<=maxIteration)
    {
        mid = (end*f0 - start*f1)/(f0 - f1);
        f2 = calculateFunction(&mid, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        printf("\n\nstart: %lf", start);
        printf("\nend: %lf", end);
        printf("\nmid: %lf", mid);
        printf("\nf(start): %lf", f0);
        printf("\nf(end): %lf", f1);
        printf("\nf(mid): %lf", f2);
        printf("\niteration: %d", iteration);

        if(f0 * f2 < 0){
            end = mid;
        }
        else{
            start = mid;
        }
        iteration++;
    }
    printf("\nResult: %lf", mid);  
}

void newtonRaphson(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    double n1, n2, temp, epsilon, f1, f2, df1;
    double h = 0.0001;
    int maxIteration = 100;
    int iteration = 1;
    int flag = 1;
    
    do{
        printf("\nEnter the starting point:\n");
        scanf(" %lf", &n1);

        f1 = calculateFunction(&n1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        if (f1 == 0)
        {
            printf("\nIncorrect value, please try again...\n");
        }
        
    }while(f1 == 0);

    printf("\nEnter the epsilon value:\n");
    scanf(" %lf", &epsilon);

    do{   
        f1 = calculateFunction(&n1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        df1 = calculateCentralDifferentiation(h, &n1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        if (df1==0)
        {
            printf("\nMathematical error!");
            flag = 0;
        }
        if (flag==1)
        {
            n2 = n1 - (f1/df1);
            printf("\n\nxn: %lf", n1);
            printf("\nxn+1: %lf", n2);
            printf("\nf(xn): %lf", f1);
            printf("\nf'(xn): %lf", df1);
            printf("\niteration: %d", iteration);
            
            temp = n1;
            n1 = n2;
            n2 = temp;
            if (iteration>maxIteration)
            {
                printf("\nNot convergent!");
                flag=0;
            }
            iteration++;
        }
        
          
    }while ((fabs(n2 - n1) > epsilon) && (flag==1));
    if (flag==1)
    {
        printf("\nResult: %lf", n2);    
    }
}

void inverseMatrix(){
    int i,j,k,N;
    int flag = 1;
    double division, multiply;
    double Matrix[MAX][MAX];
    double identityMatrix[MAX][MAX] = {0};
    
    getMatrix(Matrix, &N);

    printf("\nMatrix: \n");
    printMatrix(Matrix, N);
    setIdentityMatrix(identityMatrix, &N);
    for (i = 0; i < N; i++)
    {
        if (Matrix[i][i] == 0)
        {
            flag = 0;
        }
    }
    for (i = 0; i < N; i++)
    {   
        if (flag==1)
        {
            division = Matrix[i][i];
            if (Matrix[i][i] == 0)
            {
                flag = 0;
            }
            for (j = 0; j < N; j++)
            {
                identityMatrix[i][j] = identityMatrix[i][j]/ division;
            }
            for (j = 0; j < N; j++)
            {
                Matrix[i][j] = Matrix[i][j]/division;
            }
            
            for (j = 0; j < N; j++)
            {
                for (k = 0; k < N; k++)
                {
                    multiply = Matrix[j][i];
                    if (i!=j)
                    {   
                        identityMatrix[j][k] = identityMatrix[j][k] - (multiply * identityMatrix[i][k]);
                    }
                }
                for (k = 0; k < N; k++)
                {
                
                    if (i!=j)
                    {   
                        Matrix[j][k] = Matrix[j][k] - (multiply * Matrix[i][k]);
                    }
                }
            }
        }
    }
    if (flag==1)
    {
        printf("\nInverse Matrix: \n");
        printMatrix(identityMatrix, N);
    }
    if (flag == 0)
    {
        printf("\nMathematical error!\n");
    }
}

void GaussElimination(){
    
    int i,j,k,N;
    int flag = 1;
    double division, multiply,sum;
    double Matrix[MAX][MAX];
    double variableValues[MAX];

    getAugmentedMatrix(Matrix, &N);
    printf("\nMatrix:\n");
    printAugmentedMatrix(Matrix, N);
    printf("\n");
    for (i = 0; i < N; i++)
    {   
        if (Matrix[i][i]==0)
        {
            flag = 0;
        }

        if (flag==1)
        {
            division = Matrix[i][i];

            for (j = 0; j < N+1; j++)
            {
                Matrix[i][j] = Matrix[i][j]/division;
            }
            for (j = 0; j < N; j++)
            {   
                if (i<j)
                {
                    division = Matrix[j][i];
                    for (k = 0; k < N+1; k++)
                    {
                        Matrix[j][k] =  Matrix[j][k] / division; 
                    }
                    for (k = 0; k < N+1; k++)
                    {
                        Matrix[j][k] =  Matrix[j][k] - Matrix[i][k];
                    }

                    for (k = 0; k < N+1; k++)
                    {
                        Matrix[j][k] =  Matrix[j][k] * division;
                    }
                }   
            }
        }
    }
    if (flag==0)
    {
        printf("\nMathematical error!\n");
    }
    if (flag==1)
    {
        printf("\nGauss Elimination result:\n");
        printAugmentedMatrix(Matrix, N);
        variableValues[N-1] = Matrix[N-1][N]/Matrix[N-1][N-1];
        for (i = N-2; i >= 0; i--)
        {   
            sum = 0;
            for (j =i+1; j < N; j++)
            {
                sum += Matrix[i][j] * variableValues[j];
            }
            variableValues[i] = (Matrix[i][N] - sum)/Matrix[i][i];
        }
        for (i = N-1; i >= 0; i--)
        {
            printf("\nx%d: %lf\n", i, variableValues[i]);
        }
    }
}

void GaussSeidal(){
    int i,j,k,N, rowMin, rowMax, columnMin, columnMax;
    double epsilon,sum,initial;
    double Matrix[MAX][MAX];
    double temp[MAX];
    double variableValues[MAX];
    double tempVariableValues[MAX];
    int maxIteration;
    int iteration = 1;
    int count = 0;
    int flag = 1;
    getAugmentedMatrix(Matrix, &N);

    printf("\nEnter the epsilon value:\n");
    scanf(" %lf", &epsilon);
    printf("\nEnter the maximum iteration to be allowed:\n");
    scanf("%d", &maxIteration);
    for (i = 0; i < N; i++)
    {   
        rowMax = 0;
        for (j = 0; j < N+1; j++)
        {
            if (Matrix[j][i] > Matrix[rowMax][i])
            {
                rowMax = j;
            } 
        }
        for (j = 0; j < N+1; j++)
        {
            temp[j] = Matrix[i][j];
        }
        for (j = 0; j < N+1; j++)
        {
            Matrix[i][j] = Matrix[rowMax][j];
        }
        for (j = 0; j < N+1; j++)
        {
            Matrix[rowMax][j] = temp[j];
        }
        if (Matrix[i][i]==0)
        {
            flag=0;
        }
    }
    if (flag==0)
    {
        printf("\nMathematical error!\n");
    }
    if (flag==1)
    {
        printf("\n\n");
        printAugmentedMatrix(Matrix, N);
        printf("\n");
        printf("\nEnter initial values for variables: \n");
        scanf(" %lf", &initial);
        for (i = 0; i < N; i++)
        {
            variableValues[i] = initial;
            tempVariableValues[i] = initial;
        }
        
        printf("\nIteration: 0");
        for (i = 0; i < N; i++)
        {
            printf("\n x%d:       %lf",i,variableValues[0]);
            printf("\n|x%d|:      %lf",i,fabs(variableValues[0]-tempVariableValues[0]));
        }
        count = 1;
        do
        {   
            printf("\n");
            for (i = 0; i < N; i++)
            {       
                sum = 0;
                for (j = 0; j < N ; j++)
                {
                    sum += variableValues[j] * Matrix[i][j];
                }
                variableValues[i] += (Matrix[i][N] - sum)/Matrix[i][i];
            }
            printf("\nIteration: %d", count);
            for (i = 0; i < N; i++)
            {
                printf("\n x%d:       %lf",i,variableValues[i]);
                printf("\n|x%d|:      %lf",i,fabs(variableValues[i]-tempVariableValues[i]));
            }
            printf("\n");
            flag = 0;
            for (i = 0; i < N; i++)
            {
                if (fabs(tempVariableValues[i] - variableValues[i]) > epsilon)
                {
                    flag = 1;
                }            
            }
            for (i = 0; i < N; i++)
            {
                tempVariableValues[i] = variableValues[i];
            }
            count++;
        } while(flag == 1);
        printf("\nResult:\n");
        for (i = 0; i < N; i++)
        {
            printf("\nx%d: %lf",i,variableValues[i]);
        }
    }
}

void numericalDifferentiation(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    int choice;
    double index, h, f0, f1, f2, df;
    printf("\n(0) Backward Differentiation\n");
    printf("\n(1) Central Differentiation\n");
    printf("\n(2) Forward Differentiation\n");
    printf("\nPlease select one of the numerical differentiation methods from the options above that you would like to use.\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 0:
        printf("\n(f(xi) - f(xi-h))/h\n");
        printf("\nEnter at what value of x you want to calculate derivative: \n");
        scanf(" %lf", &index);
    do
    {
        if (h<=0)
        {
            printf("\nYou cannot enter a value equal to 0 or a value less than 0.\n");
        }
        printf("\nEnter the h value: \n");
        scanf("%lf", &h);
    } while (h<=0);
        df = calculateBackwardDifferentiation(h, &index ,functions,polynomialCount,exponentialCount,logarithmicCount,trigonometricCount,inverseTrigonometricCount);
        printf("\nResult df: %lf\n", df);
        break;
    
    case 1:
        printf("\n(f(xi+h) - f(xi-h))/2h\n");
        printf("\nEnter at what value of x you want to calculate derivative: \n");
        scanf(" %lf", &index);
        do
        {
            if (h<=0)
            {
                printf("\nYou cannot enter a value equal to 0 or a value less than 0.\n");
            }
            printf("\nEnter the h value: \n");
            scanf("%lf", &h);
        } while (h<=0);
        df = calculateCentralDifferentiation(h, &index ,functions,polynomialCount,exponentialCount,logarithmicCount,trigonometricCount,inverseTrigonometricCount);
        printf("\nResult df: %lf\n", df);
        break;
    case 2:
        printf("\n(f(xi+h) - f(xi))/h\n");
        printf("\nEnter at what value of x you want to calculate derivative: \n");
        scanf(" %lf", &index);
        do
        {
            if (h<=0)
            {
                printf("\nYou cannot enter a value equal to 0 or a value less than 0.\n");
            }
            printf("\nEnter the h value: \n");
            scanf("%lf", &h);
        } while (h<=0);
        df = calculateForwardDifferentiation(h, &index ,functions,polynomialCount,exponentialCount,logarithmicCount,trigonometricCount,inverseTrigonometricCount);
        printf("\nResult df: %lf\n", df);
        break;    
    }
}

void simpsonMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    double lower, upper, stepSize, n;
    double integration = 0;
    int i, subInterval;
    printf("\nEnter the lower limit of integration: \n");
    scanf("%lf", &lower);
    printf("\nEnter the upper limit of integration: \n");
    scanf("%lf", &upper);
    do
    {
        if (subInterval<=0)
        {
            printf("\nYou can not enter a value smaller than 0!\n");
        }
        printf("\nEnter number of sub intervals: \n");
        scanf("%d", &subInterval);
    } while (subInterval<=0);
    
    stepSize = (upper- lower)/subInterval;
    integration = calculateFunction(&upper, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount) + calculateFunction(&lower, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    for (i = 1; i <= subInterval - 1; i++)
    {
        n = lower + i*stepSize;
        if (i%2==0){
            integration += 2*calculateFunction(&n, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        }
        else{
            integration += 4*calculateFunction(&n, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
        }
    }
    integration = integration * stepSize/3;
    printf("\nResult of integration is: %lf\n", integration);
}

void trapezoidalMethod(struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    double lower, upper, stepSize, n;
    double integration = 0;
    int i, subInterval;
    printf("\nEnter the lower limit of integration: \n");
    scanf("%lf", &lower);
    printf("\nEnter the upper limit of integration: \n");
    scanf("%lf", &upper);
    do
    {
        if (subInterval<=0)
        {
            printf("\nYou can not enter a value smaller than 0!\n");
        }
        printf("\nEnter number of sub intervals: \n");
        scanf("%d", &subInterval);
    } while (subInterval<=0);

    stepSize = (upper- lower)/subInterval;
    integration = calculateFunction(&upper, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount) + calculateFunction(&lower, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    for (i = 1; i <= subInterval - 1; i++)
    {
        n = lower + i*stepSize;
        integration = integration + (2*calculateFunction(&n, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount));
    }
    integration = integration * stepSize/2;
    printf("\nResult of integration is: %lf\n", integration);
}

void gregoryNewtonsInterpolation(){
    int inputCount,i,j,fact;
    double ax[MAX]={0};
    double ay[MAX][MAX]={0};
    double sum,h,x,coefficient;
    printf("\nPlease enter how many inputs you want to enter for the Gregory-Newton interpolation method.\n");
    scanf("%d", &inputCount);
    for (i = 0; i < inputCount; i++){
        printf("\nEnter the value of x%d\n",i);
        scanf("%lf",&ax[i]);
        printf("\nEnter value of y%d:\n", i);
        scanf("%lf",&ay[i][0]);
    }
    h = ax[1] - ax[0];
    printf("\nEnter the value of x for which the value of y is wanted:\n");
    scanf("%lf",&x);
    forwardDifferenceTable(ax,ay,inputCount);
    printForwardDifferenceTable(ax,ay,inputCount);
    sum = ay[0][0];
    for (i = 1; i < inputCount; i++){
        coefficient=1.0;
        fact = 1;
        for (j = 1; j <= i; j++){
            fact*=j;
        }
        for (j = 0; j < i; j++){
            coefficient*= ((x-ax[j])/h);
        }
        sum+= ((coefficient*ay[0][i])/fact);
    }
    printf("\nWhen x = %lf, corresponding y = %lf\n",x,sum);

}

void forwardDifferenceTable(double ax[MAX], double ay[MAX][MAX], int inputCount){
    int i,j;
    for (j = 1; j < inputCount; j++){
        for (i = 0; i < inputCount-j; i++){
            ay[i][j] = ay[i+1][j-1] - ay[i][j-1];
        }
    }
}

void printForwardDifferenceTable(double ax[MAX], double ay[MAX][MAX], int inputCount){
    int i,j;
    printf("\nThe forward difference table is:\n");
    for (i = 0; i < inputCount; i++){
        printf("\n");
        for (j = 0; j < inputCount - i; j++){
            printf("%lf\t",ay[i][j]);
        } 
    } 
}

void getMatrix(double Matrix[MAX][MAX], int *N){
    int i,j;
    printf("\nEnter the order of the square matrix: \n");
    scanf(" %d", &*N);
    for (i = 0; i < *N; i++)
    {
        for (j = 0; j < *N; j++)
        {
            printf("\nEnter the Matrix[%d][%d]: \n", i, j);
            scanf(" %lf", &Matrix[i][j]);
        }
    }
}

void getAugmentedMatrix(double Matrix[MAX][MAX], int *N){
    int i,j;
    printf("\nEnter the order of the matrix: \n");
    scanf(" %d", &*N);
    printf("\nEnter the elements of augmented matrix row-wise: \n");
    for (i = 0; i < *N; i++)
    {
        for (j = 0; j < *N+1; j++)
        {
            printf("\nEnter the Matrix[%d][%d]: \n", i, j);
            scanf(" %lf", &Matrix[i][j]);
        }
    }
}

void printMatrix(double Matrix[MAX][MAX], int N){
    int i,j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%3lf ", Matrix[i][j]);
        }
        printf("\n");
    }
}

void printAugmentedMatrix(double Matrix[MAX][MAX], int N){
    int i,j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N+1; j++)
        {
            printf("%3lf ", Matrix[i][j]);
        }
        printf("\n");
    }
}

void setIdentityMatrix(double identityMatrix[MAX][MAX], int *N){
    int i;
    for (i = 0; i < *N; i++)
    {
        identityMatrix[i][i] = 1;
    }
}

double calculateCentralDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    
    double index1,index2, f0, f1, f2, df;
    index1 = *index0 - h;
    index2 = *index0 + h;
    f0 = calculateFunction(index0, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    f1 = calculateFunction(&index1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    f2 = calculateFunction(&index2, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    df = (f2 - f1)/(2*h);
    return df;
}

double calculateBackwardDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    
    double index1, f0, f1, df;
    index1 = *index0 - h;
    f0 = calculateFunction(index0, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    f1 = calculateFunction(&index1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    df = (f0 - f1)/(h);
    return df;
}

double calculateForwardDifferentiation(double h,double *index0 ,struct functionTypes functions[],int *polynomialCount, int *exponentialCount, int *logarithmicCount, int *trigonometricCount, int *inverseTrigonometricCount){
    
    double index1, f0, f1, df;
    index1 = *index0 + h;
    f0 = calculateFunction(index0, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    f1 = calculateFunction(&index1, functions, polynomialCount, exponentialCount, logarithmicCount, trigonometricCount, inverseTrigonometricCount);
    df = (f1 - f0)/(h);
    return df;
}

char* getTrigName(struct functionTypes functions[], int i){
    switch (functions[i].trigonometric.trig)
    {
    case 0:
        return "sin";
    case 1:
        return "cos";
    case 2:
        return "tan";
    case 3:
        return "cot";
    }
}

char* getInverseTrigName(struct functionTypes functions[], int i){
    switch (functions[i].inverseTrigonometric.trig)
    {
    case 0:
        return "arcsin";
    case 1:
        return "arccos";
    case 2:
        return "arctan";
    case 3:
        return "arccot";
    }
}
