#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
//////////////////////////
int main(int argc, char *argv[])
{
    doctest::Context context(argc, argv);
    //
    //gedcomfixture::getInstance().check();
    //
    int res = context.run();
    return res;
} // main
