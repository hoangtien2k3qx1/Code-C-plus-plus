
#include <bits/stdc++.h>

namespace hoangtien2k3 {
    template <typename T, typename X>
    class MyProFile {
    public:
        MyProFile() {
            this->fullname = "Hoang Anh Tien";
            this->username = "hoangtien2k3";
            this->location = "Ha Noi, Viet Nam";
            this->fanpage = "facebook.com/hoangtien2k3.vn/";
            this->youtube = "https://bit.ly/3wEGi3c";
        }
        ~MyProFile(){};
        const T &getFullname() const { return this->fullname; }
        auto _Return_Information() {
            return std::make_tuple(fullname, username, location, fanpage, youtube);
        }

    private:
        T fullname, username, location, youtube, fanpage;
        const X year_birth = 2003;
    };
}

int main()
{
    system("cls");

    hoangtien2k3::MyProFile<std::string, int> p;

    std::string fullname, username, location, fanpage, youtube;
    std::tie(fullname, username, location, fanpage, youtube) = p._Return_Information();
    std::cout << fullname << std::endl
              << username << std::endl
              << location << std::endl
              << fanpage << std::endl
              << youtube << std::endl;

    std::cin.get();
    return 0;
}