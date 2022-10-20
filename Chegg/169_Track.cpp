#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Input of total number of tracks and total minute required to reach the ground
    int n, k;
    cin >> n >> k;
    // total hours
    int totalHrs = 6;
    // get total minutes of 6 hours
    int totalMinutes = 6 * 60;
    // minus the k minutes from totalMinutes
    // because k minutes required to reach the ground
    // so in this k minutes no practice happened
    totalMinutes -= (k);
    // get totalTracks covered by runner
    int countTracks = 0;
    // Iterate track from 1 to n
    for (int i = 0; i < n; i++)
    {
        // get total minutes required for the ith track according to the condition
        int required_min_for_ith_Track = pow(2, i);
        // check required minutes is less than or equal to totalMinutes or not
        if (required_min_for_ith_Track <= totalMinutes)
        {
            // increment the count
            countTracks++;
            // minues the required minutes from totalMinues
            totalMinutes -= required_min_for_ith_Track;
        }
        // else break runner can't cover anymore track
        else
        {
            break;
        }
    }
    // Display totalTracks convered by the runner
    cout << countTracks << endl;
    return 0;
}
// 20 30
// 0- 1 = 169
// 1- 2= 167
// 2 - 4= 163
// 3- 8 = 155