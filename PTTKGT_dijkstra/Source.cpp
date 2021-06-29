#include <iostream>
#include <stdlib.h>
#define SIZE 5//nhap so dinh

using namespace std;

int main() {
	int a[SIZE][SIZE];
	int d[SIZE];
	int v[SIZE];
	int temp, minindex, min;  //khoi tao bien
	int begin_index, end_index; //dinh dau va dinh cuoi
	//Diem dau diem cuoi muon tim duong di ngan nhat
	cout << "Nhap dinh dau va dinh cuoi muon tim duong di ngan nhat:" << endl;
	cin >> begin_index >> end_index;
	--begin_index;
	--end_index;

	//vong lap khoang cach
	for (int i = 0; i < SIZE; i++) {
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			cout << "Khoang cach " << i + 1 << "-" << j + 1 << ": ";
			cin >> temp;
			a[i][j] = temp;
			a[j][i] = temp;
		}
	}

	cout << "-------KET QUA-------" << endl;
	//xuat ma tran
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		d[i] = 10000;
		v[i] = 1;
	}

	d[begin_index] = 0;

	//tim khoang cach ngan nhat giua cac dinh 
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++) {
			if ((v[i] == 1) && (d[i] < min)) {
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000) {
			for (int i = 0; i < SIZE; i++) {
				if (a[minindex][i] > 0) {
					temp = min + a[minindex][i];
					if (temp < d[i]) {
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	}

	while (minindex < 10000);
	cout << "\nKhoang cach ngan giua cac dinh ";

	for (int i = 0; i < SIZE; i++)
		cout << d[i] << " ";

	int ver[SIZE];
	int end = end_index;
	ver[0] = end + 1;
	int k = 1;
	int weight = d[end];

	//tim duong di ngan nhat
	while (end != begin_index) {
		for (int i = 0; i < SIZE; i++)
			if (a[i][end] != 0) {
				int temp = weight - a[i][end];
				if (temp == d[i]) {
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
	}

	cout << "\nDuong di ngan nhat den " << end_index + 1 << " la: ";

	for (int i = k - 1; i >= 0; i--)
		cout << ver[i] << " ";
	return 0;
}