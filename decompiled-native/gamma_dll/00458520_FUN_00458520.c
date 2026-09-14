// 00458520 FUN_00458520 [Global]
// programa: gamma.dll

/* WARNING: Type propagation algorithm not settling */

uint __cdecl FUN_00458520(undefined4 *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int local_24;
  char *local_14;
  
  iVar5 = FUN_004553d0((int)param_4,0);
  if (iVar5 == 0) {
    FUN_004553d0((int)param_4,-1);
  }
  pcVar6 = (char *)(param_2 * param_3);
  if (((pcVar6 == (char *)0x0) || (*(char *)((int)param_4 + 0xd) != '\0')) ||
     ((*(ushort *)(param_4 + 1) >> 7 & 7) == 0)) {
    return 0;
  }
  if ((*(ushort *)(param_4 + 1) >> 7 & 7) == 2) {
    FUN_00459570();
  }
  bVar4 = true;
  bVar3 = true;
  if (((*(byte *)((int)param_4 + 5) >> 4 & 1) != 0) && ((*(byte *)(param_4 + 1) >> 5 & 3) != 2)) {
    bVar3 = false;
  }
  if ((!bVar3) && ((*(byte *)(param_4 + 1) >> 5 & 3) != 1)) {
    bVar4 = false;
  }
  if (((*(byte *)(param_4 + 2) & 7) == 0) && ((*(byte *)(param_4 + 1) >> 2 & 2) != 0)) {
    if (((*(byte *)(param_4 + 1) >> 2 & 4) != 0) && (iVar5 = FUN_004553b0(param_4,0,2), iVar5 != 0))
    {
      return 0;
    }
    *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0xf8 | 1;
    FUN_00459300((int)param_4);
  }
  if ((*(byte *)(param_4 + 2) & 7) != 1) {
    *(undefined1 *)((int)param_4 + 0xd) = 1;
    param_4[0xb] = 0;
    return 0;
  }
  local_24 = 0;
  if (pcVar6 != (char *)0x0) {
    if ((param_4[10] != param_4[8]) || (bVar4)) {
      param_4[0xb] = param_4[9] - (param_4[10] - param_4[8]);
      while( true ) {
        pcVar7 = (char *)0x0;
        local_14 = (char *)param_4[0xb];
        if (pcVar6 < (char *)param_4[0xb]) {
          local_14 = pcVar6;
        }
        if ((((*(byte *)(param_4 + 1) >> 5 & 3) == 1) && (local_14 != (char *)0x0)) &&
           (pcVar7 = FUN_0044dfe0((int)param_1,'\n',(int)local_14), pcVar7 != (char *)0x0)) {
          local_14 = pcVar7 + (1 - (int)param_1);
        }
        if (local_14 != (char *)0x0) {
          FUN_0044df50((undefined4 *)param_4[10],param_1,(uint)local_14);
          param_1 = (undefined4 *)((int)param_1 + (int)local_14);
          local_24 = local_24 + (int)local_14;
          pcVar6 = pcVar6 + -(int)local_14;
          param_4[10] = local_14 + param_4[10];
          param_4[0xb] = param_4[0xb] - (int)local_14;
        }
        if ((((param_4[0xb] == 0) || (pcVar7 != (char *)0x0)) ||
            ((*(byte *)(param_4 + 1) >> 5 & 3) == 0)) &&
           (iVar5 = FUN_004593d0(param_4,(undefined4 *)0x0), iVar5 != 0)) break;
        if ((pcVar6 == (char *)0x0) || (!bVar4)) goto LAB_0045871f;
      }
      *(undefined1 *)((int)param_4 + 0xd) = 1;
      param_4[0xb] = 0;
      pcVar6 = (char *)0x0;
    }
  }
LAB_0045871f:
  if ((pcVar6 != (char *)0x0) && (!bVar4)) {
    uVar1 = param_4[8];
    uVar2 = param_4[9];
    param_4[8] = param_1;
    param_4[9] = pcVar6;
    param_4[10] = (int)param_1 + (int)pcVar6;
    iVar5 = FUN_004593d0(param_4,&local_14);
    if (iVar5 != 0) {
      *(undefined1 *)((int)param_4 + 0xd) = 1;
      param_4[0xb] = 0;
    }
    local_24 = local_24 + (int)local_14;
    param_4[8] = uVar1;
    param_4[9] = uVar2;
    FUN_00459300((int)param_4);
    param_4[0xb] = 0;
  }
  if ((*(byte *)(param_4 + 1) >> 5 & 3) != 2) {
    param_4[0xb] = 0;
  }
  return (local_24 + (param_2 - 1)) / param_2;
}


