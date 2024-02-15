#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/dxp/dxp.h"

#include "../include/dxp/control.h"

/**
 * Supposed to ALWAYS be private.
 */
static void *dxp_control_routine_invoke(uint8_t control_instruction_number,
                                        void   *arg)
{
    switch (control_instruction_number)
    {
    case DXP_CONTROL_DIR_MAKE:
        return (*dxp_control_func_dir_make)(arg);
    case DXP_CONTROL_FILE_WRITE:
        return (*dxp_control_func_file_write)(arg);
    default:
        errno = EPROCUNAVAIL;
        perror("Unknown control function");
        dxp_exit(EXIT_FAILURE);
    }
}
