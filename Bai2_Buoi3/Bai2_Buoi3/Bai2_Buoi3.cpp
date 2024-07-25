#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TaoMaTran(int n, int **a) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100; // Giá trị ngẫu nhiên từ 0 đến 99
		}
	}
}

void XuatMaTran(int n, int **a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}

void XuatDuongCheoChinh(int n, int **a) {
	printf("Cac phan tu tren duong cheo chinh: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

int main() {
	int n;
	printf("Nhap cap cua ma tran (n >= 5): ");
	scanf("%d", &n);

	if (n < 5) {
		printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
		return 1;
	}

	int **a = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		a[i] = (int *)malloc(n * sizeof(int));
	}

	TaoMaTran(n, a);

	printf("Ma tran ngau nhien:\n");
	XuatMaTran(n, a);

	XuatDuongCheoChinh(n, a);

	return 0;
}
