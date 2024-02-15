#include "../include/dxp/common.h"

#include "../include/dxp/dxp.h"

void dxp_cleanup(void) {}

void dxp_exit(int status)
{
    dxp_cleanup();
    exit(status);
}
