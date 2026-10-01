// 1001aeb0 FUN_1001aeb0 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1001aeb0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  byte local_5;
  
  iVar6 = param_1[0xf];
  piVar4 = param_1 + 0xf;
  param_1[1] = *(int *)(iVar6 + 0x58);
  iVar2 = *param_1;
  param_1[2] = *(int *)(iVar6 + 0x5c);
  param_1[3] = *(int *)(iVar6 + 0x60);
  if (((*(byte *)(iVar2 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar5 = 0;
    iVar6 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
    local_5 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
    if (*(byte *)((int)param_1 + 0x3a) != 0) {
      do {
        iVar3 = *piVar4;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar1 & local_5 & 0x3f) == 0) {
          FUN_1001ab90(iVar3,iVar6,iVar2,param_1 + 1);
        }
        piVar4 = piVar4 + 1;
        iVar5 = iVar5 + 1;
        iVar6 = iVar3;
        local_5 = bVar1;
      } while (iVar5 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
    }
  }
  return 0;
}


