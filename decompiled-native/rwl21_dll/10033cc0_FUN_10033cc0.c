// 10033cc0 FUN_10033cc0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_10033cc0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 fVar3;
  float10 extraout_ST0_00;
  undefined8 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_4 + 0x20);
  if (*(int *)(param_3 + 0x20) == iVar1) {
    return 0;
  }
  iVar2 = 0;
  local_18 = 0;
  local_14 = 0;
  if (*(char *)(iVar1 + 0x3a) != '\0') {
    do {
      uVar4 = RwDotProduct(param_3 + 0xc,param_2);
      param_2 = (int)((ulonglong)uVar4 >> 0x20);
      fVar3 = extraout_ST0 - (float10)*(float *)(param_3 + 0x18);
      if (fVar3 <= (float10)_DAT_10052268) {
        if ((uint)(float)fVar3 < 0xba831270) {
          local_14 = local_14 + 1;
        }
      }
      else {
        local_18 = local_18 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(iVar1 + 0x3a));
  }
  iVar2 = 0;
  local_10 = 0;
  local_8 = 0;
  if (*(char *)(*(int *)(param_3 + 0x20) + 0x3a) != '\0') {
    do {
      RwDotProduct(param_4 + 0xc,param_2);
      fVar3 = extraout_ST0_00 - (float10)*(float *)(param_4 + 0x18);
      if (fVar3 <= (float10)_DAT_10052268) {
        if ((uint)(float)fVar3 < 0xba831270) {
          local_10 = local_10 + 1;
        }
      }
      else {
        iVar2 = iVar2 + 1;
      }
      param_2 = local_8 + 1;
      local_8 = param_2;
    } while (param_2 < (int)(uint)*(byte *)(*(int *)(param_3 + 0x20) + 0x3a));
  }
  if ((local_18 == 0) && (iVar2 == 0)) {
    return 3;
  }
  iVar1 = (uint)*(byte *)(iVar1 + 0x3a) - local_18;
  if ((local_14 == iVar1) && ((uint)*(byte *)(*(int *)(param_3 + 0x20) + 0x3a) - iVar2 == local_10))
  {
    return 3;
  }
  if (local_18 == 0) {
    return -1;
  }
  if (local_14 == iVar1) {
    return 1;
  }
  if (iVar2 == 0) {
    return 1;
  }
  return (-(uint)((uint)*(byte *)(*(int *)(param_3 + 0x20) + 0x3a) - iVar2 == local_10) & 0xfffffffd
         ) + 2;
}


