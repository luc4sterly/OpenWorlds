// 1001d4c0 FUN_1001d4c0 [Global]
// program: RWL21.DLL

void FUN_1001d4c0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_1[1]) {
    do {
      puVar1 = (undefined4 *)(*param_1 + iVar3);
      if ((undefined4 *)*puVar1 == (undefined4 *)0x0) break;
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 1;
      FUN_10037010(DAT_1005ac38,(undefined4 *)*puVar1);
    } while (iVar2 < param_1[1]);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(*param_1);
  FUN_10037010(DAT_1005ac3c,param_1);
  return;
}


