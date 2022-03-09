#include <iostream>
using namespace std;

#pragma pack(2)

struct how{
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

int main(){
    cout<<sizeof(how)<<endl;
    return 0;
}

