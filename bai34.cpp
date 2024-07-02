/*Định hướng giải
ví dụ có chuối aabbcc ta có biến check để kiểm tra ký tự nào cần tính số lần lặp
đầu tiên cho vòng lặp for duyệt các ký tự trong chuỗi
Ta kiểm tra ký tự hiện tại (đang ở đầu) đã duyệt chưa 
vì check rỗng nên ký tự hiện tại (a)  chưa xét
ta cho check = ký tự cần xét (a)
ta xét vị trí ký tự xét xuất hiện đầu tiên (vị trí i) = duyet
Ta sử dùng vòng lặp while
nếu tại giá trị của mảng tại vị trí duyệt == check (ở đây là a) thì 
biến đếm tăng và biến duyệt tăng 1 để xét giá trị tiếp theo   
hết vòng while thì in ra kết quả của ký tự a 

Sau đó vòng for chạy tiếp tại ký tự tiếp theo , 
ở đây vòng lăp kiểm tra thấy a = check (a này đã xét ) nên chạy tiếp
đến khi đến ký tự b != check (Do b != a hay b chưa xét) nên thuật toán tiếp tục như trên
*/
#include <stdio.h>
#include <string.h>

int main(){
	char text[100];
	printf("Moi ban nhap xau ky tu: ");
	fflush(stdin);
	gets(text);
	char check; //Biến kiểm tra xem ký tự đang xét có trùng ký tự trước không
	for(int i = 0; i < strlen(text); i++){ //duyệt lần lượt các ký tự
		if(text[i] != check){ //Nếu ký tự hiện tại chưa xét (khác với biến check)
			check = text[i]; //Gán giá trị biến check = ký tự cần xét
			int dem = 0; //Khơi tạo biến đếm
			int duyet = i; //Ví trị duyệt = i vì đây là vị trí bắt đầu của ký tự cần xét
			while (text[duyet] == check) //Nếu ký tự sau đó = check
			{
				//Tăng giá trị để xét ký tự tiếp
				dem++;
				duyet++;
			}
			//In ra kết quả
			printf("%d%c",dem,check);
		}
	}
	
}
