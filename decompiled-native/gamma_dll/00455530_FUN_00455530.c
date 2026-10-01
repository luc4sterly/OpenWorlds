// 00455530 FUN_00455530 [Global]
// program: gamma.dll

undefined1 * __cdecl FUN_00455530(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = param_2 + -1;
  if (iVar5 < 0) {
    return (undefined1 *)0x0;
  }
  puVar6 = param_1;
  if (iVar5 != 0) {
    while( true ) {
      iVar3 = FUN_004553d0((int)param_3,-1);
      if (iVar3 < 0) {
        piVar1 = param_3 + 0xb;
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar3 == 0) {
          uVar4 = FUN_00455440(param_3);
        }
        else {
          pbVar2 = (byte *)param_3[10];
          param_3[10] = param_3[10] + 1;
          uVar4 = (uint)*pbVar2;
        }
      }
      else {
        uVar4 = 0xffffffff;
      }
      if (uVar4 == 0xffffffff) break;
      *puVar6 = (char)uVar4;
      puVar6 = puVar6 + 1;
      if ((uVar4 == 10) || (iVar5 = iVar5 + -1, iVar5 == 0)) goto LAB_004555a2;
    }
    if ((*(char *)(param_3 + 3) == '\0') || (puVar6 == param_1)) {
      return (undefined1 *)0x0;
    }
  }
LAB_004555a2:
  *puVar6 = 0;
  return param_1;
}


