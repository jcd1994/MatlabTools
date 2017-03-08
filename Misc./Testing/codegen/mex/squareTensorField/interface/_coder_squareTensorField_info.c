/*
 * _coder_squareTensorField_info.c
 *
 * Code generation for function '_coder_squareTensorField_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "_coder_squareTensorField_info.h"
#include "squareTensorField_data.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("squareTensorField"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.0.0.341360 (R2016a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "CoverageInfo", covrtSerializeInstanceData
                (&emlrtCoverageInstance));
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[14] = {
    "789ced5ccd6fdc44149fd010caa17c5d4a510b5d0e0811292e454250400a1f8d362881a804a9528516af77bc1e32f698196f76539512e0d23f8103122b4ebdc1"
    "81bf801317240e45e2cc817f812378d6deaf89b363d61fbb9b3c4bd6fac5f326eff7667e7ef39e3fd0d2e6360ab7c7c2dda708ad84bf67c3fd21146d0fc7f252",
    "b857e2dfe8efcbe85c2c7f1dee16f302dc09a2939ee962d4df1acc259ee905bb073e461c0b46f771a377c62614ef12176fb111a14a42c1dd18393510e429ee88"
    "41cf888e0ad12671dc43431ccb09386e8ce07822966f5dffe4dd6bc6c7027361bccf3c33704ccf788f33bfce3ac60e679f612b10c6b61950b36e6c1fec3246e5",
    "995d2c02e2350df179cbe478177b82f10d826963cd1ddaf39ac69e47147ba41c7688f16d9c4a7f45d15fe979bd55a738faffdf6af49b8abe946f6d6edd4c7409"
    "6b7b94998d9e2f9c36e37be272e495cb37ae5e79f955d3887f82d843d8a5062575c38d5c87697860c4e84227a9f85612ec5b1ab1efd1f8ef081dfedac47fbc3d",
    "bd7ef2f8cc42ffc511fda5047d34f23b4dfbfb68f2f807687cfca55cd2f857e2a39a20b771dfdeaac6dea7157ba56cb106e66b24bc0871cfa4e141037776684b"
    "e4c19fae46df55f4ddbcfd27f7d51e4263b50fd11840ec5d6a32ccc3bf2e060f804729dacffb7554c79bf38a7d525678232c939afc7a3397b8d3d5e853459fe6",
    "edaf44def42146113ac3bcfbf99f0f21fea469df458b310fd635769e53ec9432115ecbc59c58815cdea65bef65e5cd9ea2bf97b7bfe475c6261ddcf059e82e63"
    "0c63bcb0cd30ef5eaf5f00de9c24dee8e6fb59c54e2913619330823965e437b6a26fe7eda7237c89b0490f014f4e417ea3e149c5265c0436e9db7b4563eff298",
    "bdcb3dae94c193baa25fcfdb4f093c39ae4e023c39aa8f50369eccfbf8af6bec4bbbfefabffcb21c93c3ba0b78d26f3fef79fe8ec6be6715fba41c765b0be754"
    "cd669c32e6d7d83ee63665ed9ae5606b4fcf9bfe36da6fdf5f3f69ecb9a3e8dd29d25f51389e80356bde7ff806f0285dfb3fd1e479f1031a9f17529ee5bca84c",
    "6e507330f5311fe29b761d57d5e8a5a8d3f58abf9b5eb010711de215f02c0bcfa6c97bc2ee5db3936d3d38177585b17540842a635d01e257caf6c0ab645e11ef"
    "24f28a78c0ab7278750f4d1eff797b3e278907aecfda924b65d4e51a8abe948be203f3851161cb9c27bd097c48d77edec75f576f784eb14fca6abe22de69111a",
    "6c7a1f4415ad5c78735fa33f9bbabf0a35f373060f5efa0d9ecf39093c9aee3e69d821279d32e28ca3e83b05fa275e77c5e8d65c5877013faa1afb92ea62d1fc"
    "a9054c263eb889792d5a98e5c1175d5dfbaea27f37f6d74e510ef339d937036c1c033a63fef216f0285dfb459d17ba7cfdcc98dd67905917a5e43796a26fa122",
    "e38eddf28c1059e6fba9875b9fbe007cc923eecc7afc21bf81fc0678543c8f2e28f64939f1fd8335197986b8a77d2ea1abb187297a2c6f7f25f26735c218fb2e"
    "43fcb9f4f735883f2781373735f63dafd827658537a6efd3838f7a136ba3e5590161de10ffbaa6ffc795fea56cc7bdd442d00d8a53c5a3b6d24f3b6f3f26f229",
    "017a365e9dfff715e0559af68b361f8a8a4f45bfef0371ea74f06951eb0af07c0e3c9f330bbefc8e268fff77687cfca53c5bbe548667846b52aa14ad11d4e9a0"
    "4e77bc3ef0693a3e5535b8e0bb08f05d8479cc9fe6edbd5578ef08de3b5a045e9dd638f6a4824bca724eba0171b1187bfc7bb1ebea8a7b8f60cc56af80e75653",
    "b6d75d7fbf40e3f340ca25cf838ac55c9779d1155820b8df0bf77bf3d32f9a5f5db418d759c8af20bf02fe4ccf9f1cee4bd5a929d63a4decba23f88bfa0eca8c"
    "ee47498c460f63b6f5ddd5a56f803f0bc19f94f340c79f67143ba59cc41fe251e2e121fea2f2235fd1f34bf45b8431d3fb16bf3cf515acdf4e137f52e4433dfe",
    "b404ae716ccbe34cfcd1e5412d45af55a2df463066fdee36f028657b5d9de14b343e1fa45c328f2a752c0bbd81c3b170186da4e2d525c56e2927f16ad86bb675"
    "9d8e5742b14794e8c701c6ecdfb9035ea56cdf458b119faa1a3ba1be00f505e0cff4ebbb8b8a9d5256f8d35ff20c4a0c45c621aed8c3cbf15b8c71e0bac1384f",
    "5967f8f1fb3de091aefd7f64300405", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 27776U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_squareTensorField_info.c) */
