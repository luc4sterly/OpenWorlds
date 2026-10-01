// 10051324 rwFixDiv [Global]
// program: RWL21.DLL

/* rwFixDiv */

undefined8 __cdecl rwFixDiv(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 in_EDX;
  uint uVar2;
  
                    /* 0x51324  536  _rwFixDiv */
  if (param_1 != 0) {
    uVar1 = param_1;
    if ((int)param_1 < 0) {
      uVar1 = -param_1;
    }
    if (param_2 != 0) {
      uVar2 = param_2;
      if ((int)param_2 < 0) {
        uVar2 = -param_2;
      }
      if ((uint)((int)uVar1 >> 0xf) < uVar2) {
        param_1 = (uint)(CONCAT44(((int)param_1 >> 0x1f) << 0x10 | param_1 >> 0x10,param_1 << 0x10)
                        / (longlong)(int)param_2);
      }
      else {
        uVar1 = param_1 ^ param_2;
        param_1 = 0x7fffffff;
        if ((int)uVar1 < 0) {
          param_1 = 0x80000000;
        }
      }
    }
  }
  return CONCAT44(in_EDX,param_1);
}


