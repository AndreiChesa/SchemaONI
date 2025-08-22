#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

ifstream f("schema.in");	
ofstream g("schema.out");

const int NMAX = 2005;
const int GMAX = 5005;

int n, gmax;
bool a[NMAX][GMAX];
int values[NMAX];
int sume[NMAX];

set<int> s;

int main()
{
	f >> n >> gmax;

	for (int i = 1; i <= n; i++)
	{
		f >> values[i];
	}

    sort(values + 1, values + n + 1, greater<int>());

    for (int i = n; i >= 1; i--) {
		sume[i] = sume[i + 1] + values[i];
	}


    int rez = gmax - sume[1];

    a[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= gmax; j++) {
            if (j - values[i] >= 0)
            {
                a[i][j] |= a[i - 1][j - values[i]];
            }
            a[i][j] |= a[i - 1][j];
        }

        //Suma elementelor mai mici decat i
        int ssmall = sume[i + 1];

        for (int j = 0; j <= gmax; j++) {
            int stotal = gmax - ssmall - j;
            if (0 <= stotal && stotal < values[i] && a[i - 1][j] && stotal > rez)
                rez = max(rez, stotal);
        }
    }

    g << rez;
    int curent = 0;
    int maxDiff = 0;
}