
/*
    ! Viết chương trình nhập vào tạo độ các đỉnh của tam giác ABC và điểm M xác định nằm trong, nằm trên cạch hay
    ! nằm bên ngoài tam giá ABC.
*/
/*
    ý tưởng để code bài này: 

    * S(ABC) = 1/2 * | xA*xB - xB*yA + xB*yC - xC*yB + xC*yA - xA*yC |

    Biện luận: tổng tam giác MAB + MBC + MAC với tam giác ABC
*/

/*
    VD: 0 5
        3 0
        4 7
        2 6
    => M nam ngoai tam giac ABC.
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

float Dien_Tich (float xA, float yA, float xB, float yB, float xC, float yC) {
    return 0.5 * fabs(xA*xB - xB*yA + xB*yC - xC*yB + xC*yA - xA*yC);
}

int main() {
    float xA, yA, xB, yB, xC, yC, xM, yM;
    printf ("Nhap vao toa do xA, yA: "); scanf ("%f%f", &xA, &yA);
    printf ("Nhap vao toa do xB, yB: "); scanf ("%f%f", &xB, &yB);
    printf ("Nhap vao toa do xC, yC: "); scanf ("%f%f", &xC, &yC);
    printf ("Nhap vao toa do xM, yM: "); scanf ("%f%f", &xM, &yM);

    float S = Dien_Tich(xM, yM, xA, yA, xB, yB) + Dien_Tich(xM, yM, xA, yA, xC, yC) + Dien_Tich(xM, yM, xB, yB, xC, yC) - Dien_Tich(xA, yA, xB, yB, xC, yC);
    if (S > 0) {
        printf ("M nam ngoai tam giac ABC.");
    } else if (Dien_Tich(xM, yM, xA, yA, xB, yB) == 0 ||  Dien_Tich(xM, yM, xA, yA, xC, yC) == 0 || Dien_Tich(xM, yM, xB, yB, xC, yC) == 0) {
        printf ("M nam tren tam gia ABC.");
    } else {
        printf ("M nam trong tam giac ABC.");
    }
    return 0;
}
