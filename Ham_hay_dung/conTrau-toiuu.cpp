#include <stdio.h>

int main(){
    for (int trauDung = 1; trauDung < 100; trauDung++) //Vì số trâu đứng chạy từ 1 - 100
    {
        for (int trauNam = 1; trauNam < 100 - trauDung; trauNam++) //Số trâu nằm chạy từ 1 -> 100 - số trâu đứng
        {
            /*Vì số trâu đứng , trâu nằm đã biết số lượng qua giá trị từng vòng lặp mà tổng
            cố định có 100 con => Ta tính được số trâu nằm luôn mà k cần xét vòng lặp*/
            int trauGia = 100 - trauDung - trauNam; 
            if (trauDung*15 + trauNam*9 + trauGia == 300)
            {
                printf("So trau dung %d - So trau nam %d - So trau gia %d\n",trauDung,trauNam,trauGia);
            }
            
            
        }
        
    }
    
}