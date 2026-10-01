// 10019fd0 RwSetMaterialColorStruct [Global]
// program: RWL21.DLL

int RwSetMaterialColorStruct(int param_1,uint *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  uint local_14;
  uint local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x19fd0  416  RwSetMaterialColorStruct */
  if (param_2 == (uint *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_10 = param_2[2];
  local_14 = param_2[1];
  local_c = *param_2;
  if (param_1 != 0) {
    if (0x80000000 < local_c) {
      local_c = 0;
    }
    if ((int)local_c < 0x3f800000) {
      lVar2 = __ftol();
      local_c = (uint)lVar2;
    }
    else {
      local_c = 0xffff;
    }
    if (0x80000000 < local_14) {
      local_14 = 0;
    }
    if ((int)local_14 < 0x3f800000) {
      lVar2 = __ftol();
      local_8 = (undefined4)lVar2;
    }
    else {
      local_8 = 0xffff;
    }
    if (0x80000000 < local_10) {
      local_10 = 0;
    }
    if ((int)local_10 < 0x3f800000) {
      lVar2 = __ftol();
      local_4 = (undefined4)lVar2;
    }
    else {
      local_4 = 0xffff;
    }
    uVar1 = (**(code **)(PTR_DAT_1005b69c + 0x260))(&local_c);
    *(undefined4 *)(param_1 + 8) = uVar1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


