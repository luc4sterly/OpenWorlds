// 10018880 FUN_10018880 [Global]
// programa: RWL21.DLL

undefined4 * FUN_10018880(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < param_1[2])) {
    iVar4 = *(int *)(*param_1 + param_2 * 8);
    if (iVar4 != 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
    }
    iVar4 = param_2 + 1;
    puVar1 = *(undefined4 **)(*param_1 + -4 + iVar4 * 8);
    *puVar1 = 0;
    if (iVar4 < param_1[2]) {
      iVar3 = iVar4 * 8;
      do {
        iVar4 = iVar4 + 1;
        ((undefined4 *)(*param_1 + iVar3))[-2] = *(undefined4 *)(*param_1 + iVar3);
        iVar2 = *param_1 + iVar3;
        iVar3 = iVar3 + 8;
        *(undefined4 *)(iVar2 + -4) = *(undefined4 *)(iVar2 + 4);
      } while (iVar4 < param_1[2]);
    }
    param_1[2] = param_1[2] + -1;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


