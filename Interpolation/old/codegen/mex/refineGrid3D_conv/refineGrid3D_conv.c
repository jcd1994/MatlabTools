/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * refineGrid3D_conv.c
 *
 * Code generation for function 'refineGrid3D_conv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "refineGrid3D_conv.h"
#include "refineGrid3D_conv_emxutil.h"
#include "refineGrid3D_conv_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 19, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 12, 17, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 6, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 35, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 36, 5, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 37, 9, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 20, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 20, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 20, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 20, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 23, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 23, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 23, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 24, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 24, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 24, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo h_emlrtBCI = { -1, -1, 25, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 25, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo d_emlrtECI = { -1, 25, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo j_emlrtBCI = { -1, -1, 28, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo e_emlrtECI = { -1, 28, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo k_emlrtBCI = { -1, -1, 29, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo f_emlrtECI = { -1, 29, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo l_emlrtBCI = { -1, -1, 30, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtECInfo g_emlrtECI = { -1, 30, 1, "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m"
};

static emlrtBCInfo m_emlrtBCI = { -1, -1, 43, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 43, 41, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 43, 44, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 45, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 45, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 45, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 46, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 46, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 46, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 47, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 47, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 47, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 48, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 48, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 48, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 49, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 49, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 49, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 50, 54, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 50, 59, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 50, 64, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 59, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 59, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 59, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 59, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 59, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 59, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 59, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 59, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 59, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 61, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 61, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 61, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 61, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 61, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 61, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 61, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 61, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 61, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 63, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 63, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 63, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 63, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 63, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 63, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 63, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 63, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 63, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 65, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 65, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 65, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 65, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 65, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 65, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 65, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 65, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 65, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 68, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 68, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 68, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 68, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 68, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 68, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 68, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 68, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 68, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 70, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 70, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 70, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 70, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 70, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 70, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 70, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 70, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 70, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 72, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 72, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 72, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 72, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 72, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 72, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 72, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 72, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 72, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 74, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 74, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 74, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 74, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 74, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 74, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 74, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 74, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 74, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 77, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 77, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 77, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 77, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 77, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 77, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 77, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 77, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 77, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 79, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 79, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 79, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 79, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 79, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 79, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 79, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 79, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 79, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 81, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 81, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 81, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 81, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 81, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 81, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 81, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 81, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 81, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 83, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 83, 32, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 83, 37, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 83, 55, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 83, 60, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 83, 65, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 83, 83, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 83, 88, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 83, 93, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 92, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 92, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 92, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 92, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 92, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 92, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 92, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 92, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 92, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 93, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 93, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cg_emlrtBCI = { -1, -1, 93, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dg_emlrtBCI = { -1, -1, 93, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo eg_emlrtBCI = { -1, -1, 93, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fg_emlrtBCI = { -1, -1, 93, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gg_emlrtBCI = { -1, -1, 93, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hg_emlrtBCI = { -1, -1, 93, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ig_emlrtBCI = { -1, -1, 93, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jg_emlrtBCI = { -1, -1, 93, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kg_emlrtBCI = { -1, -1, 93, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lg_emlrtBCI = { -1, -1, 93, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mg_emlrtBCI = { -1, -1, 95, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ng_emlrtBCI = { -1, -1, 95, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo og_emlrtBCI = { -1, -1, 95, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pg_emlrtBCI = { -1, -1, 95, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qg_emlrtBCI = { -1, -1, 95, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rg_emlrtBCI = { -1, -1, 95, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sg_emlrtBCI = { -1, -1, 95, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tg_emlrtBCI = { -1, -1, 95, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ug_emlrtBCI = { -1, -1, 95, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vg_emlrtBCI = { -1, -1, 96, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wg_emlrtBCI = { -1, -1, 96, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xg_emlrtBCI = { -1, -1, 96, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yg_emlrtBCI = { -1, -1, 96, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ah_emlrtBCI = { -1, -1, 96, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bh_emlrtBCI = { -1, -1, 96, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ch_emlrtBCI = { -1, -1, 96, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dh_emlrtBCI = { -1, -1, 96, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo eh_emlrtBCI = { -1, -1, 96, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fh_emlrtBCI = { -1, -1, 96, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gh_emlrtBCI = { -1, -1, 96, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hh_emlrtBCI = { -1, -1, 96, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ih_emlrtBCI = { -1, -1, 98, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jh_emlrtBCI = { -1, -1, 98, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kh_emlrtBCI = { -1, -1, 98, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lh_emlrtBCI = { -1, -1, 98, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mh_emlrtBCI = { -1, -1, 98, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nh_emlrtBCI = { -1, -1, 98, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oh_emlrtBCI = { -1, -1, 98, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ph_emlrtBCI = { -1, -1, 98, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qh_emlrtBCI = { -1, -1, 98, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rh_emlrtBCI = { -1, -1, 99, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sh_emlrtBCI = { -1, -1, 99, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo th_emlrtBCI = { -1, -1, 99, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uh_emlrtBCI = { -1, -1, 99, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vh_emlrtBCI = { -1, -1, 99, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wh_emlrtBCI = { -1, -1, 99, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xh_emlrtBCI = { -1, -1, 99, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yh_emlrtBCI = { -1, -1, 99, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ai_emlrtBCI = { -1, -1, 99, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bi_emlrtBCI = { -1, -1, 99, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ci_emlrtBCI = { -1, -1, 99, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo di_emlrtBCI = { -1, -1, 99, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ei_emlrtBCI = { -1, -1, 101, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fi_emlrtBCI = { -1, -1, 101, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gi_emlrtBCI = { -1, -1, 101, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hi_emlrtBCI = { -1, -1, 101, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ii_emlrtBCI = { -1, -1, 101, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ji_emlrtBCI = { -1, -1, 101, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ki_emlrtBCI = { -1, -1, 101, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo li_emlrtBCI = { -1, -1, 101, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mi_emlrtBCI = { -1, -1, 101, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ni_emlrtBCI = { -1, -1, 102, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oi_emlrtBCI = { -1, -1, 102, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pi_emlrtBCI = { -1, -1, 102, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qi_emlrtBCI = { -1, -1, 102, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ri_emlrtBCI = { -1, -1, 102, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo si_emlrtBCI = { -1, -1, 102, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ti_emlrtBCI = { -1, -1, 102, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ui_emlrtBCI = { -1, -1, 102, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vi_emlrtBCI = { -1, -1, 102, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wi_emlrtBCI = { -1, -1, 102, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xi_emlrtBCI = { -1, -1, 102, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yi_emlrtBCI = { -1, -1, 102, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo aj_emlrtBCI = { -1, -1, 104, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bj_emlrtBCI = { -1, -1, 104, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cj_emlrtBCI = { -1, -1, 104, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dj_emlrtBCI = { -1, -1, 104, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ej_emlrtBCI = { -1, -1, 104, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fj_emlrtBCI = { -1, -1, 104, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gj_emlrtBCI = { -1, -1, 104, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hj_emlrtBCI = { -1, -1, 104, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ij_emlrtBCI = { -1, -1, 104, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jj_emlrtBCI = { -1, -1, 105, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kj_emlrtBCI = { -1, -1, 105, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lj_emlrtBCI = { -1, -1, 105, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mj_emlrtBCI = { -1, -1, 105, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nj_emlrtBCI = { -1, -1, 105, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oj_emlrtBCI = { -1, -1, 105, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pj_emlrtBCI = { -1, -1, 105, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qj_emlrtBCI = { -1, -1, 105, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rj_emlrtBCI = { -1, -1, 105, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sj_emlrtBCI = { -1, -1, 105, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tj_emlrtBCI = { -1, -1, 105, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uj_emlrtBCI = { -1, -1, 105, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vj_emlrtBCI = { -1, -1, 107, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wj_emlrtBCI = { -1, -1, 107, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xj_emlrtBCI = { -1, -1, 107, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yj_emlrtBCI = { -1, -1, 107, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ak_emlrtBCI = { -1, -1, 107, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bk_emlrtBCI = { -1, -1, 107, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ck_emlrtBCI = { -1, -1, 107, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dk_emlrtBCI = { -1, -1, 107, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ek_emlrtBCI = { -1, -1, 107, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fk_emlrtBCI = { -1, -1, 108, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gk_emlrtBCI = { -1, -1, 108, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hk_emlrtBCI = { -1, -1, 108, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ik_emlrtBCI = { -1, -1, 108, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jk_emlrtBCI = { -1, -1, 108, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kk_emlrtBCI = { -1, -1, 108, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lk_emlrtBCI = { -1, -1, 108, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mk_emlrtBCI = { -1, -1, 108, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nk_emlrtBCI = { -1, -1, 108, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ok_emlrtBCI = { -1, -1, 108, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pk_emlrtBCI = { -1, -1, 108, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qk_emlrtBCI = { -1, -1, 108, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rk_emlrtBCI = { -1, -1, 110, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sk_emlrtBCI = { -1, -1, 110, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tk_emlrtBCI = { -1, -1, 110, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uk_emlrtBCI = { -1, -1, 110, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vk_emlrtBCI = { -1, -1, 110, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wk_emlrtBCI = { -1, -1, 110, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xk_emlrtBCI = { -1, -1, 110, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yk_emlrtBCI = { -1, -1, 110, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo al_emlrtBCI = { -1, -1, 110, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bl_emlrtBCI = { -1, -1, 111, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cl_emlrtBCI = { -1, -1, 111, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dl_emlrtBCI = { -1, -1, 111, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo el_emlrtBCI = { -1, -1, 111, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fl_emlrtBCI = { -1, -1, 111, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gl_emlrtBCI = { -1, -1, 111, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hl_emlrtBCI = { -1, -1, 111, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo il_emlrtBCI = { -1, -1, 111, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jl_emlrtBCI = { -1, -1, 111, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kl_emlrtBCI = { -1, -1, 111, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ll_emlrtBCI = { -1, -1, 111, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ml_emlrtBCI = { -1, -1, 111, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nl_emlrtBCI = { -1, -1, 113, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ol_emlrtBCI = { -1, -1, 113, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pl_emlrtBCI = { -1, -1, 113, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ql_emlrtBCI = { -1, -1, 113, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rl_emlrtBCI = { -1, -1, 113, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sl_emlrtBCI = { -1, -1, 113, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tl_emlrtBCI = { -1, -1, 113, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ul_emlrtBCI = { -1, -1, 113, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vl_emlrtBCI = { -1, -1, 113, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wl_emlrtBCI = { -1, -1, 114, 28, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xl_emlrtBCI = { -1, -1, 114, 33, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yl_emlrtBCI = { -1, -1, 114, 38, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo am_emlrtBCI = { -1, -1, 114, 57, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bm_emlrtBCI = { -1, -1, 114, 62, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cm_emlrtBCI = { -1, -1, 114, 67, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dm_emlrtBCI = { -1, -1, 114, 86, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo em_emlrtBCI = { -1, -1, 114, 91, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fm_emlrtBCI = { -1, -1, 114, 96, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gm_emlrtBCI = { -1, -1, 114, 115, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hm_emlrtBCI = { -1, -1, 114, 120, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo im_emlrtBCI = { -1, -1, 114, 125, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jm_emlrtBCI = { -1, -1, 121, 11, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo km_emlrtBCI = { -1, -1, 121, 19, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lm_emlrtBCI = { -1, -1, 121, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mm_emlrtBCI = { -1, -1, 23, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nm_emlrtBCI = { -1, -1, 23, 45, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo om_emlrtBCI = { -1, -1, 24, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pm_emlrtBCI = { -1, -1, 24, 47, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qm_emlrtBCI = { -1, -1, 25, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rm_emlrtBCI = { -1, -1, 25, 47, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sm_emlrtBCI = { -1, -1, 28, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tm_emlrtBCI = { -1, -1, 28, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo um_emlrtBCI = { -1, -1, 28, 45, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vm_emlrtBCI = { -1, -1, 28, 53, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wm_emlrtBCI = { -1, -1, 29, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xm_emlrtBCI = { -1, -1, 29, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ym_emlrtBCI = { -1, -1, 29, 45, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo an_emlrtBCI = { -1, -1, 29, 55, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bn_emlrtBCI = { -1, -1, 30, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cn_emlrtBCI = { -1, -1, 30, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dn_emlrtBCI = { -1, -1, 30, 47, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo en_emlrtBCI = { -1, -1, 30, 55, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fn_emlrtBCI = { -1, -1, 33, 47, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gn_emlrtBCI = { -1, -1, 33, 55, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hn_emlrtBCI = { -1, -1, 33, 63, "V", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo in_emlrtBCI = { -1, -1, 33, 5, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jn_emlrtBCI = { -1, -1, 33, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kn_emlrtBCI = { -1, -1, 33, 27, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ln_emlrtBCI = { -1, -1, 45, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mn_emlrtBCI = { -1, -1, 45, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nn_emlrtBCI = { -1, -1, 45, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo on_emlrtBCI = { -1, -1, 46, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pn_emlrtBCI = { -1, -1, 46, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qn_emlrtBCI = { -1, -1, 46, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rn_emlrtBCI = { -1, -1, 47, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sn_emlrtBCI = { -1, -1, 47, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tn_emlrtBCI = { -1, -1, 47, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo un_emlrtBCI = { -1, -1, 48, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vn_emlrtBCI = { -1, -1, 48, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wn_emlrtBCI = { -1, -1, 48, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xn_emlrtBCI = { -1, -1, 49, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yn_emlrtBCI = { -1, -1, 49, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ao_emlrtBCI = { -1, -1, 49, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bo_emlrtBCI = { -1, -1, 50, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo co_emlrtBCI = { -1, -1, 50, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo do_emlrtBCI = { -1, -1, 50, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo eo_emlrtBCI = { -1, -1, 58, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fo_emlrtBCI = { -1, -1, 58, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo go_emlrtBCI = { -1, -1, 58, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ho_emlrtBCI = { -1, -1, 60, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo io_emlrtBCI = { -1, -1, 60, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jo_emlrtBCI = { -1, -1, 60, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ko_emlrtBCI = { -1, -1, 62, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lo_emlrtBCI = { -1, -1, 62, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mo_emlrtBCI = { -1, -1, 62, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo no_emlrtBCI = { -1, -1, 64, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo oo_emlrtBCI = { -1, -1, 64, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo po_emlrtBCI = { -1, -1, 64, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qo_emlrtBCI = { -1, -1, 67, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ro_emlrtBCI = { -1, -1, 67, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo so_emlrtBCI = { -1, -1, 67, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo to_emlrtBCI = { -1, -1, 69, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo uo_emlrtBCI = { -1, -1, 69, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vo_emlrtBCI = { -1, -1, 69, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wo_emlrtBCI = { -1, -1, 71, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xo_emlrtBCI = { -1, -1, 71, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yo_emlrtBCI = { -1, -1, 71, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ap_emlrtBCI = { -1, -1, 73, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bp_emlrtBCI = { -1, -1, 73, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cp_emlrtBCI = { -1, -1, 73, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dp_emlrtBCI = { -1, -1, 76, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ep_emlrtBCI = { -1, -1, 76, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fp_emlrtBCI = { -1, -1, 76, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gp_emlrtBCI = { -1, -1, 78, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hp_emlrtBCI = { -1, -1, 78, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo ip_emlrtBCI = { -1, -1, 78, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jp_emlrtBCI = { -1, -1, 80, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kp_emlrtBCI = { -1, -1, 80, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lp_emlrtBCI = { -1, -1, 80, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mp_emlrtBCI = { -1, -1, 82, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo np_emlrtBCI = { -1, -1, 82, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo op_emlrtBCI = { -1, -1, 82, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo pp_emlrtBCI = { -1, -1, 91, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo qp_emlrtBCI = { -1, -1, 91, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo rp_emlrtBCI = { -1, -1, 91, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo sp_emlrtBCI = { -1, -1, 94, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo tp_emlrtBCI = { -1, -1, 94, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo up_emlrtBCI = { -1, -1, 94, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo vp_emlrtBCI = { -1, -1, 97, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo wp_emlrtBCI = { -1, -1, 97, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo xp_emlrtBCI = { -1, -1, 97, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo yp_emlrtBCI = { -1, -1, 100, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo aq_emlrtBCI = { -1, -1, 100, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo bq_emlrtBCI = { -1, -1, 100, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo cq_emlrtBCI = { -1, -1, 103, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo dq_emlrtBCI = { -1, -1, 103, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo eq_emlrtBCI = { -1, -1, 103, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo fq_emlrtBCI = { -1, -1, 106, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo gq_emlrtBCI = { -1, -1, 106, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo hq_emlrtBCI = { -1, -1, 106, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo iq_emlrtBCI = { -1, -1, 109, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo jq_emlrtBCI = { -1, -1, 109, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo kq_emlrtBCI = { -1, -1, 109, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo lq_emlrtBCI = { -1, -1, 112, 16, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo mq_emlrtBCI = { -1, -1, 112, 21, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

static emlrtBCInfo nq_emlrtBCI = { -1, -1, 112, 26, "Vk", "refineGrid3D_conv",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Interpolation/refineGrid3D_conv.m",
  0 };

/* Function Declarations */
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void refineGrid3D_conv_Once(const emlrtStack *sp, const emxArray_real32_T
  *V, emxArray_real32_T *Vk);

/* Function Definitions */
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    if (quotientNeedsNegation) {
      quotient = -(int32_T)tempAbsQuotient;
    } else {
      quotient = (int32_T)tempAbsQuotient;
    }
  }

  return quotient;
}

static void refineGrid3D_conv_Once(const emlrtStack *sp, const emxArray_real32_T
  *V, emxArray_real32_T *Vk)
{
  real_T Vksize[3];
  int32_T i1;
  int32_T loop_ub;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T b_loop_ub;
  emxArray_int32_T *r0;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  int32_T b_V[3];
  int32_T b_Vk;
  int32_T iv0[2];
  int32_T iv1[2];
  int32_T i10;
  emxArray_real32_T *r3;
  int32_T iv2[2];
  int32_T i11;
  emxArray_real32_T *c_V;
  int32_T iv3[3];
  int32_T iv4[2];
  int32_T iv5[2];
  int32_T i12;
  emxArray_real32_T *r4;
  int32_T iv6[2];
  int32_T i13;
  emxArray_real32_T *d_V;
  int32_T iv7[3];
  int32_T iv8[2];
  int32_T iv9[2];
  int32_T i14;
  emxArray_real32_T *r5;
  int32_T iv10[2];
  int32_T i15;
  emxArray_real32_T *e_V;
  int32_T iv11[3];
  int32_T iv12[2];
  int32_T iv13[2];
  int32_T i16;
  int32_T iv14[2];
  int32_T i17;
  emxArray_real32_T *r6;
  int32_T iv15[2];
  int32_T iv16[2];
  int32_T i18;
  int32_T i19;
  emxArray_real32_T *f_V;
  int32_T iv17[3];
  int32_T iv18[2];
  int32_T iv19[2];
  int32_T iv20[2];
  int32_T i20;
  int32_T iv21[2];
  int32_T i21;
  emxArray_real32_T *r7;
  int32_T iv22[2];
  int32_T iv23[2];
  int32_T i22;
  int32_T i23;
  emxArray_real32_T *g_V;
  int32_T iv24[3];
  int32_T iv25[2];
  int32_T iv26[2];
  int32_T iv27[2];
  int32_T i24;
  int32_T iv28[2];
  int32_T i25;
  emxArray_real32_T *r8;
  int32_T iv29[2];
  int32_T iv30[2];
  int32_T i26;
  int32_T i27;
  emxArray_real32_T *h_V;
  int32_T iv31[3];
  int32_T iv32[2];
  int32_T iv33[2];
  int32_T iv34[2];
  int32_T iv35[2];
  int32_T c_Vk;
  int32_T iv36[2];
  int32_T iv37[2];
  int32_T iv38[2];
  int32_T iv39[2];
  int32_T i28;
  int32_T i29;
  int32_T i30;
  int32_T i31;
  int32_T i32;
  int32_T i33;
  uint32_T ii;
  uint32_T jj;
  uint32_T kk;
  real32_T Vkhalf;
  int32_T i34;
  int32_T i35;
  int32_T i36;
  int32_T i37;
  int32_T i38;
  int32_T i39;
  int32_T i40;
  int32_T i41;
  int32_T i42;
  int32_T i43;
  int32_T i44;
  int32_T i45;
  int32_T i46;
  int32_T i47;
  int32_T i48;
  int32_T i49;
  int32_T i50;
  int32_T i51;
  real32_T Vkquart;
  int32_T i52;
  int32_T i53;
  int32_T i54;
  int32_T i55;
  int32_T i56;
  int32_T i57;
  int32_T i58;
  int32_T i59;
  int32_T i60;
  int32_T i61;
  int32_T i62;
  int32_T i63;
  int32_T i64;
  int32_T i65;
  int32_T i66;
  int32_T i67;
  int32_T i68;
  int32_T i69;
  int32_T i70;
  int32_T i71;
  int32_T i72;
  int32_T i73;
  int32_T i74;
  int32_T i75;
  int32_T i76;
  int32_T i77;
  int32_T i78;
  int32_T i79;
  int32_T i80;
  int32_T i81;
  int32_T i82;
  int32_T i83;
  int32_T i84;
  int32_T i85;
  int32_T i86;
  int32_T i87;
  real32_T Vkeighth;
  int32_T i88;
  int32_T i89;
  int32_T i90;
  int32_T i91;
  int32_T i92;
  int32_T i93;
  int32_T i94;
  int32_T i95;
  int32_T i96;
  int32_T i97;
  int32_T i98;
  int32_T i99;
  int32_T i100;
  int32_T i101;
  int32_T i102;
  int32_T i103;
  int32_T i104;
  int32_T i105;
  int32_T i106;
  int32_T i107;
  int32_T i108;
  int32_T i109;
  int32_T i110;
  int32_T i111;
  emxArray_real32_T *d_Vk;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (i1 = 0; i1 < 3; i1++) {
    Vksize[i1] = (2.0 * (real_T)V->size[i1] - 1.0) + 4.0;
  }

  i1 = Vk->size[0] * Vk->size[1] * Vk->size[2];
  Vk->size[0] = (int32_T)Vksize[0];
  emxEnsureCapacity(sp, (emxArray__common *)Vk, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  i1 = Vk->size[0] * Vk->size[1] * Vk->size[2];
  Vk->size[1] = (int32_T)Vksize[1];
  emxEnsureCapacity(sp, (emxArray__common *)Vk, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  i1 = Vk->size[0] * Vk->size[1] * Vk->size[2];
  Vk->size[2] = (int32_T)Vksize[2];
  emxEnsureCapacity(sp, (emxArray__common *)Vk, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  loop_ub = (int32_T)Vksize[0] * (int32_T)Vksize[1] * (int32_T)Vksize[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    Vk->data[i1] = 0.0F;
  }

  /*  insert inner values */
  if (3 > (int32_T)Vksize[0] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = (int32_T)Vksize[0];
    i4 = (int32_T)Vksize[0] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &emlrtBCI, sp);
    }
  }

  if (3 > (int32_T)Vksize[1] - 2) {
    i4 = 1;
    i5 = 1;
    i6 = 0;
  } else {
    i4 = 3;
    i5 = 2;
    i6 = (int32_T)Vksize[1];
    i7 = (int32_T)Vksize[1] - 2;
    if ((i7 >= 1) && (i7 < i6)) {
      i6 = i7;
    } else {
      i6 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &b_emlrtBCI, sp);
    }
  }

  if (3 > (int32_T)Vksize[2] - 2) {
    i7 = 1;
    i8 = 1;
    i9 = 0;
  } else {
    i7 = 3;
    i8 = 2;
    i9 = (int32_T)Vksize[2];
    b_loop_ub = (int32_T)Vksize[2] - 2;
    if ((b_loop_ub >= 1) && (b_loop_ub < i9)) {
      i9 = b_loop_ub;
    } else {
      i9 = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i9, &c_emlrtBCI, sp);
    }
  }

  emxInit_int32_T(sp, &r0, 1, &b_emlrtRTEI, true);
  b_loop_ub = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, b_loop_ub, (int32_T)sizeof
                    (int32_T), &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  emxInit_int32_T(sp, &r1, 1, &b_emlrtRTEI, true);
  i1 = r1->size[0];
  r1->size[0] = div_s32_floor(sp, i6 - i4, i5) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i6 - i4, i5);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    r1->data[i1] = (i4 + i5 * i1) - 1;
  }

  emxInit_int32_T(sp, &r2, 1, &b_emlrtRTEI, true);
  i1 = r2->size[0];
  r2->size[0] = div_s32_floor(sp, i9 - i7, i8) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r2, i1, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i9 - i7, i8);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    r2->data[i1] = (i7 + i8 * i1) - 1;
  }

  b_V[0] = r0->size[0];
  b_V[1] = r1->size[0];
  b_V[2] = r2->size[0];
  emlrtSubAssignSizeCheckR2012b(b_V, 3, *(int32_T (*)[3])V->size, 3, &emlrtECI,
    sp);
  loop_ub = V->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = V->size[1];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_Vk = V->size[0];
      for (i3 = 0; i3 < b_Vk; i3++) {
        Vk->data[(r0->data[i3] + Vk->size[0] * r1->data[i2]) + Vk->size[0] *
          Vk->size[1] * r2->data[i1]] = V->data[(i3 + V->size[0] * i2) + V->
          size[0] * V->size[1] * i1];
      }
    }
  }

  emxFree_int32_T(&r2);

  /*  pad sides with inside values */
  if (3 > Vk->size[1] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[1];
    i4 = Vk->size[1] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &d_emlrtBCI, sp);
    }
  }

  if (3 > Vk->size[2] - 2) {
    i4 = 1;
    i5 = 1;
    i6 = 0;
  } else {
    i4 = 3;
    i5 = 2;
    i6 = Vk->size[2];
    i7 = Vk->size[2] - 2;
    if ((i7 >= 1) && (i7 < i6)) {
      i6 = i7;
    } else {
      i6 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &e_emlrtBCI, sp);
    }
  }

  iv0[0] = 1;
  iv0[1] = Vk->size[0];
  for (i7 = 0; i7 < 2; i7++) {
    i8 = Vk->size[0];
    if ((iv0[i7] >= 1) && (iv0[i7] < i8)) {
      i10 = iv0[i7];
    } else {
      i10 = emlrtDynamicBoundsCheckR2012b(iv0[i7], 1, i8, &mm_emlrtBCI, sp);
    }

    iv1[i7] = i10 - 1;
  }

  i7 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i7, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  i1 = r1->size[0];
  r1->size[0] = div_s32_floor(sp, i6 - i4, i5) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i6 - i4, i5);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    r1->data[i1] = (i4 + i5 * i1) - 1;
  }

  emxInit_real32_T(sp, &r3, 3, &b_emlrtRTEI, true);
  iv2[0] = 1;
  iv2[1] = V->size[0];
  loop_ub = V->size[1];
  b_loop_ub = V->size[2];
  i1 = r3->size[0] * r3->size[1] * r3->size[2];
  r3->size[0] = 2;
  r3->size[1] = loop_ub;
  r3->size[2] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        i4 = V->size[0];
        if ((iv2[i3] >= 1) && (iv2[i3] < i4)) {
          i11 = iv2[i3];
        } else {
          i11 = emlrtDynamicBoundsCheckR2012b(iv2[i3], 1, i4, &nm_emlrtBCI, sp);
        }

        r3->data[(i3 + r3->size[0] * i2) + r3->size[0] * r3->size[1] * i1] =
          V->data[((i11 + V->size[0] * i2) + V->size[0] * V->size[1] * i1) - 1];
      }
    }
  }

  emxInit_real32_T(sp, &c_V, 3, &b_emlrtRTEI, true);
  iv3[0] = 2;
  iv3[1] = r0->size[0];
  iv3[2] = r1->size[0];
  iv4[0] = 1;
  iv4[1] = V->size[0];
  loop_ub = V->size[1];
  b_loop_ub = V->size[2];
  i1 = c_V->size[0] * c_V->size[1] * c_V->size[2];
  c_V->size[0] = 2;
  c_V->size[1] = loop_ub;
  c_V->size[2] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)c_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        c_V->data[(i3 + c_V->size[0] * i2) + c_V->size[0] * c_V->size[1] * i1] =
          V->data[((iv4[i3] + V->size[0] * i2) + V->size[0] * V->size[1] * i1) -
          1];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = c_V->size[i1];
  }

  emxFree_real32_T(&c_V);
  emlrtSubAssignSizeCheckR2012b(iv3, 3, b_V, 3, &b_emlrtECI, sp);
  loop_ub = r3->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = r3->size[1];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        Vk->data[(iv1[i3] + Vk->size[0] * r0->data[i2]) + Vk->size[0] * Vk->
          size[1] * r1->data[i1]] = r3->data[(i3 + r3->size[0] * i2) + r3->size
          [0] * r3->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r3);
  if (3 > Vk->size[0] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[0];
    i4 = Vk->size[0] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &f_emlrtBCI, sp);
    }
  }

  if (3 > Vk->size[2] - 2) {
    i4 = 1;
    i5 = 1;
    i6 = 0;
  } else {
    i4 = 3;
    i5 = 2;
    i6 = Vk->size[2];
    i7 = Vk->size[2] - 2;
    if ((i7 >= 1) && (i7 < i6)) {
      i6 = i7;
    } else {
      i6 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &g_emlrtBCI, sp);
    }
  }

  i7 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i7, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  iv5[0] = 1;
  iv5[1] = Vk->size[1];
  for (i1 = 0; i1 < 2; i1++) {
    i2 = Vk->size[1];
    if ((iv5[i1] >= 1) && (iv5[i1] < i2)) {
      i12 = iv5[i1];
    } else {
      i12 = emlrtDynamicBoundsCheckR2012b(iv5[i1], 1, i2, &om_emlrtBCI, sp);
    }

    iv1[i1] = i12 - 1;
  }

  i1 = r1->size[0];
  r1->size[0] = div_s32_floor(sp, i6 - i4, i5) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i6 - i4, i5);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    r1->data[i1] = (i4 + i5 * i1) - 1;
  }

  emxInit_real32_T(sp, &r4, 3, &b_emlrtRTEI, true);
  loop_ub = V->size[0];
  iv6[0] = 1;
  iv6[1] = V->size[1];
  b_loop_ub = V->size[2];
  i1 = r4->size[0] * r4->size[1] * r4->size[2];
  r4->size[0] = loop_ub;
  r4->size[1] = 2;
  r4->size[2] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r4, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        i4 = V->size[1];
        if ((iv6[i2] >= 1) && (iv6[i2] < i4)) {
          i13 = iv6[i2];
        } else {
          i13 = emlrtDynamicBoundsCheckR2012b(iv6[i2], 1, i4, &pm_emlrtBCI, sp);
        }

        r4->data[(i3 + r4->size[0] * i2) + r4->size[0] * r4->size[1] * i1] =
          V->data[(i3 + V->size[0] * (i13 - 1)) + V->size[0] * V->size[1] * i1];
      }
    }
  }

  emxInit_real32_T(sp, &d_V, 3, &b_emlrtRTEI, true);
  iv7[0] = r0->size[0];
  iv7[1] = 2;
  iv7[2] = r1->size[0];
  loop_ub = V->size[0];
  iv8[0] = 1;
  iv8[1] = V->size[1];
  b_loop_ub = V->size[2];
  i1 = d_V->size[0] * d_V->size[1] * d_V->size[2];
  d_V->size[0] = loop_ub;
  d_V->size[1] = 2;
  d_V->size[2] = b_loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)d_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        d_V->data[(i3 + d_V->size[0] * i2) + d_V->size[0] * d_V->size[1] * i1] =
          V->data[(i3 + V->size[0] * (iv8[i2] - 1)) + V->size[0] * V->size[1] *
          i1];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = d_V->size[i1];
  }

  emxFree_real32_T(&d_V);
  emlrtSubAssignSizeCheckR2012b(iv7, 3, b_V, 3, &c_emlrtECI, sp);
  loop_ub = r4->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      b_loop_ub = r4->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        Vk->data[(r0->data[i3] + Vk->size[0] * iv1[i2]) + Vk->size[0] * Vk->
          size[1] * r1->data[i1]] = r4->data[(i3 + r4->size[0] * i2) + r4->size
          [0] * r4->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r4);
  if (3 > Vk->size[0] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[0];
    i4 = Vk->size[0] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &h_emlrtBCI, sp);
    }
  }

  if (3 > Vk->size[1] - 2) {
    i4 = 1;
    i5 = 1;
    i6 = 0;
  } else {
    i4 = 3;
    i5 = 2;
    i6 = Vk->size[1];
    i7 = Vk->size[1] - 2;
    if ((i7 >= 1) && (i7 < i6)) {
      i6 = i7;
    } else {
      i6 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &i_emlrtBCI, sp);
    }
  }

  i7 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i7, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  i1 = r1->size[0];
  r1->size[0] = div_s32_floor(sp, i6 - i4, i5) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i6 - i4, i5);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    r1->data[i1] = (i4 + i5 * i1) - 1;
  }

  iv9[0] = 1;
  iv9[1] = Vk->size[2];
  for (i1 = 0; i1 < 2; i1++) {
    i2 = Vk->size[2];
    if ((iv9[i1] >= 1) && (iv9[i1] < i2)) {
      i14 = iv9[i1];
    } else {
      i14 = emlrtDynamicBoundsCheckR2012b(iv9[i1], 1, i2, &qm_emlrtBCI, sp);
    }

    iv1[i1] = i14 - 1;
  }

  emxInit_real32_T(sp, &r5, 3, &b_emlrtRTEI, true);
  loop_ub = V->size[0];
  b_loop_ub = V->size[1];
  iv10[0] = 1;
  iv10[1] = V->size[2];
  i1 = r5->size[0] * r5->size[1] * r5->size[2];
  r5->size[0] = loop_ub;
  r5->size[1] = b_loop_ub;
  r5->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)r5, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        i4 = V->size[2];
        if ((iv10[i1] >= 1) && (iv10[i1] < i4)) {
          i15 = iv10[i1];
        } else {
          i15 = emlrtDynamicBoundsCheckR2012b(iv10[i1], 1, i4, &rm_emlrtBCI, sp);
        }

        r5->data[(i3 + r5->size[0] * i2) + r5->size[0] * r5->size[1] * i1] =
          V->data[(i3 + V->size[0] * i2) + V->size[0] * V->size[1] * (i15 - 1)];
      }
    }
  }

  emxInit_real32_T(sp, &e_V, 3, &b_emlrtRTEI, true);
  iv11[0] = r0->size[0];
  iv11[1] = r1->size[0];
  iv11[2] = 2;
  loop_ub = V->size[0];
  b_loop_ub = V->size[1];
  iv12[0] = 1;
  iv12[1] = V->size[2];
  i1 = e_V->size[0] * e_V->size[1] * e_V->size[2];
  e_V->size[0] = loop_ub;
  e_V->size[1] = b_loop_ub;
  e_V->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)e_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        e_V->data[(i3 + e_V->size[0] * i2) + e_V->size[0] * e_V->size[1] * i1] =
          V->data[(i3 + V->size[0] * i2) + V->size[0] * V->size[1] * (iv12[i1] -
          1)];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = e_V->size[i1];
  }

  emxFree_real32_T(&e_V);
  emlrtSubAssignSizeCheckR2012b(iv11, 3, b_V, 3, &d_emlrtECI, sp);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = r5->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_loop_ub = r5->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        Vk->data[(r0->data[i3] + Vk->size[0] * r1->data[i2]) + Vk->size[0] *
          Vk->size[1] * iv1[i1]] = r5->data[(i3 + r5->size[0] * i2) + r5->size[0]
          * r5->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r5);
  emxFree_int32_T(&r1);

  /*  pad edges with inside values */
  if (3 > Vk->size[2] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[2];
    i4 = Vk->size[2] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &j_emlrtBCI, sp);
    }
  }

  iv13[0] = 1;
  iv13[1] = Vk->size[0];
  for (i4 = 0; i4 < 2; i4++) {
    i5 = Vk->size[0];
    if ((iv13[i4] >= 1) && (iv13[i4] < i5)) {
      i16 = iv13[i4];
    } else {
      i16 = emlrtDynamicBoundsCheckR2012b(iv13[i4], 1, i5, &sm_emlrtBCI, sp);
    }

    iv1[i4] = i16 - 1;
  }

  iv14[0] = 1;
  iv14[1] = Vk->size[1];
  for (i4 = 0; i4 < 2; i4++) {
    i5 = Vk->size[1];
    if ((iv14[i4] >= 1) && (iv14[i4] < i5)) {
      i17 = iv14[i4];
    } else {
      i17 = emlrtDynamicBoundsCheckR2012b(iv14[i4], 1, i5, &tm_emlrtBCI, sp);
    }

    iv0[i4] = i17 - 1;
  }

  i4 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i4, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  emxInit_real32_T(sp, &r6, 3, &b_emlrtRTEI, true);
  iv15[0] = 1;
  iv15[1] = V->size[0];
  iv16[0] = 1;
  iv16[1] = V->size[1];
  loop_ub = V->size[2];
  i1 = r6->size[0] * r6->size[1] * r6->size[2];
  r6->size[0] = 2;
  r6->size[1] = 2;
  r6->size[2] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)r6, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        i4 = V->size[0];
        i5 = V->size[1];
        if ((iv15[i3] >= 1) && (iv15[i3] < i4)) {
          i18 = iv15[i3];
        } else {
          i18 = emlrtDynamicBoundsCheckR2012b(iv15[i3], 1, i4, &um_emlrtBCI, sp);
        }

        if ((iv16[i2] >= 1) && (iv16[i2] < i5)) {
          i19 = iv16[i2];
        } else {
          i19 = emlrtDynamicBoundsCheckR2012b(iv16[i2], 1, i5, &vm_emlrtBCI, sp);
        }

        r6->data[(i3 + r6->size[0] * i2) + r6->size[0] * r6->size[1] * i1] =
          V->data[((i18 + V->size[0] * (i19 - 1)) + V->size[0] * V->size[1] * i1)
          - 1];
      }
    }
  }

  emxInit_real32_T(sp, &f_V, 3, &b_emlrtRTEI, true);
  iv17[0] = 2;
  iv17[1] = 2;
  iv17[2] = r0->size[0];
  iv18[0] = 1;
  iv18[1] = V->size[0];
  iv19[0] = 1;
  iv19[1] = V->size[1];
  loop_ub = V->size[2];
  i1 = f_V->size[0] * f_V->size[1] * f_V->size[2];
  f_V->size[0] = 2;
  f_V->size[1] = 2;
  f_V->size[2] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)f_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        f_V->data[(i3 + f_V->size[0] * i2) + f_V->size[0] * f_V->size[1] * i1] =
          V->data[((iv18[i3] + V->size[0] * (iv19[i2] - 1)) + V->size[0] *
                   V->size[1] * i1) - 1];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = f_V->size[i1];
  }

  emxFree_real32_T(&f_V);
  emlrtSubAssignSizeCheckR2012b(iv17, 3, b_V, 3, &e_emlrtECI, sp);
  loop_ub = r6->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        Vk->data[(iv1[i3] + Vk->size[0] * iv0[i2]) + Vk->size[0] * Vk->size[1] *
          r0->data[i1]] = r6->data[(i3 + r6->size[0] * i2) + r6->size[0] *
          r6->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r6);
  if (3 > Vk->size[1] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[1];
    i4 = Vk->size[1] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &k_emlrtBCI, sp);
    }
  }

  iv20[0] = 1;
  iv20[1] = Vk->size[0];
  for (i4 = 0; i4 < 2; i4++) {
    i5 = Vk->size[0];
    if ((iv20[i4] >= 1) && (iv20[i4] < i5)) {
      i20 = iv20[i4];
    } else {
      i20 = emlrtDynamicBoundsCheckR2012b(iv20[i4], 1, i5, &wm_emlrtBCI, sp);
    }

    iv1[i4] = i20 - 1;
  }

  i4 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i4, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  iv21[0] = 1;
  iv21[1] = Vk->size[2];
  for (i1 = 0; i1 < 2; i1++) {
    i2 = Vk->size[2];
    if ((iv21[i1] >= 1) && (iv21[i1] < i2)) {
      i21 = iv21[i1];
    } else {
      i21 = emlrtDynamicBoundsCheckR2012b(iv21[i1], 1, i2, &xm_emlrtBCI, sp);
    }

    iv0[i1] = i21 - 1;
  }

  emxInit_real32_T(sp, &r7, 3, &b_emlrtRTEI, true);
  iv22[0] = 1;
  iv22[1] = V->size[0];
  loop_ub = V->size[1];
  iv23[0] = 1;
  iv23[1] = V->size[2];
  i1 = r7->size[0] * r7->size[1] * r7->size[2];
  r7->size[0] = 2;
  r7->size[1] = loop_ub;
  r7->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)r7, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        i4 = V->size[0];
        i5 = V->size[2];
        if ((iv22[i3] >= 1) && (iv22[i3] < i4)) {
          i22 = iv22[i3];
        } else {
          i22 = emlrtDynamicBoundsCheckR2012b(iv22[i3], 1, i4, &ym_emlrtBCI, sp);
        }

        if ((iv23[i1] >= 1) && (iv23[i1] < i5)) {
          i23 = iv23[i1];
        } else {
          i23 = emlrtDynamicBoundsCheckR2012b(iv23[i1], 1, i5, &an_emlrtBCI, sp);
        }

        r7->data[(i3 + r7->size[0] * i2) + r7->size[0] * r7->size[1] * i1] =
          V->data[((i22 + V->size[0] * i2) + V->size[0] * V->size[1] * (i23 - 1))
          - 1];
      }
    }
  }

  emxInit_real32_T(sp, &g_V, 3, &b_emlrtRTEI, true);
  iv24[0] = 2;
  iv24[1] = r0->size[0];
  iv24[2] = 2;
  iv25[0] = 1;
  iv25[1] = V->size[0];
  loop_ub = V->size[1];
  iv26[0] = 1;
  iv26[1] = V->size[2];
  i1 = g_V->size[0] * g_V->size[1] * g_V->size[2];
  g_V->size[0] = 2;
  g_V->size[1] = loop_ub;
  g_V->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)g_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        g_V->data[(i3 + g_V->size[0] * i2) + g_V->size[0] * g_V->size[1] * i1] =
          V->data[((iv25[i3] + V->size[0] * i2) + V->size[0] * V->size[1] *
                   (iv26[i1] - 1)) - 1];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = g_V->size[i1];
  }

  emxFree_real32_T(&g_V);
  emlrtSubAssignSizeCheckR2012b(iv24, 3, b_V, 3, &f_emlrtECI, sp);
  for (i1 = 0; i1 < 2; i1++) {
    loop_ub = r7->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        Vk->data[(iv1[i3] + Vk->size[0] * r0->data[i2]) + Vk->size[0] * Vk->
          size[1] * iv0[i1]] = r7->data[(i3 + r7->size[0] * i2) + r7->size[0] *
          r7->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r7);
  if (3 > Vk->size[0] - 2) {
    i1 = 1;
    i2 = 1;
    i3 = 0;
  } else {
    i1 = 3;
    i2 = 2;
    i3 = Vk->size[0];
    i4 = Vk->size[0] - 2;
    if ((i4 >= 1) && (i4 < i3)) {
      i3 = i4;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &l_emlrtBCI, sp);
    }
  }

  i4 = r0->size[0];
  r0->size[0] = div_s32_floor(sp, i3 - i1, i2) + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i4, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  loop_ub = div_s32_floor(sp, i3 - i1, i2);
  for (i3 = 0; i3 <= loop_ub; i3++) {
    r0->data[i3] = (i1 + i2 * i3) - 1;
  }

  iv27[0] = 1;
  iv27[1] = Vk->size[1];
  for (i1 = 0; i1 < 2; i1++) {
    i2 = Vk->size[1];
    if ((iv27[i1] >= 1) && (iv27[i1] < i2)) {
      i24 = iv27[i1];
    } else {
      i24 = emlrtDynamicBoundsCheckR2012b(iv27[i1], 1, i2, &bn_emlrtBCI, sp);
    }

    iv1[i1] = i24 - 1;
  }

  iv28[0] = 1;
  iv28[1] = Vk->size[2];
  for (i1 = 0; i1 < 2; i1++) {
    i2 = Vk->size[2];
    if ((iv28[i1] >= 1) && (iv28[i1] < i2)) {
      i25 = iv28[i1];
    } else {
      i25 = emlrtDynamicBoundsCheckR2012b(iv28[i1], 1, i2, &cn_emlrtBCI, sp);
    }

    iv0[i1] = i25 - 1;
  }

  emxInit_real32_T(sp, &r8, 3, &b_emlrtRTEI, true);
  loop_ub = V->size[0];
  iv29[0] = 1;
  iv29[1] = V->size[1];
  iv30[0] = 1;
  iv30[1] = V->size[2];
  i1 = r8->size[0] * r8->size[1] * r8->size[2];
  r8->size[0] = loop_ub;
  r8->size[1] = 2;
  r8->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)r8, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        i4 = V->size[1];
        i5 = V->size[2];
        if ((iv29[i2] >= 1) && (iv29[i2] < i4)) {
          i26 = iv29[i2];
        } else {
          i26 = emlrtDynamicBoundsCheckR2012b(iv29[i2], 1, i4, &dn_emlrtBCI, sp);
        }

        if ((iv30[i1] >= 1) && (iv30[i1] < i5)) {
          i27 = iv30[i1];
        } else {
          i27 = emlrtDynamicBoundsCheckR2012b(iv30[i1], 1, i5, &en_emlrtBCI, sp);
        }

        r8->data[(i3 + r8->size[0] * i2) + r8->size[0] * r8->size[1] * i1] =
          V->data[(i3 + V->size[0] * (i26 - 1)) + V->size[0] * V->size[1] * (i27
          - 1)];
      }
    }
  }

  emxInit_real32_T(sp, &h_V, 3, &b_emlrtRTEI, true);
  iv31[0] = r0->size[0];
  iv31[1] = 2;
  iv31[2] = 2;
  loop_ub = V->size[0];
  iv32[0] = 1;
  iv32[1] = V->size[1];
  iv33[0] = 1;
  iv33[1] = V->size[2];
  i1 = h_V->size[0] * h_V->size[1] * h_V->size[2];
  h_V->size[0] = loop_ub;
  h_V->size[1] = 2;
  h_V->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)h_V, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        h_V->data[(i3 + h_V->size[0] * i2) + h_V->size[0] * h_V->size[1] * i1] =
          V->data[(i3 + V->size[0] * (iv32[i2] - 1)) + V->size[0] * V->size[1] *
          (iv33[i1] - 1)];
      }
    }
  }

  for (i1 = 0; i1 < 3; i1++) {
    b_V[i1] = h_V->size[i1];
  }

  emxFree_real32_T(&h_V);
  emlrtSubAssignSizeCheckR2012b(iv31, 3, b_V, 3, &g_emlrtECI, sp);
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      loop_ub = r8->size[0];
      for (i3 = 0; i3 < loop_ub; i3++) {
        Vk->data[(r0->data[i3] + Vk->size[0] * iv1[i2]) + Vk->size[0] * Vk->
          size[1] * iv0[i1]] = r8->data[(i3 + r8->size[0] * i2) + r8->size[0] *
          r8->size[1] * i1];
      }
    }
  }

  emxFree_real32_T(&r8);
  emxFree_int32_T(&r0);

  /*  pad corners with inside values */
  b_loop_ub = Vk->size[0];
  b_Vk = Vk->size[0];
  iv34[0] = 1;
  iv34[1] = b_loop_ub;
  b_loop_ub = Vk->size[1];
  loop_ub = Vk->size[1];
  iv35[0] = 1;
  iv35[1] = b_loop_ub;
  b_loop_ub = Vk->size[2];
  c_Vk = Vk->size[2];
  iv36[0] = 1;
  iv36[1] = b_loop_ub;
  iv37[0] = 1;
  iv37[1] = V->size[0];
  iv38[0] = 1;
  iv38[1] = V->size[1];
  iv39[0] = 1;
  iv39[1] = V->size[2];
  for (i1 = 0; i1 < 2; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < 2; i3++) {
        i4 = V->size[0];
        i5 = V->size[1];
        i6 = V->size[2];
        if ((iv34[i3] >= 1) && (iv34[i3] < b_Vk)) {
          i28 = iv34[i3];
        } else {
          i28 = emlrtDynamicBoundsCheckR2012b(iv34[i3], 1, b_Vk, &in_emlrtBCI,
            sp);
        }

        if ((iv35[i2] >= 1) && (iv35[i2] < loop_ub)) {
          i29 = iv35[i2];
        } else {
          i29 = emlrtDynamicBoundsCheckR2012b(iv35[i2], 1, loop_ub, &jn_emlrtBCI,
            sp);
        }

        if ((iv36[i1] >= 1) && (iv36[i1] < c_Vk)) {
          i30 = iv36[i1];
        } else {
          i30 = emlrtDynamicBoundsCheckR2012b(iv36[i1], 1, c_Vk, &kn_emlrtBCI,
            sp);
        }

        if ((iv37[i3] >= 1) && (iv37[i3] < i4)) {
          i31 = iv37[i3];
        } else {
          i31 = emlrtDynamicBoundsCheckR2012b(iv37[i3], 1, i4, &fn_emlrtBCI, sp);
        }

        if ((iv38[i2] >= 1) && (iv38[i2] < i5)) {
          i32 = iv38[i2];
        } else {
          i32 = emlrtDynamicBoundsCheckR2012b(iv38[i2], 1, i5, &gn_emlrtBCI, sp);
        }

        if ((iv39[i1] >= 1) && (iv39[i1] < i6)) {
          i33 = iv39[i1];
        } else {
          i33 = emlrtDynamicBoundsCheckR2012b(iv39[i1], 1, i6, &hn_emlrtBCI, sp);
        }

        Vk->data[((i28 + Vk->size[0] * (i29 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i30 - 1)) - 1] = V->data[((i31 + V->size[0] * (i32 - 1)) +
          V->size[0] * V->size[1] * (i33 - 1)) - 1];
      }
    }
  }

  i1 = (int32_T)(((Vksize[0] - 2.0) + -1.0) / 2.0);
  emlrtForLoopVectorCheckR2012b(3.0, 2.0, Vksize[0] - 2.0, mxDOUBLE_CLASS, i1,
    &e_emlrtRTEI, sp);
  b_Vk = 0;
  while (b_Vk <= i1 - 1) {
    ii = 3U + ((uint32_T)b_Vk << 1);
    i2 = (int32_T)(((Vksize[1] - 2.0) + -1.0) / 2.0);
    emlrtForLoopVectorCheckR2012b(3.0, 2.0, Vksize[1] - 2.0, mxDOUBLE_CLASS, i2,
      &f_emlrtRTEI, sp);
    c_Vk = 0;
    while (c_Vk <= i2 - 1) {
      jj = 3U + ((uint32_T)c_Vk << 1);
      i3 = (int32_T)(((Vksize[2] - 2.0) + -1.0) / 2.0);
      emlrtForLoopVectorCheckR2012b(3.0, 2.0, Vksize[2] - 2.0, mxDOUBLE_CLASS,
        i3, &g_emlrtRTEI, sp);
      b_loop_ub = 0;
      while (b_loop_ub <= i3 - 1) {
        kk = 3U + ((uint32_T)b_loop_ub << 1);

        /* ============================================================== */
        /*  6 Close Neighbours */
        /* ============================================================== */
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &m_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &n_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &o_emlrtBCI, sp);
        Vkhalf = 0.5F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1))
          + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &p_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &q_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &r_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i34 = i5;
        } else {
          i34 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ln_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i35 = i7;
        } else {
          i35 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &mn_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i36 = i9;
        } else {
          i36 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &nn_emlrtBCI, sp);
        }

        Vk->data[((i34 + Vk->size[0] * (i35 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i36 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &s_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &t_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &u_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i37 = i5;
        } else {
          i37 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &on_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i38 = i7;
        } else {
          i38 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &pn_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i39 = i9;
        } else {
          i39 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &qn_emlrtBCI, sp);
        }

        Vk->data[((i37 + Vk->size[0] * (i38 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i39 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)((real_T)
          ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size
          [1] * ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &v_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &w_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &x_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i40 = i5;
        } else {
          i40 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rn_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i41 = i7;
        } else {
          i41 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &sn_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i42 = i9;
        } else {
          i42 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &tn_emlrtBCI, sp);
        }

        Vk->data[((i40 + Vk->size[0] * (i41 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i42 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &y_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ab_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i43 = i5;
        } else {
          i43 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &un_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i44 = i7;
        } else {
          i44 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &vn_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i45 = i9;
        } else {
          i45 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &wn_emlrtBCI, sp);
        }

        Vk->data[((i43 + Vk->size[0] * (i44 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i45 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cb_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &db_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &eb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i46 = i5;
        } else {
          i46 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xn_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i47 = i7;
        } else {
          i47 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &yn_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i48 = i9;
        } else {
          i48 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &ao_emlrtBCI, sp);
        }

        Vk->data[((i46 + Vk->size[0] * (i47 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i48 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fb_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i49 = i5;
        } else {
          i49 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bo_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i50 = i7;
        } else {
          i50 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &co_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i51 = i9;
        } else {
          i51 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &do_emlrtBCI, sp);
        }

        Vk->data[((i49 + Vk->size[0] * (i50 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i51 - 1)) - 1] = Vkhalf + 0.5F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)((real_T)kk + 2.0) - 1)) - 1];

        /* ============================================================== */
        /*  12 Intermediate Neighbours */
        /* ============================================================== */
        Vkquart = 0.5F * Vkhalf;
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ib_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lb_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ob_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i52 = i5;
        } else {
          i52 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &eo_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i53 = i7;
        } else {
          i53 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &fo_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i54 = i9;
        } else {
          i54 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &go_emlrtBCI, sp);
        }

        Vk->data[((i52 + Vk->size[0] * (i53 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i54 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1))
          - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj -
          3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rb_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ub_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wb_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xb_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yb_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ac_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i55 = i5;
        } else {
          i55 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ho_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i56 = i7;
        } else {
          i56 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &io_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i57 = i9;
        } else {
          i57 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &jo_emlrtBCI, sp);
        }

        Vk->data[((i55 + Vk->size[0] * (i56 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i57 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ec_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ic_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i58 = i5;
        } else {
          i58 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ko_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i59 = i7;
        } else {
          i59 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &lo_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i60 = i9;
        } else {
          i60 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &mo_emlrtBCI, sp);
        }

        Vk->data[((i58 + Vk->size[0] * (i59 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i60 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &oc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk;
        if ((i5 >= 1) && (i5 < i4)) {
          i61 = i5;
        } else {
          i61 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &no_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i62 = i7;
        } else {
          i62 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &oo_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i63 = i9;
        } else {
          i63 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &po_emlrtBCI, sp);
        }

        Vk->data[((i61 + Vk->size[0] * (i62 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i63 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1))
          + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &uc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wc_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xc_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yc_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ad_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cd_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i64 = i5;
        } else {
          i64 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qo_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i65 = i7;
        } else {
          i65 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &ro_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i66 = i9;
        } else {
          i66 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &so_emlrtBCI, sp);
        }

        Vk->data[((i64 + Vk->size[0] * (i65 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i66 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3))
          - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ed_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fd_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &id_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ld_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i67 = i5;
        } else {
          i67 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &to_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i68 = i7;
        } else {
          i68 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &uo_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i69 = i9;
        } else {
          i69 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &vo_emlrtBCI, sp);
        }

        Vk->data[((i67 + Vk->size[0] * (i68 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i69 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &md_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &od_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rd_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &td_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ud_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i70 = i5;
        } else {
          i70 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wo_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i71 = i7;
        } else {
          i71 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &xo_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i72 = i9;
        } else {
          i72 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &yo_emlrtBCI, sp);
        }

        Vk->data[((i70 + Vk->size[0] * (i71 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i72 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)
          kk + 2.0) - 1)) - 3]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wd_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xd_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yd_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ae_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &be_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ce_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &de_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ee_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i73 = i5;
        } else {
          i73 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ap_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i74 = i7;
        } else {
          i74 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &bp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i75 = i9;
        } else {
          i75 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &cp_emlrtBCI, sp);
        }

        Vk->data[((i73 + Vk->size[0] * (i74 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i75 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1]) + 0.25F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fe_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ge_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &he_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ie_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &je_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ke_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &le_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &me_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ne_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i76 = i5;
        } else {
          i76 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i77 = i7;
        } else {
          i77 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &ep_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i78 = i9;
        } else {
          i78 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &fp_emlrtBCI, sp);
        }

        Vk->data[((i76 + Vk->size[0] * (i77 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i78 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3))
          - 1]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &oe_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pe_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qe_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &re_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &se_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &te_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ue_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ve_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &we_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i79 = i5;
        } else {
          i79 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i80 = i7;
        } else {
          i80 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &hp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i81 = i9;
        } else {
          i81 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &ip_emlrtBCI, sp);
        }

        Vk->data[((i79 + Vk->size[0] * (i80 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i81 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xe_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ye_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &af_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cf_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &df_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ef_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ff_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i82 = i5;
        } else {
          i82 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i83 = i7;
        } else {
          i83 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &kp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i84 = i9;
        } else {
          i84 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &lp_emlrtBCI, sp);
        }

        Vk->data[((i82 + Vk->size[0] * (i83 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i84 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0]
          * ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)
          kk + 2.0) - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &if_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lf_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &of_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i85 = i5;
        } else {
          i85 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i86 = i7;
        } else {
          i86 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &np_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i87 = i9;
        } else {
          i87 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &op_emlrtBCI, sp);
        }

        Vk->data[((i85 + Vk->size[0] * (i86 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i87 - 1)) - 1] = ((Vkquart + 0.25F * Vk->data[(((int32_T)ii +
          Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.25F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1]) + 0.25F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1];

        /* ============================================================== */
        /*  8 Furthest Neighbours */
        /* ============================================================== */
        Vkeighth = 0.5F * Vkquart;
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rf_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &uf_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wf_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xf_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yf_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ag_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cg_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &eg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fg_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ig_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lg_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i88 = i5;
        } else {
          i88 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i89 = i7;
        } else {
          i89 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &qp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i90 = i9;
        } else {
          i90 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &rp_emlrtBCI, sp);
        }

        Vk->data[((i88 + Vk->size[0] * (i89 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i90 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 3)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 3)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ng_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &og_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rg_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ug_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wg_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xg_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yg_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ah_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ch_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &eh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i91 = i5;
        } else {
          i91 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i92 = i7;
        } else {
          i92 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &tp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i93 = i9;
        } else {
          i93 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &up_emlrtBCI, sp);
        }

        Vk->data[((i91 + Vk->size[0] * (i92 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i93 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj -
          3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F * Vk->
          data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1))
                + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F *
          Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj -
          3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F * Vk->
          data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
                Vk->size[1] * ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ih_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &oh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ph_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &th_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &uh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wh_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xh_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yh_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ai_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bi_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ci_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &di_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i94 = i5;
        } else {
          i94 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i95 = i7;
        } else {
          i95 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &wp_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i96 = i9;
        } else {
          i96 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &xp_emlrtBCI, sp);
        }

        Vk->data[((i94 + Vk->size[0] * (i95 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i96 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)kk - 3)) - 3]) + 0.125F * Vk->
          data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1))
                + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 3]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ei_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fi_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gi_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hi_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ii_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ji_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ki_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &li_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mi_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ni_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &oi_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pi_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qi_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ri_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &si_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ti_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ui_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vi_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wi_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xi_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yi_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)kk - 1;
        if ((i5 >= 1) && (i5 < i4)) {
          i97 = i5;
        } else {
          i97 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yp_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i98 = i7;
        } else {
          i98 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &aq_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i99 = i9;
        } else {
          i99 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &bq_emlrtBCI, sp);
        }

        Vk->data[((i97 + Vk->size[0] * (i98 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i99 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)
          ((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk -
          1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)
          ((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk -
          1)) - 1]) + 0.125F * Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->
          size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)
          kk - 3)) - 1]) + 0.125F * Vk->data[(((int32_T)((real_T)ii + 2.0) +
          Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] *
          Vk->size[1] * ((int32_T)kk - 3)) - 1]) + 0.125F * Vk->data[(((int32_T)
          ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)kk - 3)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &aj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ej_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ij_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &oj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &uj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i100 = i5;
        } else {
          i100 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cq_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i101 = i7;
        } else {
          i101 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &dq_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i102 = i9;
        } else {
          i102 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &eq_emlrtBCI, sp);
        }

        Vk->data[((i100 + Vk->size[0] * (i101 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i102 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 3]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 3]) +
          0.125F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) +
                             Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk +
          2.0) - 1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wj_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xj_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yj_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ak_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ck_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ek_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fk_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ik_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lk_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &mk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ok_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &qk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)jj - 1;
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i103 = i5;
        } else {
          i103 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fq_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i104 = i7;
        } else {
          i104 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &gq_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i105 = i9;
        } else {
          i105 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &hq_emlrtBCI, sp);
        }

        Vk->data[((i103 + Vk->size[0] * (i104 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i105 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj -
          3)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 3)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F * Vk->
          data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1))
                + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1))
          - 1]) + 0.125F * Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] *
          ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 3)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rk_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &uk_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wk_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xk_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yk_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &al_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cl_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii - 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &el_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fl_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &il_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &jl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &kl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ll_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ml_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii - 1;
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i106 = i5;
        } else {
          i106 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &iq_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i107 = i7;
        } else {
          i107 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &jq_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i108 = i9;
        } else {
          i108 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &kq_emlrtBCI, sp);
        }

        Vk->data[((i106 + Vk->size[0] * (i107 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i108 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 3]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) -
          1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0]
                    * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 3]) +
          0.125F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj
          + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk + 2.0)
          - 1)) - 3]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] *
          ((int32_T)((real_T)kk + 2.0) - 1)) - 1]) + 0.125F * Vk->data
          [(((int32_T)ii + Vk->size[0] * ((int32_T)jj - 1)) + Vk->size[0] *
            Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1];
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &nl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ol_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &pl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ql_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &rl_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &sl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &tl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &ul_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)kk;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &vl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &wl_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &xl_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &yl_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)((real_T)ii + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &am_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &bm_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &cm_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &dm_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)((real_T)jj + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &em_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &fm_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)ii;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &gm_emlrtBCI, sp);
        i4 = Vk->size[1];
        i5 = (int32_T)jj;
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &hm_emlrtBCI, sp);
        i4 = Vk->size[2];
        i5 = (int32_T)((real_T)kk + 2.0);
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &im_emlrtBCI, sp);
        i4 = Vk->size[0];
        i5 = (int32_T)(ii + 1U);
        i6 = Vk->size[1];
        i7 = (int32_T)(jj + 1U);
        i8 = Vk->size[2];
        i9 = (int32_T)(kk + 1U);
        if ((i5 >= 1) && (i5 < i4)) {
          i109 = i5;
        } else {
          i109 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &lq_emlrtBCI, sp);
        }

        if ((i7 >= 1) && (i7 < i6)) {
          i110 = i7;
        } else {
          i110 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &mq_emlrtBCI, sp);
        }

        if ((i9 >= 1) && (i9 < i8)) {
          i111 = i9;
        } else {
          i111 = emlrtDynamicBoundsCheckR2012b(i9, 1, i8, &nq_emlrtBCI, sp);
        }

        Vk->data[((i109 + Vk->size[0] * (i110 - 1)) + Vk->size[0] * Vk->size[1] *
                  (i111 - 1)) - 1] = ((((((Vkeighth + 0.125F * Vk->data
          [(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)jj - 1)) +
            Vk->size[0] * Vk->size[1] * ((int32_T)kk - 1)) - 1]) + 0.125F *
          Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->size[0] * ((int32_T)
          ((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk -
          1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)
          ((real_T)jj + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)kk -
          1)) - 1]) + 0.125F * Vk->data[(((int32_T)((real_T)ii + 2.0) + Vk->
          size[0] * ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)
          ((real_T)kk + 2.0) - 1)) - 1]) + 0.125F * Vk->data[(((int32_T)((real_T)
          ii + 2.0) + Vk->size[0] * ((int32_T)((real_T)jj + 2.0) - 1)) +
          Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk + 2.0) - 1)) - 1]) +
          0.125F * Vk->data[(((int32_T)ii + Vk->size[0] * ((int32_T)((real_T)jj
          + 2.0) - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk + 2.0)
          - 1)) - 1]) + 0.125F * Vk->data[(((int32_T)ii + Vk->size[0] *
          ((int32_T)jj - 1)) + Vk->size[0] * Vk->size[1] * ((int32_T)((real_T)kk
          + 2.0) - 1)) - 1];
        b_loop_ub++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      c_Vk++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    b_Vk++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Crop Vk to 2*size(V)-1 */
  if (3 > Vk->size[0] - 2) {
    i1 = 0;
    i2 = 0;
  } else {
    i1 = 2;
    i2 = Vk->size[0];
    i3 = Vk->size[0] - 2;
    if ((i3 >= 1) && (i3 < i2)) {
      i2 = i3;
    } else {
      i2 = emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &jm_emlrtBCI, sp);
    }
  }

  if (3 > Vk->size[1] - 2) {
    i3 = 0;
    i4 = 0;
  } else {
    i3 = 2;
    i4 = Vk->size[1];
    i5 = Vk->size[1] - 2;
    if ((i5 >= 1) && (i5 < i4)) {
      i4 = i5;
    } else {
      i4 = emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &km_emlrtBCI, sp);
    }
  }

  if (3 > Vk->size[2] - 2) {
    i5 = 0;
    i6 = 0;
  } else {
    i5 = 2;
    i6 = Vk->size[2];
    i7 = Vk->size[2] - 2;
    if ((i7 >= 1) && (i7 < i6)) {
      i6 = i7;
    } else {
      i6 = emlrtDynamicBoundsCheckR2012b(i7, 1, i6, &lm_emlrtBCI, sp);
    }
  }

  emxInit_real32_T(sp, &d_Vk, 3, &b_emlrtRTEI, true);
  i7 = d_Vk->size[0] * d_Vk->size[1] * d_Vk->size[2];
  d_Vk->size[0] = i2 - i1;
  d_Vk->size[1] = i4 - i3;
  d_Vk->size[2] = i6 - i5;
  emxEnsureCapacity(sp, (emxArray__common *)d_Vk, i7, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  loop_ub = i6 - i5;
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_loop_ub = i4 - i3;
    for (i7 = 0; i7 < b_loop_ub; i7++) {
      b_Vk = i2 - i1;
      for (i8 = 0; i8 < b_Vk; i8++) {
        d_Vk->data[(i8 + d_Vk->size[0] * i7) + d_Vk->size[0] * d_Vk->size[1] *
          i6] = Vk->data[((i1 + i8) + Vk->size[0] * (i3 + i7)) + Vk->size[0] *
          Vk->size[1] * (i5 + i6)];
      }
    }
  }

  i1 = Vk->size[0] * Vk->size[1] * Vk->size[2];
  Vk->size[0] = d_Vk->size[0];
  Vk->size[1] = d_Vk->size[1];
  Vk->size[2] = d_Vk->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Vk, i1, (int32_T)sizeof(real32_T),
                    &b_emlrtRTEI);
  loop_ub = d_Vk->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = d_Vk->size[1];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_Vk = d_Vk->size[0];
      for (i3 = 0; i3 < b_Vk; i3++) {
        Vk->data[(i3 + Vk->size[0] * i2) + Vk->size[0] * Vk->size[1] * i1] =
          d_Vk->data[(i3 + d_Vk->size[0] * i2) + d_Vk->size[0] * d_Vk->size[1] *
          i1];
      }
    }
  }

  emxFree_real32_T(&d_Vk);

  /* ========================================================================== */
  /*  MEX Build Script */
  /* ========================================================================== */
  /* { */
  /*  */
  /* InitialVars     =	whos; */
  /* InitialVarNames	=	{InitialVars.name}; */
  /*  */
  /* SINGLE	=   zeros(1,'single'); */
  /* DOUBLE	=   zeros(1,'double'); */
  /* FUNC	=   'refineGrid3D_conv'; */
  /* ARGS	=	{	coder.typeof( SINGLE, [512,512,512],	[1,1,1] ),	... */
  /*                 coder.typeof( DOUBLE, [1,1],            [0,0]	)	}; */
  /*  */
  /* CurrentDirectory	=   cd; */
  /* goto(FUNC), codegen refineGrid3D_conv -args ARGS */
  /* cd(CurrentDirectory) */
  /*  */
  /* fprintf( 'Code generation completed for:\t%s\n', FUNC ); */
  /* clearvars('-except',InitialVarNames{:}); */
  /*  */
  /* } */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void refineGrid3D_conv(const emlrtStack *sp, const emxArray_real32_T *V, real_T
  K, emxArray_real32_T *Vk)
{
  int32_T i0;
  int32_T loop_ub;
  int32_T k;
  emxArray_real32_T *b_Vk;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* REFINEGRID3D_CONV Returns the interpolated values on a refined grid formed */
  /*  by repeatedly dividing the intervals K times in each dimension. */
  i0 = Vk->size[0] * Vk->size[1] * Vk->size[2];
  Vk->size[0] = V->size[0];
  Vk->size[1] = V->size[1];
  Vk->size[2] = V->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)Vk, i0, (int32_T)sizeof(real32_T),
                    &emlrtRTEI);
  loop_ub = V->size[0] * V->size[1] * V->size[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Vk->data[i0] = V->data[i0];
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, K, mxDOUBLE_CLASS, (int32_T)K,
    &d_emlrtRTEI, sp);
  k = 0;
  emxInit_real32_T(sp, &b_Vk, 3, &emlrtRTEI, true);
  while (k <= (int32_T)K - 1) {
    i0 = b_Vk->size[0] * b_Vk->size[1] * b_Vk->size[2];
    b_Vk->size[0] = Vk->size[0];
    b_Vk->size[1] = Vk->size[1];
    b_Vk->size[2] = Vk->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)b_Vk, i0, (int32_T)sizeof(real32_T),
                      &emlrtRTEI);
    loop_ub = Vk->size[0] * Vk->size[1] * Vk->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_Vk->data[i0] = Vk->data[i0];
    }

    st.site = &emlrtRSI;
    refineGrid3D_conv_Once(&st, b_Vk, Vk);
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&b_Vk);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (refineGrid3D_conv.c) */
