#include "include/Gun.h"
#include "include/Solider.h"

void test()
{
    Solider sanduo("xusanduo");
    sanduo.addGun(new Gun("AK47"));
    sanduo.addBullectToGun(20);
    sanduo.fire();
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
