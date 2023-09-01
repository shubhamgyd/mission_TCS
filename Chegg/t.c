#include <stdio.h>

// Structures
typedef struct
{
    float real;
    float imag;
} complex;

// Function to read the real and imaginary part of a fraction
complex read_complex()
{
    complex z;
    printf("Enter the real and imaginary parts of the fraction: ");
    scanf("%f%f", &z.real, &z.imag);
    return z;
}

// Here is the division of complex numbers
complex divide_complex(complex z1, complex z2)
{
    complex z;
    float denominator = z2.real * z2.real + z2.imag * z2.imag;
    z.real = (z1.real * z2.real + z1.imag * z2.imag) / denominator;
    z.imag = (z2.real * z1.imag - z1.real * z2.imag) / denominator;
    return z;
}

int main()
{
    // Read z1
    complex z1 = read_complex();
    // Readz2
    complex z2 = read_complex();
    // Get result
    complex z = divide_complex(z1, z2);
    // display result
    printf("The result of the division is: %.1f + %.1fi\n", z.real, z.imag);
    return 0;
}
