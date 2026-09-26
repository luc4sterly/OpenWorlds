// 1001a8b0 FUN_1001a8b0 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_1001a8b0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  byte local_9;
  
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar4 = 0;
    if (*(byte *)((int)param_1 + 0x3a) != 0) {
      piVar5 = param_1 + 0xf;
      iVar6 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
      local_9 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
      do {
        iVar3 = *piVar5;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar1 & local_9 & 0x3f) == 0) {
          FUN_1001a940(iVar3,iVar6,iVar2,param_1 + 1);
        }
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + 1;
        iVar6 = iVar3;
        local_9 = bVar1;
      } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
    }
  }
  return 0;
}


