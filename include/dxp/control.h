#ifndef __DXP_CONTROL_H
#define __DXP_CONTROL_H

#ifdef __cplusplus
extern
{
#endif /* __cplusplus */

#define DXP_CONTROL_DIR_MAKE   0b00000001
#define DXP_CONTROL_FILE_WRITE 0b00010000

    typedef void *(*dxp_control_func)(void *);

    extern dxp_control_func dxp_control_func_dir_make;
    extern dxp_control_func dxp_control_func_file_write;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __DXP_CONTROL_H */
