#include "include/FIR.h"

using namespace std;

int main(int argv, char *argc[])
{
    // cout << "Start of main function\n";
    int n = 1000;

    // Generating noisy data to be filtered
    float input[n];
    float filteredInput[n];

    // Generate the input values
    const float pi = 3.14159265358979;
    const float f = 2.5; // Hz
    for (int i = 0; i < n; i++)
    {
        float min = 0.0f;
        float max = 0.3f;
        float noise = min + ((float)rand() / (float)RAND_MAX) * (max - min);
        input[i] = (float)sin(2 * pi * f * i / n) + noise; // one cycle t=i/n=0 to 1
    }

    // FIR filter with circular buffer
    // Declaring the filter struct variable
    FIRFilter fir;

    // Initialise the filter coefficient (the weight)
    FIRFilter_init(&fir);

    // Calculating the filtered values
    for (int i = 0; i < n; i++)
    {
        FIRFilter_calc(&fir, input[i]);
        filteredInput[i] = fir.out;
    }

    // Display a new line for better formatting
    cout << endl;

    // Plotting with GNU Plot
    FILE *gnuplot = fopen("commands.p", "w");

    char title[200] = "";
    char xLabel[200] = "";
    char yLabel[200] = "";

    // Set the plot title, xlabel and ylabel
    sprintf(title, "Original and filtered samples");
    sprintf(xLabel, "Time");
    sprintf(yLabel, "Amplitude");

    fprintf(gnuplot, "set terminal wxt size 500, 400\n");
    fprintf(gnuplot, "set title '%s'\n", title);
    fprintf(gnuplot, "set xlabel '%s'\n", xLabel);
    fprintf(gnuplot, "set ylabel '%s'\n", yLabel);
    fprintf(gnuplot, "plot \'data.tmp\' title \'Data\'\n");

    // Plot the data
    fprintf(gnuplot, "plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot, "%d %lf\n", i, input[i]);
    }
    fprintf(gnuplot, "e\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(gnuplot, "%d %lf\n", i, filteredInput[i]);
    }
    fprintf(gnuplot, "e\n");
    fprintf(gnuplot, "replot\n");

    // Close the GNU plot piping
    fclose(gnuplot);


    cout << "Generated commands.p file!\n\n";
    
    return 0;
}