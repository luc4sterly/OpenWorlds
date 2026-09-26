// 10021e30 FUN_10021e30 [Global]
// programa: RWDL8D21.DLL

undefined4 FUN_10021e30(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte local_5;
  
  piVar6 = param_1 + 0xf;
  param_1[1] = *(int *)(param_1[0xf] + 0x58);
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar5 = 0;
    iVar4 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
    local_5 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
    if (*(byte *)((int)param_1 + 0x3a) != 0) {
      do {
        iVar3 = *piVar6;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar1 & local_5 & 0x3f) == 0) {
          FUN_10021a20(iVar3,iVar4,iVar2,param_1 + 1);
        }
        piVar6 = piVar6 + 1;
        iVar5 = iVar5 + 1;
        iVar4 = iVar3;
        local_5 = bVar1;
      } while (iVar5 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
    }
  }
  return 0;
}


