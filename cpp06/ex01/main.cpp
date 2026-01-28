#include "Serializer.hpp"

int main()
{
    Data data;
    data.num = 10;
    data.msg = "testing";

    Data* ptr = &data;

    std::cout << "Original pointer: " << ptr << std::endl;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer: " << recovered << std::endl;

    std::cout << "Recovered number: " << recovered->num << std::endl;
    std::cout << "Recovered text: " << recovered->msg << std::endl;

    return 0;
}
