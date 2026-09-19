// 100360f0 RwCreateUserDraw [Global]
// programa: RWL21.DLL

undefined4 *
RwCreateUserDraw(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  
                    /* 0x360f0  49  RwCreateUserDraw */
  if ((param_1 < 1) || (4 < param_1)) {
    FUN_1000cba0(0x33);
    return (undefined4 *)0x0;
  }
  if ((((param_2 & 1) == 0) || ((param_2 & 2) == 0)) &&
     (((param_2 & 8) == 0 || ((param_2 & 4) == 0)))) {
    puVar1 = FUN_10037030(DAT_1005b310);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_7;
      puVar1[2] = param_3;
      puVar1[3] = param_4;
      puVar1[4] = param_5;
      puVar1[5] = param_6;
      puVar1[10] = param_1;
      puVar1[0xb] = param_2;
      puVar1[0xc] = 1;
      if (param_1 != 2) {
        puVar1[0xc] = 0;
      }
      puVar1[1] = 0;
      puVar1[0xd] = 0;
      puVar1[0xe] = 0;
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
      return puVar1;
    }
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  FUN_1000cba0(0x34);
  return (undefined4 *)0x0;
}


