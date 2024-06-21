#include <stdio.h>
#include <math.h>
int main(){
	for(int trauDung = 1; trauDung <= 100; trauDung++){
		for(int trauNam = 1; trauNam <= 100 - trauDung; trauNam++){
			for(int trauGia = 1; trauGia <= 100 - trauDung - trauNam; trauGia++){
				if((trauDung*15 + trauNam*9 + trauGia == 300) && (trauDung + trauNam + trauGia == 100)){
					printf("So trau dung %d - So trau nam %d - So trau gia %d\n",trauDung,trauNam,trauGia);
				}
			}
		}
	}
	
}
