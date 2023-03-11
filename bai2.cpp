#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int const MAX = 100;
typedef struct cuonsach {
    char masach[10];
    char tensach[256];
    char tentg[50];
    char loaisach[50];
    char years[5];
    float prices;
    int sl;
    float sum_of_books;
} cs;
void nhapsl(int &n) {
    printf("Nhap so luong cuon sach: ");
    scanf("%d", &n);
}
void delRow(char x[]) {
    size_t n = strlen(x);
    if (x[n - 1] == '\n')
        x[n - 1] = '\0';
}
void nhaptt(cs &x) {
    fflush(stdin);
    printf("\nNhap ma sach: "); fgets(x.masach, sizeof(x.masach), stdin); delRow(x.masach);
    // fflush(stdin);
    // printf("Nhap ten sach: "); fgets(x.tensach, sizeof(x.tensach), stdin); delRow(x.tensach);
    // printf("Nhap tac gia: "); fgets(x.tentg, sizeof(x.tentg), stdin); delRow(x.tentg);
    // printf("Nhap loai sach: "); fgets(x.loaisach, sizeof(x.loaisach), stdin); delRow(x.loaisach);
    // printf("Nhap nam xuat ban: "); fgets(x.years, sizeof(x.years), stdin); delRow(x.years);
    fflush(stdin);
    // printf("Nhap gia tien:"); scanf("%f", &x.prices);
    // printf("Nhap so luong:"); scanf("%d", &x.sl);
}
void xuat_tt_sach(cs x) {
    printf("\nMa sach: %s", x.masach);
    // printf("\nTen sach: %s", x.tensach);
    // printf("\nTen tac gia: %s", x.tentg);
    // printf("\nTen tac gia: %s", x.tentg);
    // printf("\nNam xuat ban: %s", x.years);
    // printf("\nGia tien: %f", x.prices);
    // printf("\nSo luong: %d", x.sl);

}
void nhap_ds_sach(cs a[], int n) {
    printf("==================\n");
    for(int i = 0; i < n; i++) {
        printf("NHAP DANH TT CUON SACH THU (%d)", i+ 1);
        nhaptt(a[i]);
    }
}
void adding_new_book(cs a[], int &n) {
    for(int i = 0; i < n; i++) {
        printf("\nNHAP CUON SACH MUON THEM");
        nhaptt(a[n]);
    }
    n++;
}
int sum_of_books(cs a[], int n) {
    int temp = 0;
    for(int i = 0; i < n; i++) { 
        temp += a[i].prices;
    }
    return temp;
}
void xuat_ds_sach(cs a[], int n) {
    printf("\nDANH SACH CUON SACH");
    for(int i = 0; i < n; i++) {
        xuat_tt_sach(a[i]);
        printf("\n==================\n");
    }
}
void swap(cs &a, cs &b)
{
    cs temp = a;
    a = b;
    b = temp;
}
void bbsort(cs a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (strcmp(a[j].masach, a[j+1].masach) > 0) {
                swap(a[j], a[j+1]);
            }
        }
    }
}
int main() {
    int n;
    cs a[MAX];
    nhapsl(n);
    nhap_ds_sach(a,n);
    // adding_new_book(a,n);
    bbsort(a,n);
    xuat_ds_sach(a,n);
    printf("%d", sum_of_books(a,n));
    return 0;
    // loi con me m roi
}