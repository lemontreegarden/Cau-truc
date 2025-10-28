#include<stdio.h>
#include<string.h>

struct SinhVien {
    char maSV[20];
    char hoTen[50];
    char ngaySinh[20];
    int tuoi;
    float diemTB;
};

void nhap1SV(struct SinhVien *sv) {
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0';

    printf("Nhap ngay sinh: ");
    fgets(sv->ngaySinh, sizeof(sv->ngaySinh), stdin);
    sv->ngaySinh[strcspn(sv->ngaySinh, "\n")] = '\0';

    printf("Nhap ma SV: ");
    fgets(sv->maSV, sizeof(sv->maSV), stdin);
    sv->maSV[strcspn(sv->maSV, "\n")] = '\0';

    printf("Nhap diem TB: ");
    scanf("%f", &sv->diemTB);
    while (getchar() != '\n');
}

void nhapDanhSach(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);
        nhap1SV(&ds[i]);
    }
}

void xuat1SV(struct SinhVien sv) {
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Ngay sinh: %s\n", sv.ngaySinh);
    printf("Ma SV: %s\n", sv.maSV);
    printf("Diem TB: %.2f\n", sv.diemTB);
}

void xuatDanhSach(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        xuat1SV(ds[i]);
    }
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    struct SinhVien ds[100];
    nhapDanhSach(ds, n);

    printf("\n--- Danh sach sinh vien ---\n");
    xuatDanhSach(ds, n);

    return 0;
}