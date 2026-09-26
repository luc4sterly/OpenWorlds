// 00401641 FUN_00401641 [Global]
// programa: run.exe

undefined4 * __cdecl FUN_00401641(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar6 = iVar6 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar6 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    psVar4 = (short *)*param_1;
    puVar7 = puVar3;
    while (psVar4 != (short *)0x0) {
      param_1 = param_1 + 1;
      uVar5 = FUN_00403a35(psVar4);
      *puVar7 = uVar5;
      puVar7 = puVar7 + 1;
      psVar4 = (short *)*param_1;
    }
    *puVar7 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}


