// 100051c0 FUN_100051c0 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_100051c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((-1 < param_1) && (param_1 < DAT_10087168)) {
    puVar2 = (undefined4 *)(DAT_10087164 + param_1 * 0x14);
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    return 1;
  }
  return 0;
}


