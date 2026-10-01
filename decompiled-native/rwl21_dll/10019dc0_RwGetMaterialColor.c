// 10019dc0 RwGetMaterialColor [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwGetMaterialColor(int param_1,float *param_2)

{
  int unaff_EBX;
  int iStack_10;
  int local_c [3];
  
                    /* 0x19dc0  197  RwGetMaterialColor */
  if ((param_1 != 0) && (param_2 != (float *)0x0)) {
    (**(code **)(PTR_DAT_1005b69c + 0x264))(*(undefined4 *)(param_1 + 8),local_c);
    *param_2 = (float)unaff_EBX * (float)_DAT_10052168;
    param_2[1] = (float)iStack_10 * (float)_DAT_10052168;
    param_2[2] = (float)local_c[0] * (float)_DAT_10052168;
    return param_2;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


