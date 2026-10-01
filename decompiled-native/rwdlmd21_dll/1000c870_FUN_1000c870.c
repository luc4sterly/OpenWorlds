// 1000c870 FUN_1000c870 [Global]
// program: rwdlmd21.dll

undefined4 * FUN_1000c870(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1 + 4;
  if (DAT_10089b90 < (uint)(DAT_10089b84 + iVar3)) {
    if (DAT_10089b88 == 0) {
      iVar1 = (**(code **)(DAT_10089de0 + 0x34c))(DAT_10089b84 + iVar3);
    }
    else {
      iVar1 = (**(code **)(DAT_10089de0 + 0x354))(DAT_10089b88);
    }
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
    DAT_10089b90 = DAT_10089b84 + iVar3;
    DAT_10089b88 = iVar1;
  }
  if (DAT_10089b98 <= DAT_10089b94) {
    if (DAT_10089b8c == 0) {
      iVar1 = (**(code **)(DAT_10089de0 + 0x34c))(DAT_10089b98 * 4 + 4);
    }
    else {
      iVar1 = (**(code **)(DAT_10089de0 + 0x354))(DAT_10089b8c);
    }
    if (iVar1 == 0) {
      return (undefined4 *)0x0;
    }
    DAT_10089b98 = DAT_10089b98 + 1;
    DAT_10089b8c = iVar1;
  }
  *(int *)(DAT_10089b8c + DAT_10089b94 * 4) = DAT_10089b84;
  puVar2 = (undefined4 *)(DAT_10089b84 + DAT_10089b88);
  *puVar2 = param_2;
  DAT_10089b94 = DAT_10089b94 + 1;
  DAT_10089b84 = DAT_10089b84 + iVar3;
  return puVar2 + 1;
}


