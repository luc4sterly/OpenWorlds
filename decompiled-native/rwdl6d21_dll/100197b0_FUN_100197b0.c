// 100197b0 FUN_100197b0 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_100197b0(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_6;
  byte local_5;
  
  iVar2 = *param_1;
  uVar6 = (uint)*(byte *)((int)param_1 + 0x3a);
  iVar7 = param_1[0xf];
  iVar5 = 1;
  local_6 = *(byte *)(param_1[uVar6 + 0xe] + 0x48);
  local_5 = *(byte *)(iVar7 + 0x48);
  if (1 < *(byte *)((int)param_1 + 0x3a)) {
    piVar4 = param_1 + 0x10;
    do {
      if ((local_5 & local_6 & 0x3f) == 0) break;
      iVar7 = *piVar4;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
      local_6 = local_5;
      local_5 = *(byte *)(iVar7 + 0x48);
    } while (iVar5 < (int)uVar6);
    if (iVar5 < (int)uVar6) {
      piVar4 = param_1 + iVar5 + 0xf;
      iVar5 = uVar6 - iVar5;
      do {
        iVar3 = *piVar4;
        piVar4 = piVar4 + 1;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar1 & local_5 & 0x3f) == 0) {
          FUN_10019370(iVar3,iVar7,iVar2,param_1 + 1);
        }
        iVar5 = iVar5 + -1;
        iVar7 = iVar3;
        local_5 = bVar1;
      } while (iVar5 != 0);
    }
  }
  return 0;
}


