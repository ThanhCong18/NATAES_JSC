#include<stdio.h>
#include<string.h>
// Bài Tập Quản lý Sinh viên đơn giản - code: Bùi Văn Công .
// tạo 1 struct lưu biến thông tin sinh viên . 
typedef struct   
{
    int msv ;  // mã sinh viên 
    char Ho[10];
    char dem[10];
    char ten[10];
    char gioitinh[10];
    int tuoi ;
    float diemtoan ;
    float diemvan;
    float diemanh;
    float diemtb ;
} sv_info_t;
// hàm nhập thông tin sinh viên 
sv_info_t NhapSv(int index)
{
    sv_info_t sv ;
    printf("Nhap Msvv[%d]:" , index+1);
    scanf("%d" , &sv.msv);
    fflush(stdin);  // xóa bộ nhớ đệm 
    printf("Nhap ho va ten :");
    scanf("%s %s %s" , sv.Ho , sv.dem , sv.ten);
    fflush(stdin);
    printf("Nhap tuoi :");
    scanf("%d" , &sv.tuoi);
    printf("Nhap gioi tinh :");
    fflush(stdin);
    gets(sv.gioitinh);
    printf("Nhap diem :");
    scanf("%f %f %f", &sv.diemtoan , &sv.diemvan , &sv.diemanh);
    sv.diemtb = (sv.diemtoan + sv.diemvan + sv.diemanh)/3;  // tính tổng điểm trung bình của các sinh viên 
    return sv ;
}
// hàm in thông tin của một sinh viên .
void InSV(sv_info_t sv)
{
    printf("%-10d%-10s%-10s%-10s%-10d%-15s%-10.2f%-10.2f%-10.2f%-10.2f\n" , sv.msv , sv.Ho , sv.dem , sv.ten , sv.tuoi , sv.gioitinh , sv.diemtoan , sv.diemvan , sv.diemanh , sv.diemtb);
}
// hàm in thông tin của tất cả sinh viên .
void InallSv( sv_info_t *sv , int num )
{
    printf("------------------------------------\n");
    printf("%-10s%-10s%-10s%-10s%-10s%-15s%-10s%-10s%-10s%-10s\n" , "MASV" , "HO" , "DEM" , "TEN" , "TUOI" , "GIOI TINH" , "TOAN" ,"VAN" , "ANH" ,"DIEMB" );
    for ( int i = 0 ; i < num ; i++)
    {
        InSV(sv[i]);
    }
    printf("------------------------------------\n");
}
// hàm sắp xếp sinh viên theo điểm Trung bình . 
void sapxepSV(sv_info_t *sv , int num , char *option)
{
    sv_info_t sv_clone[100];   // tạo ra 1 mảng mới khác với mảng sv_arr[100];
    memcpy(sv_clone , sv , num*sizeof(sv_info_t)); // copy cac phan tu sang mang sv clone .
    if(strstr(option,"diemtb")) // hàm strstr có chức năng tìm kiếm chuỗi "diemtb" trong đích option được nhập từ bàn phím , nếu có thì thực hiện chương trình . 
    {                                                     
        for ( int i = 0 ; i < num ; i++)  // sử dụng thuật toán selection sort để sắp xếp theo thứ tứ tăng dần của điểm TB .
        {
            for(int j = i+1 ; j < num ; j++)
            {
                if((sv_clone[i].diemtb) > (sv_clone[j].diemtb))
                {
                    sv_info_t temp ;  
                    temp = sv_clone[i] ;  // thực hiện đổi chỗ .
                    sv_clone[i] = sv_clone[j] ;
                    sv_clone[j] = temp;
                }
            }
        }
        InallSv(sv_clone,num);  // in ra thông tin sinh viên đã được sắp xếp theo điểm .
    }
}
int main()
{
    sv_info_t sv_arr[100] ; // mảng lưu trữ thông tin của tất cả sinh viên .
    int slsv ; // biến lưu trữ số lượng sinh viên có trong mảng . 
    printf("nhap so sinh vien : ");
    scanf("%d" , &slsv);
    for( int i = 0 ; i < slsv ; i++)
    {
        sv_arr[i] = NhapSv(i); // thực hiện nhập từng sinh viên vào mảng lưu trữ sv_arr[100];
    }
    sapxepSV(sv_arr,slsv,"diemtb");
    InallSv(sv_arr,slsv);  
    return 0 ;
}
