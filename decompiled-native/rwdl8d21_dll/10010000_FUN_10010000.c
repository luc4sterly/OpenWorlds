// 10010000 FUN_10010000 [Global]
// programa: RWDL8D21.DLL

void FUN_10010000(uint *param_1)

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
  
  uVar6 = *param_1;
  uVar8 = param_1[1];
  uVar1 = param_1[3];
  uVar2 = param_1[2];
  uVar3 = param_1[4];
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
    uVar6 = uVar6 + uVar1;
    uVar8 = uVar8 + uVar2;
    uVar5 = param_1[0x10] + param_1[0x11];
    iVar9 = ((int)uVar6 >> 0x10) - ((int)uVar8 >> 0x10);
    param_1[0x10] = uVar5;
    if (iVar9 < 0) {
      uVar4 = param_1[5];
      uVar7 = *(uint *)(DAT_10075224 + ((uVar6 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      do {
        if ((uVar7 & 0xff) < param_1[10]) {
          *(undefined1 *)(iVar9 + ((int)uVar8 >> 0x10) + uVar4) =
               *(undefined1 *)(((uVar7 & 0xff) + uVar5 >> 8 & 0xff) + param_1[0xd]);
        }
        uVar7 = uVar7 ^ uVar7 >> 6;
        uVar5 = uVar5 + param_1[0x12];
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar6;
  param_1[1] = uVar8;
  return;
}


