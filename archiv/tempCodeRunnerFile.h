#ifndef Blatt3_Header_h
#define Blatt3_Header_h
namespace hfu
{
class DynamicInt
{
    public:
    int *pointer;


    DynamicInt(int number);
    DynamicInt(const DynamicInt &z);
    ~DynamicInt();
    int get();
};
int negative(DynamicInt);
} // namespace hfu
#endif