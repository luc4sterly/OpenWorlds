// 0040bb00 _Java_NET_worlds_console_Console_decrypt@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Console_decrypt_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte local_118;
  byte local_117 [259];
  byte local_14 [4];
  
                    /* 0xbb00  19  _Java_NET_worlds_console_Console_decrypt@12 */
  pbVar3 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  pbVar8 = &local_118;
  pbVar7 = pbVar3;
  while (*pbVar7 != 0) {
    bVar1 = pbVar7[1];
    iVar4 = (*pbVar7 - 0x20) * 0x40;
    pbVar2 = pbVar7 + 1;
    if (bVar1 != 0) {
      iVar4 = iVar4 + (bVar1 - 0x20);
      pbVar2 = pbVar7 + 2;
    }
    pbVar7 = pbVar2;
    iVar4 = iVar4 * 0x40;
    if (*pbVar7 != 0) {
      iVar4 = iVar4 + (*pbVar7 - 0x20);
      pbVar7 = pbVar7 + 1;
    }
    iVar4 = iVar4 * 0x40;
    if (*pbVar7 != 0) {
      iVar4 = iVar4 + (*pbVar7 - 0x20);
      pbVar7 = pbVar7 + 1;
    }
    pbVar8[2] = (byte)iVar4;
    pbVar8[1] = (byte)((uint)iVar4 >> 8);
    *pbVar8 = (byte)((uint)iVar4 >> 0x10);
    pbVar8 = pbVar8 + 3;
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar3);
  iVar9 = (int)pbVar8 - (int)&local_118;
  local_14[0] = (byte)DAT_0049fa6c;
  local_14[1] = (byte)((uint)DAT_0049fa6c >> 8);
  local_14[1] = local_14[1] ^ local_118;
  local_14[0] = local_14[0] ^ local_118;
  local_14[2] = (byte)((uint)DAT_0049fa6c >> 0x10);
  local_14[3] = (byte)((uint)DAT_0049fa6c >> 0x18);
  local_14[2] = local_14[2] ^ local_118;
  local_14[3] = local_14[3] ^ local_118;
  iVar4 = 0;
  if (iVar9 != 1 && -1 < iVar9 + -1) {
    iVar5 = iVar4;
    if (8 < iVar9 + -1) {
      do {
        uVar6 = iVar5 >> 0x1f & 3;
        local_117[iVar5] = local_117[iVar5] ^ local_14[(iVar5 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 1 >> 0x1f & 3;
        local_117[iVar5 + 1] = local_117[iVar5 + 1] ^ local_14[(iVar5 + 1 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 2 >> 0x1f & 3;
        local_117[iVar5 + 2] = local_117[iVar5 + 2] ^ local_14[(iVar5 + 2 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 3 >> 0x1f & 3;
        local_117[iVar5 + 3] = local_117[iVar5 + 3] ^ local_14[(iVar5 + 3 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 4 >> 0x1f & 3;
        local_117[iVar5 + 4] = local_117[iVar5 + 4] ^ local_14[(iVar5 + 4 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 5 >> 0x1f & 3;
        local_117[iVar5 + 5] = local_117[iVar5 + 5] ^ local_14[(iVar5 + 5 + uVar6 & 3) - uVar6];
        uVar6 = iVar5 + 6 >> 0x1f & 3;
        local_117[iVar5 + 6] = local_117[iVar5 + 6] ^ local_14[(iVar5 + 6 + uVar6 & 3) - uVar6];
        iVar4 = iVar5 + 8;
        uVar6 = iVar5 + 7 >> 0x1f & 3;
        local_117[iVar5 + 7] = local_117[iVar5 + 7] ^ local_14[(iVar5 + 7 + uVar6 & 3) - uVar6];
        iVar5 = iVar4;
      } while (iVar4 < iVar9 + -9);
    }
    if (iVar4 < iVar9 + -1) {
      do {
        uVar6 = iVar4 >> 0x1f & 3;
        local_117[iVar4] = local_117[iVar4] ^ local_14[(iVar4 + uVar6 & 3) - uVar6];
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar9 + -1);
    }
  }
  if ((iVar9 + -2 < (int)(uint)local_117[0]) || ((int)(local_117[0] + 2) < iVar9 + -2)) {
    local_117[0] = 0;
  }
  local_117[local_117[0] + 1] = 0;
  (**(code **)(*param_1 + 0x29c))(param_1,local_117 + 1);
  return;
}


