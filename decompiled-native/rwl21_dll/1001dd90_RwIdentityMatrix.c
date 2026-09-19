// 1001dd90 RwIdentityMatrix [Global]
// programa: RWL21.DLL

undefined4 * RwIdentityMatrix(undefined4 *param_1)

{
                    /* 0x1dd90  275  RwIdentityMatrix */
  if (param_1 != (undefined4 *)0x0) {
    param_1[0xe] = 0;
    param_1[0xf] = 0x3f800000;
    param_1[10] = 0x3f800000;
    param_1[5] = 0x3f800000;
    *param_1 = 0x3f800000;
    param_1[0xd] = 0;
    param_1[0xc] = 0;
    param_1[0xb] = 0;
    param_1[9] = 0;
    param_1[8] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    *(undefined1 *)((int)param_1 + 0x41) = 1;
    *(undefined1 *)(param_1 + 0x10) = 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


