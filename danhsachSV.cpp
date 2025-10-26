#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char maSV[20];
    char hoTen[50];
    int tuoi;
    float diemTB;
} SinhVien;

void nhapDanhSach(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma sinh vien: ");
        scanf("%s", ds[i].maSV);
        getchar();
        printf("Ho ten: ");
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &ds[i].tuoi);
        printf("Diem trung binh: ");
        scanf("%f", &ds[i].diemTB);
    }
}

void xuatDanhSach(SinhVien ds[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s - Tuoi: %d - Diem TB: %.2f\n",
               i + 1, ds[i].maSV, ds[i].hoTen, ds[i].tuoi, ds[i].diemTB);
    }
}

void timDiemCaoNhat(SinhVien ds[], int n) {
    float max = ds[0].diemTB;
    int viTri = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTB > max) {
            max = ds[i].diemTB;
            viTri = i;
        }
    }
    printf("\nSinh vien co diem trung binh cao nhat:\n");
    printf("%s - %s - Tuoi: %d - Diem TB: %.2f\n",
           ds[viTri].maSV, ds[viTri].hoTen, ds[viTri].tuoi, ds[viTri].diemTB);
}

void sapXepGiamDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTB < ds[j].diemTB) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("\nDanh sach sau khi sap xep giam dan theo diem trung binh:\n");
    xuatDanhSach(ds, n);
}

int main() {
    int n;
    SinhVien danhSach[MAX];
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    nhapDanhSach(danhSach, n);
    xuatDanhSach(danhSach, n);
    timDiemCaoNhat(danhSach, n);
    sapXepGiamDan(danhSach, n);

    return 0;
}