#ifndef Blatt3_Header_h
#define Blatt3_Header_h
namespace hfu
{
class DynamicInt
{
    int *pointer;

public:
    DynamicInt(int number);
    DynamicInt(const DynamicInt &z) ;
    ~DynamicInt();
    int get() const ;
};
int negative(DynamicInt);
} // namespace hfu
#endif