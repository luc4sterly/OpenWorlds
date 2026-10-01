// 10004b10 FUN_10004b10 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_10004b10(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((-1 < param_1) && (param_1 < DAT_10075160)) {
    puVar2 = (undefined4 *)(DAT_1007515c + param_1 * 0x14);
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    return 1;
  }
  return 0;
}


