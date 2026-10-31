#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    int masach;
    char ten[50];
    int soluong;
    float giaban;
} sach;

void displayMenu() {
    printf("\n===== QUAN LY DAU SACH =====\n");
    printf("1. Them dau sach\n");
    printf("2. Hien thi danh sach dau sach\n");
    printf("3. Cap nhat dau sach theo ma\n");
    printf("4. Xoa dau sach theo ma\n");
    printf("5. Tim dau sach theo ten\n");
	printf("6. Thong ke kho hang\n");
    printf("0. Thoat\n");
    printf("Chon chuc nang: ");
}
int findStudent(sach a[], int n, int ma) {
    for (int i = 0; i < n; i++) {
       if (a[i].masach == ma) return i;
   }
    return -1;
}

void inputInfo(sach a[], int i) {
    getchar();
    printf("Nhap ten dau sach: ");
    fgets(a[i].ten, 50, stdin);
    a[i].ten[strcspn(a[i].ten, "\n")] = '\0';

    do {
        printf("Nhap so luong: ");
        scanf("%f", &a[i].giaban);
        if (a[i].giaban < 0)
            printf("so luong khong hop le\n");
    } while (a[i].giaban < 0);
    
    do {
        printf("Nhap gia ban: ");
        scanf("%f", &a[i].giaban);
        if (a[i].giaban < 0)
            printf("gia ban khong hop le\n");
    } while (a[i].giaban < 0);
}

void displayList(sach a[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("\n%-10s %-25s %-12s %-12s %-15s\n",
           "Ma", "Ho ten dau sach", "so luong", "gia ban", "thanh tien");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-25s %-12d %-12.2f ",
               a[i].masach, a[i].ten, a[i].soluong, a[i].giaban);
        printf("\n");
    }
}
void addStudent(sach a[], int *n) {
    if (*n == MAX_SIZE) {
        printf("Danh sach da day\n");
        return;
    }

    int ma;
    printf("Nhap ma: ");
    scanf("%d", &ma);

    if (ma <= 0) {
        printf("Ma khong hop le\n");
        return;
    }

    if (findStudent(a, *n, ma) != -1) {
        printf("Ma da ton tai\n");
        return;
    }

    a[*n].masach = ma;
    inputInfo(a, *n);
    (*n)++;

    printf("Them dau sach thanh cong\n");
}

void updateStudent(sach a[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma can cap nhat: ");
    scanf("%d", &ma);

    int i = findStudent(a, n, ma);
    if (i == -1) {
        printf("Khong tim thay dau sach\n");
        return;
    }

    inputInfo(a, i);
    printf("Cap nhat thanh cong\n");
}
void deleteStudent(sach a[], int *n) {
    if (*n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma can xoa: ");
    scanf("%d", &ma);

    int i = findStudent(a, *n, ma);
    if (i == -1) {
        printf("Khong tim thay ma\n");
        return;
    }

    for (int j = i; j < *n - 1; j++)
        a[j] = a[j + 1];

    (*n)--;
    printf("Xoa thanh cong\n");
}

void searchStudent(sach a[], int n) {
    char ten[50];
    int found = 0;

    getchar();
    printf("Nhap ten can tim: ");
    fgets(ten, 50, stdin);
    ten[strcspn(ten, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strstr(a[i].ten, ten) != NULL) {
            if (found == 0)
                printf("\n%-10s %-25s %-12s %-12s %-15s\n",
                       "Ma", "ten", "so luong", "gia ban", "thanh tien");

            printf("%-10d %-25s %-12d %-12.2f ",
                   a[i].masach, a[i].ten, a[i].soluong, a[i].giaban);

        }
    }

    if (found == 0) printf("Khong tim thay sinh vien\n");
}
int main() {
    sach students[MAX_SIZE];
    int currentLength = 0;
    int userChoose;

    while (1) {
        displayMenu();
        scanf("%d", &userChoose);

        switch (userChoose) {
            case 1:
                addStudent(students, &currentLength);
                break;
            case 2:
                displayList(students, currentLength);
                break;
            case 3:
                updateStudent(students, currentLength);
                break;
            case 4:
                deleteStudent(students, &currentLength);
                break;
            case 5:
                searchStudent(students, currentLength);
                break;
            case 0:
                printf("Tam biet!\n");
                return 0;
            default:
                printf("Lua chon khong hop le\n");
        }
    }

    return 0;
}
