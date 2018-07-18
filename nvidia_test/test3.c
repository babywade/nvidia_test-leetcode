#include <stdio.h>

int is_interlace(const char* a, const char* b, const char* c)
{
    // Complete your code here
    return 1;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#ifndef __NVIDIA_TEST_
// ----------------------------

int bmain()
{
    // Write your tests here
    const char* a = "AAA";
    const char* b = "B";
    const char* c = "ABAA";
    if (is_interlace(a, b, c))
        printf("Yes\n");
    else
        printf("No\n");
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#endif
// ----------------------------
