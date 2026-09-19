// 100192e0 FUN_100192e0 [Global]
// programa: RWDL6D21.DLL

undefined4 FUN_100192e0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  int local_c;
  
  iVar2 = *param_1;
  if (((*(byte *)(iVar2 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    local_c = 0;
    if (*(byte *)((int)param_1 + 0x3a) != 0) {
      piVar5 = param_1 + 0xf;
      iVar6 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
      bVar4 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
      do {
        iVar3 = *piVar5;
        bVar1 = *(byte *)(iVar3 + 0x48);
        if ((bVar4 & bVar1 & 0x3f) == 0) {
          FUN_10019370(iVar3,iVar6,iVar2,param_1 + 1);
        }
        piVar5 = piVar5 + 1;
        local_c = local_c + 1;
        iVar6 = iVar3;
        bVar4 = bVar1;
      } while (local_c < (int)(uint)*(byte *)((int)param_1 + 0x3a));
    }
  }
  return 0;
}


