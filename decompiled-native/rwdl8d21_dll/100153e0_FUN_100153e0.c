// 100153e0 FUN_100153e0 [Global]
// program: RWDL8D21.DLL

void FUN_100153e0(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_18;
  
  uVar2 = param_1[0xd];
  uVar9 = *param_1;
  uVar10 = param_1[1];
  uVar3 = param_1[0xc];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar9 = uVar9 + uVar4;
    uVar10 = uVar10 + uVar5;
    uVar8 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar8;
    local_18 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar11 = ((int)uVar9 >> 0x10) - ((int)uVar10 >> 0x10);
    if (iVar11 < 0) {
      uVar7 = param_1[5];
      do {
        if (((local_18 & 0xff) < param_1[10]) &&
           (bVar1 = *(byte *)(((uVar8 & 0x7f00) >> 8 | (uVar8 & 0x7f000000) >> 0x11) + uVar3),
           bVar1 != 0)) {
          *(undefined1 *)(iVar11 + uVar7 + ((int)uVar10 >> 0x10)) = *(undefined1 *)(bVar1 + uVar2);
        }
        local_18 = local_18 ^ local_18 >> 6;
        uVar8 = param_1[0x12] + uVar8 & 0x7fff7fff;
        iVar11 = iVar11 + 1;
      } while (iVar11 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar10;
  return;
}


