// 10019ed0 RwSetMaterialColor [Global]
// program: RWL21.DLL

int RwSetMaterialColor(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x19ed0  415  RwSetMaterialColor */
  if (param_1 != 0) {
    if (0x80000000 < param_2) {
      param_2 = 0;
    }
    if ((int)param_2 < 0x3f800000) {
      lVar2 = __ftol();
      local_c = (undefined4)lVar2;
    }
    else {
      local_c = 0xffff;
    }
    if (0x80000000 < param_3) {
      param_3 = 0;
    }
    if ((int)param_3 < 0x3f800000) {
      lVar2 = __ftol();
      local_8 = (undefined4)lVar2;
    }
    else {
      local_8 = 0xffff;
    }
    if (0x80000000 < param_4) {
      param_4 = 0;
    }
    if ((int)param_4 < 0x3f800000) {
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


