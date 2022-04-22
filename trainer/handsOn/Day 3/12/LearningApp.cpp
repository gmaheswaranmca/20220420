/*
#include <iostream>
using namespace std;


int main()
{
	int N = 10;
	for (int I = 1; I <= N; I++) {
		cout << I << " ";
	}

	return 0;
}

//==>
*/

#include <iostream>
using namespace std;

void printNatural(int& N, int I) {
	if (I <= N) {
		
		cout << I << " ";

		printNatural(N, I+1);

		
	}
}

/*
pN(N,I) N=10,I=1 ^1					from main 
	   pN(N=10,I+1) N=10,I=2		from r1 ^ 2
			pN(N=10,I+1) N=10,I=3	from r2 ^ 3
				pN(N=10,I+1) N=10,I=4			R3 ^ 4
					pN(N=10,I+1) N=10,I=5		R4 ^ 5
						pN(N=10,I+1) N=10,I=6	r5 ^ 6
							pN(N=10,I+1) N=10,I=7	r6	^ 7
								pN(N=10,I+1) N=10,I=8	r7 ^ 8
									pN(N=10,I+1) N=10,I=9	r8 ^9
										pN(N=10,I+1) N=10,I=10	r9 ^10
											pN(N=10,I+1) N=10,I=11 
*/
void printNaturalReverse(int& N, int I) {
	if (I <= N) {


		printNaturalReverse(N, I + 1);

		cout << I << " ";
	}
}

int main()
{
	int N = 10;
	
	printNatural(N, 1);
	cout << endl;
	printNaturalReverse(N, 1);
	return 0;
}
