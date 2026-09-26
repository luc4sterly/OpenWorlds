// 00401989 FUN_00401989 [Global]
// programa: run.exe

undefined4 * __cdecl FUN_00401989(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_00403b83(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}


