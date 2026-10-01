// 10017f50 RwGetClumpVertexUV [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwGetClumpVertexUV(int param_1,int param_2,float *param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x17f50  170  RwGetClumpVertexUV */
  if ((param_1 == 0) || (param_3 == (float *)0x0)) {
    FUN_1000cba0(1);
    return (float *)0x0;
  }
  if ((0 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 0x70 + (param_2 + 7) * 0x74);
    uVar2 = iVar1 + 0x100;
    if ((uVar2 & 0xffff0000) == 0) {
      uVar2 = iVar1 - 0x100;
    }
    *param_3 = (float)(int)uVar2 * (float)_DAT_10052158;
    iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 0x74 + (param_2 + 7) * 0x74);
    uVar2 = iVar1 + 0x100;
    if ((uVar2 & 0xffff0000) == 0) {
      uVar2 = iVar1 - 0x100;
    }
    param_3[1] = (float)(int)uVar2 * (float)_DAT_10052158;
    return param_3;
  }
  FUN_1000cba0(0x19);
  return (float *)0x0;
}


