// 10044d90 FUN_10044d90 [Global]
// programa: RWDL8D21.DLL

void FUN_10044d90(uint *param_1)

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
  uint uVar11;
  int iVar12;
  
  uVar2 = param_1[0xc];
  uVar3 = param_1[0xd];
  uVar9 = *param_1;
  uVar10 = param_1[1];
  uVar4 = param_1[3];
  uVar5 = param_1[2];
  uVar6 = param_1[4];
  while (uVar6 = uVar6 - 1, -1 < (int)uVar6) {
    uVar9 = uVar9 + uVar4;
    uVar10 = uVar10 + uVar5;
    uVar11 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar11;
    uVar8 = *(uint *)(DAT_10075224 + ((uVar9 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9];
    iVar12 = ((int)uVar9 >> 0x10) - ((int)uVar10 >> 0x10);
    if (iVar12 < 0) {
      uVar7 = param_1[5];
      do {
        bVar1 = *(byte *)((((int)(short)((short)(char)uVar8 ^ 0xaa) + ((int)uVar11 >> 0x10) & 0xf00U
                           | ((int)(short)(char)uVar8 + uVar11 & 0xf00) >> 4) >> 4) + uVar2);
        if (bVar1 != 0) {
          *(undefined1 *)(uVar7 + ((int)uVar10 >> 0x10) + iVar12) = *(undefined1 *)(bVar1 + uVar3);
        }
        uVar8 = uVar8 ^ uVar8 >> 6;
        uVar11 = param_1[0x12] + uVar11 & 0x7fff7fff;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar9;
  param_1[1] = uVar10;
  return;
}


