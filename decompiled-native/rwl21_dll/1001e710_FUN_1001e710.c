// 1001e710 FUN_1001e710 [Global]
// programa: RWL21.DLL

undefined4 FUN_1001e710(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = DAT_1005ac40;
  iVar5 = 0;
  piVar1 = DAT_1005ac40 + 1;
  if (0 < DAT_1005ac40[1]) {
    iVar4 = 0;
    do {
      puVar2 = (undefined4 *)(*piVar3 + iVar4);
      if ((undefined4 *)*puVar2 == (undefined4 *)0x0) break;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 1;
      FUN_10037010(DAT_1005ac38,(undefined4 *)*puVar2);
    } while (iVar5 < *piVar1);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(*piVar3);
  FUN_10037010(DAT_1005ac3c,piVar3);
  piVar3 = DAT_1005ac44;
  iVar4 = 0;
  iVar5 = 0;
  piVar1 = DAT_1005ac44 + 1;
  if (0 < DAT_1005ac44[1]) {
    do {
      puVar2 = (undefined4 *)(*piVar3 + iVar4);
      if ((undefined4 *)*puVar2 == (undefined4 *)0x0) break;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 1;
      FUN_10037010(DAT_1005ac38,(undefined4 *)*puVar2);
    } while (iVar5 < *piVar1);
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(*piVar3);
  FUN_10037010(DAT_1005ac3c,piVar3);
  FUN_100370f0();
  FUN_100370f0();
  return 1;
}


