// 1000a460 FUN_1000a460 [Global]
// program: rwdlmd21.dll

undefined4 * FUN_1000a460(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0x10;
  if (param_1[9] != 0xf) {
    iVar2 = param_1[9];
  }
  iVar2 = param_1[7] * iVar2 + 7;
  piVar1 = param_1 + 6;
  uVar3 = ((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
  if (uVar3 == 0) {
    *piVar1 = 0;
  }
  else {
    iVar2 = (**(code **)(DAT_10089de0 + 0x34c))(param_1[8] * uVar3);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      return (undefined4 *)0x0;
    }
  }
  param_1[10] = uVar3;
  param_1[0xb] = 0;
  param_1[0x10] = 9;
  if (*piVar1 != 0) {
    param_1[0x10] = 0xb;
  }
  if (param_1[1] == 0) {
    switch(param_1[9]) {
    case 8:
      *param_1 = 1;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[1] = 8;
      return param_1;
    default:
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      return param_1;
    case 0xf:
      param_1[1] = 0x10;
      param_1[2] = 0x7c00;
      *param_1 = 2;
      param_1[3] = 0x3e0;
      param_1[4] = 0x1f;
      param_1[5] = 0;
      return param_1;
    case 0x10:
      param_1[1] = 0x10;
      param_1[2] = 0xf800;
      *param_1 = 2;
      param_1[3] = 0x7e0;
      param_1[4] = 0x1f;
      param_1[5] = 0;
      return param_1;
    case 0x18:
      param_1[1] = 0x18;
      param_1[2] = 0xff0000;
      param_1[3] = 0xff00;
      param_1[4] = 0xff;
      param_1[5] = 0;
      *param_1 = 2;
    }
  }
  return param_1;
}


