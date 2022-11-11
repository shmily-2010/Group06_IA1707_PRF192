#include <stdio.h>
#include <string.h>

struct SinhVien;
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();

struct HoTen {
	char ho[20];
	char dem[21];
	char ten[20];
};

struct DiemMH {
	float toan;
	float van;
	float anh;
	float tbc;
};

struct SinhVien {
	int ma;
	struct HoTen hoVaTen;
	int tuoi;
	char gioiTinh[10];
	struct DiemMH diem;
};

void nhapDiem(struct DiemMH* diem) {
	printf("Toan: ");
	scanf("%f", &diem->toan);
	printf("Van: ");
	scanf("%f", &diem->van);
	printf("Anh: ");
	scanf("%f", &diem->anh);
	diem->tbc = (diem->toan + diem->van + diem->anh) / 3;
}

void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}

struct SinhVien nhapSV() {
	struct SinhVien sv;
	printf("Nhap ma: ");
	scanf("%d", &sv.ma);
	nhapHoTen(&sv.hoVaTen);
	printf("Tuoi: ");
	scanf("%d", &sv.tuoi);
	printf("Gioi tinh: ");
	scanf("%s", sv.gioiTinh);
	nhapDiem(&sv.diem);
	return sv;
}

void hienThiTTSV(struct SinhVien sv) {
	printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
	sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
}
struct SinhVien timTheoTen(struct SinhVien* ds, int slsv) {
	char ten[20];
	struct SinhVien sv;
	int a;
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
			sv = ds[i];
			timSV = 1;
			
		}
	}

	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
	return sv;
}


void ghiFile(struct SinhVien* ds, int slsv) {
	getchar();
	char fName[26];
	FILE* fOut = fopen("SV2022.dat", "r+");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
	}
	printf("Ghi thanh cong\n");
	fclose(fOut);
}
void ghiFile1(struct SinhVien* ds, int slsv) {
	int i;
	getchar();
	char fName[26];
	FILE* fOut = fopen("out.txt", "a");

	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.tuoi, sv.gioiTinh,
		sv.diem.toan, sv.diem.van, sv.diem.anh, sv.diem.tbc);
	}
	fclose(fOut);
}

void docFile1(struct SinhVien* ds, int* slsv) {
	FILE* fOut = fopen("SV2021.dat", "a+");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SinhVien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, &sv.tuoi, sv.gioiTinh,
			&sv.diem.toan, &sv.diem.van, &sv.diem.anh, &sv.diem.tbc);
			
			ds[i++] = sv;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsv = i;
}
void docFile2(struct SinhVien* ds, int* slsv) {
	FILE* fOut = fopen("SV2022.dat", "a+");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SinhVien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&sv.ma, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, &sv.tuoi, sv.gioiTinh,
			&sv.diem.toan, &sv.diem.van, &sv.diem.anh, &sv.diem.tbc);
			
			ds[i++] = sv;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsv = i;
}

void hienThiTenCot() {
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
		"Ma SV", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", 
		"Diem Toan", "Diem Van", "Diem Anh", "Diem TBC");
}

void hienThiDSSV(struct SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}

int main() {
	struct SinhVien dssv[100];
	struct SinhVien dssv1[100];
	int slsv = 0,slsv1=0;
	int luaChon;
	int i;				
	do {
		printf("=============== MENU ===============");		
		printf("\n1. Hien thi danh sach sinh vien.");
		printf("\n2. Them Sinh vien vao danh sach.");
		printf("\n3. Tim sinh vien theo ten.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		
		switch(luaChon) {
			case 0:
				break;
			case 1:
				docFile1(dssv, &slsv);
				printf("DANH SACH SINH VIEN 2021:\n");
				hienThiDSSV(dssv, slsv);
				break;
			case 2:
				sv = nhapSV();
				dssv[slsv++] = sv;
				ghiFile(dssv, slsv);
				break;
			case 3:
				docFile2(dssv, &slsv);
				sv=timTheoTen(dssv, slsv);
				dssv1[slsv1++] = sv;
				ghiFile1(dssv1, slsv1);
				break;

			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}
