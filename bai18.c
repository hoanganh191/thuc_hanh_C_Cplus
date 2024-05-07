#include <stdio.h>

int main() {
    int a, b, c; // Các chữ số của số có ba chữ số

    // Duyệt qua các số có ba chữ số từ 100 đến 999
    for (int num = 100; num <= 999; num++) {
        // Tách số thành từng chữ số
        a = num / 100;             // Lấy chữ số hàng trăm
        b = (num / 10) % 10;       // Lấy chữ số hàng chục
        c = num % 10;              // Lấy chữ số hàng đơn vị

        // Kiểm tra tổng của các chữ số
        if (a + b + c == 9) {
            // In số và tổng của các chữ số nếu đúng điều kiện
            printf("%d có tổng 3 chữ số: %d+%d+%d=9\n", num, a, b, c);
        }
    }

    return 0;
}
