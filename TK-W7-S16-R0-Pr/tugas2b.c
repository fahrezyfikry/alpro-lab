// Group 2:
// 2802658250 - Hasbi Rajab Assadiqi
// 2802669746 - Yosua Maranatha Siahaan
// 2802663931 - Septia Dini Rahayu
// 2802658263 - Fikry Fahrezy Ramadhan
// 2802680225 - Ranidya Putri Hantari

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// use `fgets` instead of `scanf` to handle input with whitespace character
// https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
void readstr(char *str, const int size) {
    fgets(str, size, stdin);
    // remove a newline character from the end of the string, if any
    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n')) {
        str[strlen(str) - 1] = '\0';
    }
}

void readint(int *num, const int len) {
    char input[len];
    char *endptr;
    fgets(input, (int)sizeof(input), stdin);
    // clang recommendation: use `strtol` to convert string to integer for better error handling
    int base = 10;
    *num = (int)strtol(input, &endptr, base);
}

// Define the array longer to provide space for null terminator \0
typedef char bracket[5];

double get_salary_by_bracket(bracket bracket_type) {
    if (strcmp(bracket_type, "D1") == 0) {
        return 2500000;
    }

    if (strcmp(bracket_type, "D2") == 0) {
        return 2000000;
    }

    if (strcmp(bracket_type, "D3") == 0) {
        return 1500000;
    }

    return -1;
}

double get_overtime_hour_payment_by_bracket(bracket bracket_type) {
    if (strcmp(bracket_type, "D1") == 0) {
        return 10000;
    }

    if (strcmp(bracket_type, "D2") == 0) {
        return 5000;
    }

    if (strcmp(bracket_type, "D3") == 0) {
        return 2500;
    }

    return -1;
}

struct employee {
    char nip[50];
    char name[50];
    char address[100];
    char phone[50];
    char title[50];
    bracket bracket_type;
};

struct overtime {
    char nip[50];
    bracket bracket_type;
    int hours;
};

int main() {
    printf("Enter employee data\n");

    struct employee employee;

    printf("Nip = ");
    readstr(employee.nip, sizeof(employee.nip));

    printf("Nama = ");
    readstr(employee.name, sizeof(employee.name));

    printf("Alamat = ");
    readstr(employee.address, sizeof(employee.address));

    printf("No HP = ");
    readstr(employee.phone, sizeof(employee.phone));

    printf("Jabatan = ");
    readstr(employee.title, sizeof(employee.title));

    printf("Golongan = ");
    readstr(employee.bracket_type, sizeof(employee.bracket_type));

    double main_salary = get_salary_by_bracket(employee.bracket_type);
    if (main_salary == -1) {
        printf("\n<Gaji tidak ditemukan>\n\n");
        return 1;
    }

    printf("Gaji = %.2f\n\n", main_salary);

    printf("Enter overtime data\n");

    struct overtime overtime;
    printf("Nip = ");
    readstr(overtime.nip, sizeof(overtime.nip));

    if (strcmp(overtime.nip, employee.nip) != 0) {
        printf("\n<Nip tidak sesuai>\n\n");
        return 1;
    }

    printf("Golongan = ");
    readstr(overtime.bracket_type, sizeof(overtime.bracket_type));

    double overtime_payment = get_overtime_hour_payment_by_bracket(overtime.bracket_type);
    if (overtime_payment == -1) {
        printf("\n<Bayaran lembur tidak ditemukan>\n\n");
        return 1;
    }

    printf("Lembur = ");
    readint(&overtime.hours, 100);

    double total_overtime_payment = overtime_payment * overtime.hours;
    printf("Bayaran lembur = %.2f\n", overtime_payment);
    printf("Total bayaran lembur = %.2f\n", total_overtime_payment);
    printf("Total Gaji Bulan ini = %.2f", main_salary + total_overtime_payment);

    return 0;
}
