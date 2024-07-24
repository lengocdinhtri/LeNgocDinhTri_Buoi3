#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void TaoMaTran(int a[MAX][MAX], int m, int n, int k) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (k + 1);
		}
	}
}

void XuatMaTran(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void TinhTongTungDong(int a[MAX][MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		int tong = 0;
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		printf("Tong dong %d: %d\n", i, tong);
	}
}

void PhanTuLonNhatTungCot(int a[MAX][MAX], int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat cot %d: %d\n", j, max);
	}
}

void XuatDuongBien(int a[MAX][MAX], int m, int n) {
	// Duong bien tren
	for (int j = 0; j < n; j++) {
		printf("%d\t", a[0][j]);
	}
	printf("\n");

	// Duong bien duoi
	for (int j = 0; j < n; j++) {
		printf("%d\t", a[m - 1][j]);
	}
	printf("\n");

	// Duong bien trai
	for (int i = 0; i < m; i++) {
		printf("%d\t", a[i][0]);
	}
	printf("\n");

	// Duong bien phai
	for (int i = 0; i < m; i++) {
		printf("%d\t", a[i][n - 1]);
	}
	printf("\n");
}

int LaCucDai(int a[MAX][MAX], int m, int n, int i, int j) {
	int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
	for (int k = 0; k < 8; k++) {
		int ni = i + dx[k], nj = j + dy[k];
		if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j]) {
			return 0;
		}
	}
	return 1;
}

void XuatCucDai(int a[MAX][MAX], int m, int n) {
	printf("Cac phan tu cuc dai:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (LaCucDai(a, m, n, i, j)) {
				printf("%d\t", a[i][j]);
			}
		}
	}
	printf("\n");
}
int main() {
	int m, n, k;
	int a[MAX][MAX];

	printf("Nhap so dong: ");
	scanf("%d", &m);
	printf("Nhap so cot: ");
	scanf("%d", &n);
	printf("Nhap gia tri k de tao cac so ngau nhien tu 0 den k: ");
	scanf("%d", &k);

	TaoMaTran(a, m, n, k);

	printf("Ma tran ngau nhien:\n");
	XuatMaTran(a, m, n);

	printf("\nTong gia tri tung dong:\n");
	TinhTongTungDong(a, m, n);

	printf("\nCac phan tu thuoc cac duong bien:\n");
	XuatDuongBien(a, m, n);

	XuatCucDai(a, m, n);


	return 0;
}
