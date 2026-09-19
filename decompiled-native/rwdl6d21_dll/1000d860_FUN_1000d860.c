// 1000d860 FUN_1000d860 [Global]
// programa: RWDL6D21.DLL

void FUN_1000d860(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  int local_1c;
  
  iVar6 = *param_1;
  iVar7 = param_1[1];
  iVar2 = param_1[3];
  iVar3 = param_1[2];
  iVar4 = param_1[0xc];
  iVar5 = param_1[4];
  while (iVar5 = iVar5 + -1, -1 < iVar5) {
    iVar6 = iVar6 + iVar2;
    iVar7 = iVar7 + iVar3;
    uVar8 = param_1[0x10] + param_1[0x11] & 0x7fff7fff;
    param_1[0x10] = uVar8;
    local_1c = (iVar6 >> 0x10) - (iVar7 >> 0x10);
    if (local_1c < 0) {
      puVar9 = (ushort *)(param_1[5] + (iVar7 >> 0x10) * 2 + local_1c * 2);
      do {
        uVar1 = *(ushort *)(((uVar8 & 0x7f00) >> 7 | (uVar8 & 0x7f000000) >> 0x10) + iVar4);
        if (uVar1 != 0) {
          *puVar9 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                    (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                    (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
        }
        puVar9 = puVar9 + 1;
        uVar8 = param_1[0x12] + uVar8 & 0x7fff7fff;
        local_1c = local_1c + 1;
      } while (local_1c < 0);
    }
    param_1[5] = param_1[5] + param_1[6];
  }
  *param_1 = iVar6;
  param_1[1] = iVar7;
  return;
}


