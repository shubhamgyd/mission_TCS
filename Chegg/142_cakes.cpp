#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // get 3 radii input
    double radius1, radius2, radius3;
    cout << "Enter 3 radii values: ";
    cin >> radius1 >> radius2 >> radius3;

    // get 3 height input
    double height1, height2, height3;
    cout << "Enter 3 height values: ";
    cin >> height1 >> height2 >> height3;

    // get slices for each cake
    int slices1, slices2, slices3;
    cout << "Enter the number of slices for each: ";
    cin >> slices1 >> slices2 >> slices3;

    // to store the volume of each cake
    double volume1, volume2, volume3;

    // pie value
    double pie = 3.14;
    // formula : pie*radiud*raius*height

    // get volume of cake1
    volume1 = pie * radius1 * radius1 * height1;
    // get volume of cake2

    volume2 = pie * radius2 * radius2 * height2;
    // get volume of cake3
    volume3 = pie * radius3 * radius3 * height3;

    // get volume per slice
    double volumePerSlice1, volumePerSlice2, volumePerSlice3;
    // volume for per slices for cake1
    // to get it divide volume by slices
    volumePerSlice1 = volume1 / (slices1 * 1.0);

    // volume for per slices for cake2
    volumePerSlice2 = volume2 / (slices2 * 1.0);

    // volume for per slices for cake2
    volumePerSlice3 = volume3 / (slices3 * 1.0);

    // if all cakes have same volume per slices
    if (volumePerSlice1 == volumePerSlice2 and volumePerSlice2 == volumePerSlice3)
    {
        cout << "Error. You entered the same volume per slice 3 times." << endl;
        return 0;
    }

    // if cake1's slice volume is lesser than cake2's and cake3's
    if (volumePerSlice1 <= volumePerSlice2 and volumePerSlice1 <= volumePerSlice3)
    {
        // print cake1 info
        cout << "cake1: " << fixed << setprecision(4) << volumePerSlice1 << ", ";

        // if cake2's volume is lesser than cake3's
        if (volumePerSlice2 <= volumePerSlice3)
        {
            cout << "cake2: " << fixed << setprecision(4) << volumePerSlice2 << ", ";
            cout << "cake3: " << fixed << setprecision(4) << volumePerSlice3 << " ";
        }
        // else cake3's is lesser than cake'2
        else
        {
            cout << "cake3: " << fixed << setprecision(4) << volumePerSlice3 << ", ";
            cout << "cake2: " << fixed << setprecision(4) << volumePerSlice2 << " ";
        }
    }

    // if cake2's slice volume is lesser than cake1's and cake3's
    else if (volumePerSlice2 <= volumePerSlice2 and volumePerSlice2 <= volumePerSlice3)
    {
        cout << "cake2: " << fixed << setprecision(4) << volumePerSlice2 << ", ";
        // if cake1's volume is lesser than cake3's
        if (volumePerSlice1 <= volumePerSlice3)
        {
            cout << "cake1: " << fixed << setprecision(4) << volumePerSlice1 << ", ";
            cout << "cake3: " << fixed << setprecision(4) << volumePerSlice3 << " ";
        }
        // else cake3's is lesser than cake'1
        else
        {
            cout << "cake3: " << fixed << setprecision(4) << volumePerSlice3 << ", ";
            cout << "cake1: " << fixed << setprecision(4) << volumePerSlice1 << " ";
        }
    }
    // if cake3's slice volume is lesser than cake1's and cake2's
    else
    {
        cout << "cake3: " << fixed << setprecision(4) << volumePerSlice3 << ", ";
        // if cake1's volume is lesser than cake2's
        if (volumePerSlice1 <= volumePerSlice2)
        {
            cout << "cake1: " << fixed << setprecision(4) << volumePerSlice1 << ", ";
            cout << "cake2: " << fixed << setprecision(4) << volumePerSlice2 << " ";
        }
        // else cake2's is lesser than cake'1
        else
        {
            cout << "cake2: " << fixed << setprecision(4) << volumePerSlice2 << ", ";
            cout << "cake1: " << fixed << setprecision(4) << volumePerSlice1 << " ";
        }
    }
    return 0;
}