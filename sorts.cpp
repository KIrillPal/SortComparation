#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int t = 0;
void qsort(int* A, int l, int r) {
	if (r - l + 1 == 2) {
		if (A[l] > A[r]) {
			swap(A[l], A[r]);
			t += 3;
		}
		t++;
	}
	else if (r - l + 1 > 2) {
		//cout << " Получил "<< r-l+1 << ":";
		//for (int i = l; i < r+1; i++)
		//cout << " " << A[i];
		int lo = l, hi = r, piv = A[l + (r - l) / 2];
		t++;
		while (lo <= hi) {
			//cout << " в " << lo << " " << hi << " ";
			while (A[lo] < piv) lo++;
			while (A[hi] > piv) hi--;
			t += 2;
			if (lo <= hi) {
				swap(A[lo], A[hi]);
				lo++;
				hi--;
				t += 3;
			}
		}
		//cout << endl << "bnd = " << bnd << endl;
		qsort(A, l, hi);
		qsort(A, hi + 1, r);
	}
}

void merge_sort(int* a, int* b, int l, int r, bool reversed) {
	if (r - l + 1 == 2)
		if (!reversed) {
			if (a[l] <= a[r]) {
				b[l] = a[l];
				b[r] = a[r];
			}
			else {
				b[r] = a[l];
				b[l] = a[r];
			}
			t += 5;
		}
		else {
			if (b[l] > b[r])
				swap(b[l], b[r]);
			t += 4;
		}
	else if (r - l + 1 > 2) {
		int mid = (l + (r - l) / 2);
		//cout << "Вошел" << endl;
		int v1 = l, v2 = mid + 1, v = l;
		merge_sort(b, a, l, mid, !reversed);
		merge_sort(b, a, mid + 1, r, !reversed);
		while (v1 <= mid || v2 <= r) {
			if ((v1 <= mid && a[v1] <= a[v2]) || (v1 <= mid && v2 > r)) {
				b[v] = a[v1];
				v1++;
			}
			else if (v2 <= r) {
				b[v] = a[v2];
				v2++;
			}
			t += 2;
			v++;
		}
	}
	else if (!reversed) { b[l] = a[l]; t++; }
}


int main() {
	for (int i = 0; i < 0; i++)
		int k = rand();
	for (int n = 64; n < pow(2, 24); n *= 4) {
		cout << endl << endl << n << " элем." << endl << endl;
		for (int i = 0; i < 7; i++) {
			int* arr1 = new int[n];
			int* arr2 = new int[n];
			int* arr3 = new int[n];
			//arr2 =new int[n],
			//arr3 =new int[n];
			//cout<<" Массив:";
			//srand(0);

			for (int i = 0; i < n; i++) {
				arr1[i] = int(rand());
				arr2[i] = arr1[i];
				//cin » arr[i];
				//cout << " " << arr1[i];
			}
			//cout << endl << endl << " Сортировка..." << endl;
			auto first = clock();
			t = 0;
			qsort(arr1, 0, n - 1);
			cout << i << ". qsort: " <<(clock() - first) << " " << t << endl;
			first = clock(); t = 0;
			merge_sort(arr2, arr3, 0, n - 1, false);
			cout << i << ". merge: " <<(clock() - first) << " " << t << endl << endl;
			//cout << endl << " Массив 1:";
			//for (int i=0; i<n; i++) {
			//cout << " " << arr1[i];
			//}
			//cout << endl << endl << " Массив 2:";
			//for (int i=0; i<n; i++) {
			//cout << " " << arr3[i];
			//}
			//cout << endl << endl << endl;
		}
	}
}