
/*
    Quan hệ hợp thành (Composition):
    - Quan hệ hợp thành xảy ra khi đối tượng của lớp ClassB là 1 phần trong đối tượng của lớp ClassA,
     khi đối tượng của lớp ClassA bị hủy thì đối tượng của ClassB cũng bị hủy theo.


    Ex:
        Ví dụ mối quan hệ giữa File và Folder, một Folder sẽ có nhiều File và 
        nếu Folder bị hủy thì File cũng bị hủy theo.


    Ex:
            class ClassA {
                private:
                    ClassB *b;
                public:
                    ClassA() {
                        b = new ClassB();
                    }
            }
            
*/