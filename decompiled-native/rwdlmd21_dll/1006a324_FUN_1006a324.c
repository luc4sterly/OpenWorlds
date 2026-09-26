// 1006a324 FUN_1006a324 [Global]
// programa: rwdlmd21.dll

undefined8 __fastcall FUN_1006a324(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    uVar1 = param_3;
    if ((int)param_3 < 0) {
      uVar1 = -param_3;
    }
    if (param_4 != 0) {
      uVar2 = param_4;
      if ((int)param_4 < 0) {
        uVar2 = -param_4;
      }
      if ((uint)((int)uVar1 >> 0xf) < uVar2) {
        param_3 = (uint)(CONCAT44(((int)param_3 >> 0x1f) << 0x10 | param_3 >> 0x10,param_3 << 0x10)
                        / (longlong)(int)param_4);
      }
      else {
        uVar1 = param_3 ^ param_4;
        param_3 = 0x7fffffff;
        if ((int)uVar1 < 0) {
          param_3 = 0x80000000;
        }
      }
    }
  }
  return CONCAT44(param_2,param_3);
}


