/* Program to find row averages and column averages of numbers present in numbers.txt using heap memory.
*  Written by: Shreevathsa.
*  Date: 08-09-2019.
*/

#include<iostream>
#include<fstream>
#include<new>
#include<iomanip>
using namespace std;

void getFirstLine(ifstream& sfTextFile, int& Row, int& Column);
float** getTable(ifstream& sfTextFile, int Row, int Column);
float* rowAverage(float** table, int Row, int Column);
float* colAverage(float** table, int Row, int Column);
void printAverage(float** table, float* rowA, float* colA, int Row, int Column);
void printToFile(float** table, float* rowA, float* colA, int Row, int Column);


int main()
{   //Opening numbers.txt file.
    ifstream sfTextFile;
    sfTextFile.open("numbers.txt");
    if(!sfTextFile)
	{
		cerr << "Error 100 opening output";
		exit(100);
	}
    int Row;
    int Column;

   
    getFirstLine(sfTextFile, Row, Column);
    
  
    float** table = getTable(sfTextFile, Row, Column);

    
    float* rowA = rowAverage(table,Row, Column);
    float* colA = colAverage(table,Row,Column);

 
    printAverage(table, rowA, colA, Row, Column);

    printToFile( table, rowA, colA, Row, Column);

    sfTextFile.close();
    return 0;
}

//Getting the number of rows and column from the first line of the file.
void getFirstLine(ifstream& sfTextFile, int& Row, int& Column)
{   int getNum[2];
    for(int i = 0; i < 2; i++)
    {
        sfTextFile >> getNum[i];
    }
    Row = getNum[0];
    Column = getNum[1];
    return;
}

//Creating double pointer array.
float** getTable(ifstream& sfTextFile, int Row, int Column)
{
    float** table;
    table = new float* [Row];
    for(int r = 0; r < Row; r++)
    {   
        table[r] = new float[Column];
        
        for(int c = 0; c < Column; c++)
        {
            sfTextFile >> table[r][c];
        }
    }

    return table;
}

//Calculating the row and column averages.
float* rowAverage(float** table, int Row, int Column)
{   
    float sum;
    float* calcAve = new float [Row];
    for(int i = 0; i < Row; i++)
    {   sum = 0;
        for(int j = 0; j < Column; j++)
        {
            sum += table[i][j];
        }
        calcAve[i] = sum / Column;
    }
    return calcAve;
}

//Calculating the row and column averages.
float* colAverage(float** table, int Row, int Column)
{   
    float sum;
    float* calcAve = new float [Column];
    for(int i = 0; i < Column; i++)
    {   sum = 0;
        for(int j = 0; j < Row; j++)
        {
            sum += table[j][i];
        }
        calcAve[i] = sum / Row;
    }
    return calcAve;
}

//Printing the output to console.
void printAverage(float** table, float* rowA, float* colA, int Row, int Column)
{   cout << fixed;
    cout << "Row and Column Averages\n\n";
    for(int i = 0; i< Row; i++)
    {
        for(int j = 0; j < Column; j++)
        {
            cout << setw(7) << setprecision(2) << table[i][j] << " ";
        }
        cout << " | " << setw(6) << setprecision(2) << rowA[i] << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    for(int k = 0; k < Column; k++)
    {
        cout << setw(7) << setprecision(2) << colA[k] << " ";
    }
    cout << endl;
    return;
}

//Printing the output to average.txt file.
void printToFile(float** table, float* rowA, float* colA, int Row, int Column)
{
    ofstream printFile ;
    printFile.open("average.txt");
    if(!printFile)
	{
		cerr << "Error 100 opening output";
		exit(100);
	}
    printFile << "Row and Column Averages\n\n";
    cout << fixed;
    for(int i = 0; i< Row; i++)
    {
        for(int j = 0; j < Column; j++)
        {
            printFile << fixed << setw(7) << setprecision(2) << table[i][j] << " ";
        }
        printFile << fixed << " | " << setw(6) << setprecision(2) << rowA[i] << endl;
    }
    printFile << "------------------------------------------------------------------" << endl;
    for(int k = 0; k < Column; k++)
    {
        printFile << fixed << setw(7) << setprecision(2) << colA[k] << " ";
    }
    printFile << endl;
    printFile.close();
    return;

}