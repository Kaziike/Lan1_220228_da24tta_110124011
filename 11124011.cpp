/*
	110124011
	Pham Minh Chau
	DA24TTA
*/


#include <stdio.h>
#define TUAN 7 
/*tuan Co 7 ngay*/
void nhapthongtin(float thoigianhoc[]);
void hienthithongtin(float thoigianhoc[]);
float tinhtongthoigian(float thoigianhoc[]);
float tinhtrungbinh(float thoigianhoc[]);
void nghocnhieunhat(float thoigianhoc[], int *ngnhieunhat, int *ngitnhat);
int ngdatmtieu(float thoigianhoc[], float mtieu);
void xepgiam(float thoigianhoc[]);



int main() {
    float thoigianhoc[TUAN];

    nhapthongtin(thoigianhoc);
    hienthithongtin(thoigianhoc);

    float tongthoigian = tinhtongthoigian(thoigianhoc);
    float trungBinh = tinhtrungbinh(thoigianhoc);

    int ngnhieunhat, ngitnhat;
    nghocnhieunhat(thoigianhoc, &ngnhieunhat, &ngitnhat);

    printf("Tong so gio hoc trong tuan: %.1f gio\n", tongthoigian);
    printf("Trung binh moi ngay hoc: %.1f gio\n", trungBinh);
    printf("Ngay hoc nhieu nhat: %d\n", ngnhieunhat + 1);
    printf("Ngay hoc it nhat: %d\n", ngitnhat + 1);

    float mtieu;
    printf("Nhap muc tieu so gio muon dat duoc: ");
    scanf("%f", &mtieu);

    int ngdat = ngdatmtieu(thoigianhoc, mtieu);
    printf("So ngay dat hoac vuot muc tieu: %d\n", ngdat);
    printf("So ngay khong dat muc tieu: %d\n", TUAN - ngdat);

    xepgiam(thoigianhoc);
    printf("Thoi gian hoc sau khi sap xep giam dan:\n");
    hienthithongtin(thoigianhoc);

    return 0;
}

void nhapthongtin(float thoigianhoc[]) {
    for (int i = 0; i < TUAN; i++) {
        do {
            printf("Nhap thoi gian hoc ngay thu %d (gio): ", i + 1);
            scanf("%f",  &thoigianhoc[i]);
        } while (thoigianhoc[i] < 0 || thoigianhoc[i] > 15);
    }
}

void hienthithongtin(float thoigianhoc[]) {
    for (int i = 0; i < TUAN; i++) {
        printf("Ngay thu %d: %.1f gio\n", i + 1, thoigianhoc[i]);
    }
}

float tinhtongthoigian(float thoigianhoc[]) {
    float tong = 0;
    for (int i = 0; i < TUAN; i++) {
        tong += thoigianhoc[i];
    }
    return tong;
}

float tinhtrungbinh(float thoigianhoc[]) {
    return tinhtongthoigian(thoigianhoc) / TUAN;
}

void nghocnhieunhat(float thoigianhoc[], int *ngnhieunhat, int *ngitnhat) {
    *ngnhieunhat = 0;
    *ngitnhat = 0;
    for (int i = 1; i < TUAN; i++) {
        if (thoigianhoc[i] > thoigianhoc[*ngnhieunhat]) {
            *ngnhieunhat = i;
        }
        if (thoigianhoc[i] < thoigianhoc[*ngitnhat]) {
            *ngitnhat = i;
        }
    }
}

int ngdatmtieu(float thoigianhoc[], float mtieu) {
    int dem = 0;
    for (int i = 0; i < TUAN; i++) {
        if (thoigianhoc[i] >= mtieu) {
            dem++;
        }
    }
    return dem;
}

void xepgiam(float thoigianhoc[]) {
    for (int i = 0; i < TUAN - 1; i++) {
        for (int j = 0; j < TUAN - i - 1; j++) {
            if (thoigianhoc[j] < thoigianhoc[j + 1]) {
                float temp = thoigianhoc[j];
                thoigianhoc[j] = thoigianhoc[j + 1];
                thoigianhoc[j + 1] = temp;
            }
        }
    }
}

