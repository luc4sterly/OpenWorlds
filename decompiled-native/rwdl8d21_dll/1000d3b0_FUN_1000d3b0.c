// 1000d3b0 FUN_1000d3b0 [Global]
// program: RWDL8D21.DLL

void FUN_1000d3b0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar7 = param_1[1];
  uVar1 = param_1[3];
  uVar8 = *param_1;
  uVar2 = param_1[2];
  uVar5 = param_1[0xb];
  uVar3 = param_1[4];
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
    uVar8 = uVar8 + uVar1;
    uVar7 = uVar7 + uVar2;
    iVar9 = ((int)uVar8 >> 0x10) - ((int)uVar7 >> 0x10);
    if (iVar9 < 0) {
      uVar4 = param_1[5];
      uVar6 = *(uint *)(DAT_10075224 + ((uVar8 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      do {
        if ((uVar6 & 0xff) < param_1[10]) {
          *(char *)(((int)uVar7 >> 0x10) + uVar4 + iVar9) = (char)uVar5;
        }
        uVar6 = uVar6 ^ uVar6 >> 6;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar8;
  param_1[1] = uVar7;
  return;
}


