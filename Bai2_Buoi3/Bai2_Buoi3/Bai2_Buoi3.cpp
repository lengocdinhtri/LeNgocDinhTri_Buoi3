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

void XuatDuongCheoSongSong(int n, int **a) {
	printf("Cac phan tu tren cac duong cheo song song voi duong cheo chinh: \n");
	for (int d = 1; d < n; d++) {
		// Duong cheo tren duong cheo chinh
		for (int i = 0; i < n - d; i++) {
			printf("%d ", a[i][i + d]);
		}
		printf("\n");
		// Duong cheo duoi duong cheo chinh
		for (int i = 0; i < n - d; i++) {
			printf("%d ", a[i + d][i]);
		}
		printf("\n");
	}
}

int TimMaxTamGiacTren(int n, int **a) {
	int max = a[0][1]; // Bắt đầu từ phần tử trên đường chéo chính
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void SapXepZicZac(int n, int **a) {
	int *temp = (int *)malloc(n * n * sizeof(int));
	int index = 0;

	// Chuyển ma trận thành mảng 1 chiều
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[index++] = a[i][j];
		}
	}

	// Sắp xếp mảng 1 chiều
	for (int i = 0; i < n * n - 1; i++) {
		for (int j = i + 1; j < n * n; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Chuyển mảng 1 chiều trở lại ma trận theo kiểu zic-zac
	index = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[index++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = temp[index++];
			}
		}
	}

	free(temp);
}

void SapXepDuongCheoChinh(int n, int **a) {
	int *temp = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		temp[i] = a[i][i];
	}

	// Sắp xếp mảng 1 chiều
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Gán lại các giá trị đã sắp xếp vào đường chéo chính
	for (int i = 0; i < n; i++) {
		a[i][i] = temp[i];
	}

	free(temp);
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

	XuatDuongCheoSongSong(n, a);

	int max = TimMaxTamGiacTren(n, a);
	printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", max);

	SapXepZicZac(n, a);
	printf("Ma tran sau khi sap xep zic-zac:\n");
	XuatMaTran(n, a);

	SapXepDuongCheoChinh(n, a);
	printf("Ma tran sau khi sap xep duong cheo chinh tang dan:\n");
	XuatMaTran(n, a);

	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);

	return 0;
}
