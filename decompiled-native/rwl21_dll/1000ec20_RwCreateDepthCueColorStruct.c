// 1000ec20 RwCreateDepthCueColorStruct [Global]
// program: RWL21.DLL

undefined4 RwCreateDepthCueColorStruct(uint *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  longlong lVar3;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0xec20  569  RwCreateDepthCueColorStruct */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_c = *param_1;
  piVar2 = (int *)(PTR_DAT_1005b69c + 0x2a8);
  if (*piVar2 == 0) {
    FUN_1000cba0(0x5f);
    return 0;
  }
  if (local_c < 0x80000001) {
    if (0x3f800000 < (int)local_c) {
      local_c = 0x3f800000;
    }
  }
  else {
    local_c = 0;
  }
  lVar3 = __ftol();
  local_c = (uint)lVar3;
  lVar3 = __ftol();
  local_8 = (undefined4)lVar3;
  lVar3 = __ftol();
  local_4 = (undefined4)lVar3;
  uVar1 = (*(code *)*piVar2)(&local_c);
  return uVar1;
}


