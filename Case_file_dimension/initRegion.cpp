#include <iostream>
//#include <random>
#include <fstream>
using namespace std;

int main()
{

	ofstream outphi;
	outphi.open ("0/phiInitial"); //opening output file
	ofstream outT;
	outT.open ("0/TInitial"); //opening output file
	ofstream outpsi;
	outpsi.open ("0/psiInitial"); //opening output file
	int numcell = 200;
	double phi[numcell*numcell], T[numcell*numcell], psi[numcell*numcell];
	fill_n(phi, numcell*numcell, 0);
	fill_n(T, numcell*numcell, 1728);
	fill_n(psi, numcell*numcell, 0);
	for (int i = 50; i < 71; ++i) {
		for (int j = 75; j < 126; ++j) {
            phi[i*numcell + j] = 1;
		}
	}
	for (int i = 50; i < 151; ++i) {
		for (int j = 75; j < 126; ++j) {
            T[i*numcell + j] = 1589.76; //0.92;
            psi[i*numcell + j] = 1;
		}
	}

	/*if (!outphi) {
		cout << "No such output file" << endl;
	}
	else {*/
		cout << "Printing values" << endl;
		outphi << "internalField   nonuniform List<scalar>\n" << numcell*numcell << "\n(" << endl;
		outT << "internalField   nonuniform List<scalar>\n" << numcell*numcell << "\n(" << endl;
		outpsi << "internalField   nonuniform List<scalar>\n" << numcell*numcell << "\n(" << endl;
		for (int i = 0; i < numcell; ++i) {
			for (int j = 0; j < numcell; ++j) {
                outphi << phi[i*numcell + j] << endl;
                outT << T[i*numcell + j] << endl;
                outpsi << psi[i*numcell + j] << endl;
			}
		}
		outphi << ")\n;" << endl;
		outT << ")\n;" << endl;
		outpsi << ")\n;" << endl;
	//}
	outphi.close();
	outT.close();
	outpsi.close();

	return 0;
}
