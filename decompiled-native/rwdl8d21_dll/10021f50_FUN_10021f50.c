// 10021f50 FUN_10021f50 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_10021f50(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  byte local_6;
  byte local_5;
  
  iVar2 = *param_1;
  uVar5 = (uint)*(byte *)((int)param_1 + 0x3a);
  iVar6 = param_1[0xf];
  iVar4 = 1;
  local_6 = *(byte *)(param_1[uVar5 + 0xe] + 0x48);
  local_5 = *(byte *)(iVar6 + 0x48);
  if (1 < *(byte *)((int)param_1 + 0x3a)) {
    piVar7 = param_1 + 0x10;
    do {
      if ((local_5 & local_6 & 0x3f) == 0) break;
      iVar6 = *piVar7;
      piVar7 = piVar7 + 1;
      iVar4 = iVar4 + 1;
      local_6 = local_5;
      local_5 = *(byte *)(iVar6 + 0x48);
    } while (iVar4 < (int)uVar5);
    if (iVar4 < (int)uVar5) {
      piVar7 = param_1 + iVar4 + 0xf;
      iVar4 = uVar5 - iVar4;
      do {
        iVar3 = *piVar7;
        piVar7 = piVar7 + 1;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar1 & local_5 & 0x3f) == 0) {
          FUN_10021a20(iVar3,iVar6,iVar2,param_1 + 1);
        }
        iVar4 = iVar4 + -1;
        iVar6 = iVar3;
        local_5 = bVar1;
      } while (iVar4 != 0);
    }
  }
  return 0;
}


