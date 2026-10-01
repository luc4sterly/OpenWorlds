// 004266f0 FUN_004266f0 [Global]
// program: gamma.dll

int __cdecl FUN_004266f0(byte *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  int local_44;
  uint local_40;
  uint local_3c;
  undefined1 uStack_38;
  int aiStack_34 [5];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  piVar4 = param_2;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  iVar3 = 0x100;
  local_40 = 0;
  local_3c = 0;
  uStack_38 = 0;
  local_44 = 0;
  pbVar5 = param_1;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    if (8 < bVar1) {
      FUN_00402800(s_huffdcod_00471cb0,0x47);
    }
    iVar3 = iVar3 + -1;
    local_44 = local_44 + (uint)bVar1;
    *(char *)((int)&local_40 + (uint)bVar1) = *(char *)((int)&local_40 + (uint)bVar1) + '\x01';
  } while (iVar3 != 0);
  if (1 < local_44) {
    aiStack_34[1] = 0;
    aiStack_34[2] = (local_40 >> 8 & 0xff) * 2;
    aiStack_34[3] = ((local_40 >> 0x10 & 0xff) + aiStack_34[2]) * 2;
    aiStack_34[4] = ((local_40 >> 0x18) + aiStack_34[3]) * 2;
    local_20 = ((local_3c & 0xff) + aiStack_34[4]) * 2;
    local_1c = ((local_3c >> 8 & 0xff) + local_20) * 2;
    local_18 = ((local_3c >> 0x10 & 0xff) + local_1c) * 2;
    iVar3 = 0x100;
    local_14 = ((local_3c >> 0x18) + local_18) * 2;
    do {
      bVar1 = *param_1;
      if (bVar1 != 0) {
        iVar2 = aiStack_34[bVar1];
        aiStack_34[bVar1] = aiStack_34[bVar1] + 1;
        *param_2 = iVar2;
      }
      iVar3 = iVar3 + -1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 != 0);
  }
  return local_44;
}


