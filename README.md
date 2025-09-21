# VI XỬ LÝ - VI ĐIỀU KHIỂN (TN)
* GVHD: TÔN HUỲNH LONG
* SV: Nguyễn Hảo Khang
* MSSV: 2311444

---

## Giới thiệu tổng quan
Kho lưu trữ này là tập hợp các báo cáo và dự án thực hành cho khóa học **Vi xử lý - Vi điều khiển** tại **Đại học Bách Khoa TP. HCM**. Các bài tập đã được thực hiện bằng cách sử dụng **STM32CubeIDE** để lập trình và **Proteus** để mô phỏng.

---

## Cấu trúc kho lưu trữ
Các dự án được tổ chức theo từng chương và bài lab, giúp giảng viên dễ dàng truy cập và đánh giá. Mỗi thư mục (ví dụ: `Chapter_1_LED_Animations`, `Chapter_2_Timer_Interrupt`, v.v.) sẽ chứa đầy đủ các file cần thiết bao gồm:
* Báo cáo chi tiết.
* Mã nguồn dự án STM32CubeIDE.
* File mô phỏng Proteus.

---

## Cách thức mô phỏng
Để thực hiện mô phỏng các bài thực hành, sử dụng git fetch để lấy các nhánh về máy mà không làm ảnh hưởng đến nhánh hiện tại:
1.  **Clone kho lưu trữ:** Clone toàn bộ kho lưu trữ về máy tính.
2.  **Lấy về các nhánh mới:** Lệnh git fetch sẽ tải về tất cả các nhánh và thông tin mới nhất từ remote repository về máy tính cục bộ.
3.  **Chuyển đến nhánh mong muốn:** git checkout <mã_nhánh> sẽ cập nhật thư mục làm việc hiện tại với các file của bài tập đó.
4.  **Mở dự án:**
    * Mở file `.ioc` trong thư mục dự án bằng **STM32CubeIDE**.
    * Mở file `.pdsprj` trong thư mục dự án bằng **Proteus**.
5.  **Biên dịch và nạp chương trình:**
    * Trong **STM32CubeIDE**, sau khi đã cấu hình đúng, chọn `Project -> Build Project` để biên dịch mã nguồn và tạo file `.hex` cho mô phỏng.
6.  **Chạy mô phỏng:**
    * Trong **Proteus**, nhấp đúp vào vi điều khiển STM32 và tải file `.hex` đã được biên dịch vào.
    * Chạy mô phỏng để kiểm tra hoạt động của mạch.
