#ifndef __DXP_H
#define __DXP_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
 * C11      memcpy_s
 */
#if (__STDC_VERSION__ < 201112L)
#error "C Standard version not met"
#elif (__STDC_VERSION__ >= 202311L)
#define __DXP_STDC_2023
#endif

    void dxp_cleanup(void);

    void dxp_exit(int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __DXP_H */
