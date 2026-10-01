// 1003d650 FUN_1003d650 [Global]
// program: RWDL8D21.DLL

void FUN_1003d650(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint local_24;
  uint local_18;
  
  iVar7 = DAT_10075220;
  uVar2 = param_1[0xc];
  uVar9 = *param_1;
  uVar10 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar9 = uVar9 + uVar3;
    uVar10 = uVar10 + uVar4;
    uVar8 = param_1[0x11] + param_1[0x10] & 0x7fff7fff;
    uVar11 = param_1[0x13] + param_1[0x14];
    param_1[0x10] = uVar8;
    iVar12 = ((int)uVar9 >> 0x10) - ((int)uVar10 >> 0x10);
    param_1[0x13] = uVar11;
    if (iVar12 < 0) {
      uVar6 = param_1[5];
      local_24 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
      do {
        if (((local_24 & 0xff) < param_1[10]) &&
           (bVar1 = *(byte *)(((uVar8 & 0xf000000) >> 0x14 | (uVar8 & 0xf00) >> 8) + uVar2),
           bVar1 != 0)) {
          local_18 = (uint)bVar1;
          *(undefined1 *)(iVar12 + ((int)uVar10 >> 0x10) + uVar6) =
               *(undefined1 *)(((local_24 & 0xff) + uVar11 & 0xff00) + local_18 + iVar7);
        }
        local_24 = local_24 ^ local_24 >> 6;
        uVar11 = uVar11 + param_1[0x15];
        uVar8 = param_1[0x12] + uVar8 & 0x7fff7fff;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0);
    }
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = uVar9;
  param_1[1] = uVar10;
  return;
}


