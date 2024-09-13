#include <iostream>
#include <chrono>
#include "spans.h"
using std::cout;
using std::endl;

int main()
{
    using namespace std::chrono;

    // test case 1
    {
        double X1[] = {100, 80, 60, 70, 60, 75, 85};
        int size1 = sizeof(X1) / sizeof(X1[0]);
        int S1[size1];

        cout << "Test Case 1: \n";
        cout << "Input X1: ";
        for (int i = 0; i < size1; i++)
        {
            cout << X1[i] << " ";
        }
        cout << endl;

        // quadratic
        auto start = high_resolution_clock::now();
        calculateSpanQuadratic(X1, size1, S1);
        auto end = high_resolution_clock::now();
        auto duration_quadratic = duration_cast<nanoseconds>(end - start);
        cout << "Output S1 (Quadratic): ";
        for (int i = 0; i < size1; i++)
        {
            cout << S1[i] << " ";
        }
        cout << "\nExecution Time (Quadratic): " << duration_quadratic.count() << " ns\n";

        // linear
        start = high_resolution_clock::now();
        calculateSpanLinear(X1, size1, S1);
        end = high_resolution_clock::now();
        auto duration_linear = duration_cast<nanoseconds>(end - start);
        cout << "Output S1 (Linear): ";
        for (int i = 0; i < size1; i++)
        {
            cout << S1[i] << " ";
        }
        cout << "\nExecution Time (Linear): " << duration_linear.count() << " ns\n";

        // vector
        start = high_resolution_clock::now();
        calculateSpanVector(X1, size1, S1);
        end = high_resolution_clock::now();
        auto duration_vector = duration_cast<nanoseconds>(end - start);
        cout << "Output S1 (Vector): ";
        for (int i = 0; i < size1; i++)
        {
            cout << S1[i] << " ";
        }
        cout << "\nExecution Time (Vector): " << duration_vector.count() << " ns\n";
    }

    // test case 2
    {
        double X2[] = {10, 20, 30, 40, 50};
        int size2 = sizeof(X2) / sizeof(X2[0]);
        int S2[size2];

        cout << "\nTest Case 2: \n";
        cout << "Input X2: ";
        for (int i = 0; i < size2; i++)
        {
            cout << X2[i] << " ";
        }
        cout << endl;

        // quadratic
        auto start = high_resolution_clock::now();
        calculateSpanQuadratic(X2, size2, S2);
        auto end = high_resolution_clock::now();
        auto duration_quadratic = duration_cast<nanoseconds>(end - start);
        cout << "Output S2 (Quadratic): ";
        for (int i = 0; i < size2; i++)
        {
            cout << S2[i] << " ";
        }
        cout << "\nExecution Time (Quadratic): " << duration_quadratic.count() << " ns\n";

        // linear
        start = high_resolution_clock::now();
        calculateSpanLinear(X2, size2, S2);
        end = high_resolution_clock::now();
        auto duration_linear = duration_cast<nanoseconds>(end - start);
        cout << "Output S2 (Linear): ";
        for (int i = 0; i < size2; i++)
        {
            cout << S2[i] << " ";
        }
        cout << "\nExecution Time (Linear): " << duration_linear.count() << " ns\n";

        // vector
        start = high_resolution_clock::now();
        calculateSpanVector(X2, size2, S2);
        end = high_resolution_clock::now();
        auto duration_vector = duration_cast<nanoseconds>(end - start);
        cout << "Output S2 (Vector): ";
        for (int i = 0; i < size2; i++)
        {
            cout << S2[i] << " ";
        }
        cout << "\nExecution Time (Vector): " << duration_vector.count() << " ns\n";
    }
    // test case 3
    {
        double X3[] = {50, 40, 30, 20, 10};
        int size3 = sizeof(X3) / sizeof(X3[0]);
        int S3[size3];

        cout << "\nTest Case 3: \n";
        cout << "Input X3: ";
        for (int i = 0; i < size3; i++)
        {
            cout << X3[i] << " ";
        }
        cout << endl;

        // quadratic
        auto start = high_resolution_clock::now();
        calculateSpanQuadratic(X3, size3, S3);
        auto end = high_resolution_clock::now();
        auto duration_quadratic = duration_cast<nanoseconds>(end - start);
        cout << "Output S3 (Quadratic): ";
        for (int i = 0; i < size3; i++)
        {
            cout << S3[i] << " ";
        }
        cout << "\nExecution Time (Quadratic): " << duration_quadratic.count() << " ns\n";

        // linear
        start = high_resolution_clock::now();
        calculateSpanLinear(X3, size3, S3);
        end = high_resolution_clock::now();
        auto duration_linear = duration_cast<nanoseconds>(end - start);
        cout << "Output S3 (Linear): ";
        for (int i = 0; i < size3; i++)
        {
            cout << S3[i] << " ";
        }
        cout << "\nExecution Time (Linear): " << duration_linear.count() << " ns\n";

        // vector
        start = high_resolution_clock::now();
        calculateSpanVector(X3, size3, S3);
        end = high_resolution_clock::now();
        auto duration_vector = duration_cast<nanoseconds>(end - start);
        cout << "Output S3 (Vector): ";
        for (int i = 0; i < size3; i++)
        {
            cout << S3[i] << " ";
        }
        cout << "\nExecution Time (Vector): " << duration_vector.count() << " ns\n";
    }
    // test case 4
    {
        double X4[] = {10, 4, 5, 90, 120, 80};
        int size4 = sizeof(X4) / sizeof(X4[0]);
        int S4[size4];

        cout << "\nTest Case 4: \n";
        cout << "Input X4: ";
        for (int i = 0; i < size4; i++)
        {
            cout << X4[i] << " ";
        }
        cout << endl;

        // quadratic
        auto start = high_resolution_clock::now();
        calculateSpanQuadratic(X4, size4, S4);
        auto end = high_resolution_clock::now();
        auto duration_quadratic = duration_cast<nanoseconds>(end - start);
        cout << "Output S4 (Quadratic): ";
        for (int i = 0; i < size4; i++)
        {
            cout << S4[i] << " ";
        }
        cout << "\nExecution Time (Quadratic): " << duration_quadratic.count() << " ns\n";

        // linear
        start = high_resolution_clock::now();
        calculateSpanLinear(X4, size4, S4);
        end = high_resolution_clock::now();
        auto duration_linear = duration_cast<nanoseconds>(end - start);
        cout << "Output S4 (Linear): ";
        for (int i = 0; i < size4; i++)
        {
            cout << S4[i] << " ";
        }
        cout << "\nExecution Time (Linear): " << duration_linear.count() << " ns\n";

        // vector
        start = high_resolution_clock::now();
        calculateSpanVector(X4, size4, S4);
        end = high_resolution_clock::now();
        auto duration_vector = duration_cast<nanoseconds>(end - start);
        cout << "Output S4 (Vector): ";
        for (int i = 0; i < size4; i++)
        {
            cout << S4[i] << " ";
        }
        cout << "\nExecution Time (Vector): " << duration_vector.count() << " ns\n";
    }

    // test case with larger input to better see the timing differences
    const int size_large = 10000;
    double X_large[size_large];
    int S_large[size_large];

    // initialize X_large with random values or a specific pattern
    // for example, we can use an increasing sequence
    for (int i = 0; i < size_large; i++)
    {
        X_large[i] = i % 100; // repeating pattern to prevent monotonic increase
    }

    cout << "\nTest Case Large Input: \n";
    cout << "Input X_large: [Large array with " << size_large << " elements]\n";

    // quadratic
    auto start = high_resolution_clock::now();
    calculateSpanQuadratic(X_large, size_large, S_large);
    auto end = high_resolution_clock::now();
    auto duration_quadratic = duration_cast<milliseconds>(end - start);
    cout << "Execution Time (Quadratic): " << duration_quadratic.count() << " ms\n";

    // linear
    start = high_resolution_clock::now();
    calculateSpanLinear(X_large, size_large, S_large);
    end = high_resolution_clock::now();
    auto duration_linear = duration_cast<milliseconds>(end - start);
    cout << "Execution Time (Linear): " << duration_linear.count() << " ms\n";

    // vector
    start = high_resolution_clock::now();
    calculateSpanVector(X_large, size_large, S_large);
    end = high_resolution_clock::now();
    auto duration_vector = duration_cast<milliseconds>(end - start);
    cout << "Execution Time (Vector): " << duration_vector.count() << " ms\n";

    return 0;
}
