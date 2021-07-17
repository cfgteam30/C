// C++ program for implementation of KMP pattern searching
// algorithm
#include<iostream>
using namespace std;
#include<string.h>

void computeLPSArray(string pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt)
{
	int M = pat.length();
	int N = txt.length();

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];
    int comp = 0;

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
            comp++;
		}

		if (j == M) {
			printf("Found pattern at index %d \n", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    cout<<"Total number of comparisons : "<<comp<<"\n";
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
    for(int i=0;i<M;i++)
        cout<<i<<'\t';
    cout<<endl;
    for(int i=0;i<M;i++)
        cout<<lps[i]<<'\t';
    cout<<endl<<endl;
}

// Driver program to test above function
int main()
{
	string txt,pat;
    cout<<"Enter text\n";
    cin>>txt;
    cout<<"Enter pat\n";
    cin>>pat;

	KMPSearch(pat, txt);
	return 0;
}