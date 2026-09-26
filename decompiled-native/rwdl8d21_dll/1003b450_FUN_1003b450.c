// 1003b450 FUN_1003b450 [Global]
// programa: RWDL8D21.DLL

void FUN_1003b450(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_20;
  uint local_14;
  
  iVar7 = DAT_10075220;
  uVar2 = param_1[0xc];
  uVar9 = *param_1;
  uVar11 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar9 = uVar9 + uVar3;
    uVar11 = uVar11 + uVar4;
    uVar12 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    uVar10 = param_1[0x13] + param_1[0x14];
    param_1[0x10] = uVar12;
    param_1[0x13] = uVar10;
    iVar8 = ((int)uVar9 >> 0x10) - ((int)uVar11 >> 0x10);
    if (iVar8 < 0) {
      local_20 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      uVar6 = param_1[5];
      do {
        bVar1 = *(byte *)(((uVar12 & 0xf00) >> 8 | (uVar12 & 0xf000000) >> 0x14) + uVar2);
        if (bVar1 != 0) {
          local_14 = (uint)bVar1;
          *(undefined1 *)(uVar6 + ((int)uVar11 >> 0x10) + iVar8) =
               *(undefined1 *)(((local_20 & 0xff) + uVar10 & 0xff00) + local_14 + iVar7);
        }
        local_20 = local_20 ^ local_20 >> 6;
        uVar12 = param_1[0x12] + uVar12 & 0x7fff7fff;
        uVar10 = uVar10 + param_1[0x15];
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = uVar9;
  param_1[1] = uVar11;
  return;
}


