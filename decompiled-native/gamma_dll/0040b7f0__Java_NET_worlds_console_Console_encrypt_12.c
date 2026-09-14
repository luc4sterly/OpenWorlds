// 0040b7f0 _Java_NET_worlds_console_Console_encrypt@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Console_encrypt_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  DWORD DVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int local_27c;
  byte local_278 [260];
  char local_174 [356];
  
                    /* 0xb7f0  20  _Java_NET_worlds_console_Console_encrypt@12 */
  pcVar3 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_0044d6b0((char *)(local_278 + 2),pcVar3);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar3);
  local_27c = -1;
  pbVar6 = local_278 + 2;
  do {
    if (local_27c == 0) break;
    local_27c = local_27c + -1;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
  } while (bVar1 != 0);
  local_27c = -2 - local_27c;
  if (0xff < local_27c) {
    local_27c = 0xff;
  }
  DVar4 = timeGetTime();
  local_278[0] = (byte)DVar4 ^ (byte)(DVar4 >> 8) ^ (byte)(DVar4 >> 0x10) ^ (byte)(DVar4 >> 0x18);
  local_278[1] = (undefined1)local_27c;
  for (local_27c = local_27c + 2; local_27c != (local_27c / 3) * 3; local_27c = local_27c + 1) {
    local_278[local_27c] = 0;
  }
  local_174[0x160] = (char)DAT_0049fa6c;
  local_174[0x161] = (char)((uint)DAT_0049fa6c >> 8);
  local_174[0x161] = local_174[0x161] ^ local_278[0];
  local_174[0x160] = local_174[0x160] ^ local_278[0];
  local_174[0x162] = (char)((uint)DAT_0049fa6c >> 0x10);
  local_174[0x163] = (char)((uint)DAT_0049fa6c >> 0x18);
  local_174[0x162] = local_174[0x162] ^ local_278[0];
  local_174[0x163] = local_174[0x163] ^ local_278[0];
  iVar7 = 0;
  if (local_27c != 1 && -1 < local_27c + -1) {
    iVar8 = iVar7;
    if (8 < local_27c + -1) {
      do {
        uVar5 = iVar8 >> 0x1f & 3;
        local_278[iVar8 + 1] =
             local_278[iVar8 + 1] ^ local_174[((iVar8 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 1 >> 0x1f & 3;
        local_278[iVar8 + 2] =
             local_278[iVar8 + 2] ^ local_174[((iVar8 + 1 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 2 >> 0x1f & 3;
        local_278[iVar8 + 3] =
             local_278[iVar8 + 3] ^ local_174[((iVar8 + 2 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 3 >> 0x1f & 3;
        local_278[iVar8 + 4] =
             local_278[iVar8 + 4] ^ local_174[((iVar8 + 3 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 4 >> 0x1f & 3;
        local_278[iVar8 + 5] =
             local_278[iVar8 + 5] ^ local_174[((iVar8 + 4 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 5 >> 0x1f & 3;
        local_278[iVar8 + 6] =
             local_278[iVar8 + 6] ^ local_174[((iVar8 + 5 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 6 >> 0x1f & 3;
        local_278[iVar8 + 7] =
             local_278[iVar8 + 7] ^ local_174[((iVar8 + 6 + uVar5 & 3) - uVar5) + 0x160];
        uVar5 = iVar8 + 7 >> 0x1f & 3;
        iVar7 = iVar8 + 8;
        local_278[iVar8 + 8] =
             local_278[iVar8 + 8] ^ local_174[((iVar8 + 7 + uVar5 & 3) - uVar5) + 0x160];
        iVar8 = iVar7;
      } while (iVar7 < local_27c + -9);
    }
    if (iVar7 < local_27c + -1) {
      do {
        uVar5 = iVar7 >> 0x1f & 3;
        local_278[iVar7 + 1] =
             local_278[iVar7 + 1] ^ local_174[((iVar7 + uVar5 & 3) - uVar5) + 0x160];
        iVar7 = iVar7 + 1;
      } while (iVar7 < local_27c + -1);
    }
  }
  iVar7 = 0;
  pcVar3 = local_174;
  if (0 < local_27c) {
    do {
      pbVar6 = local_278 + iVar7;
      iVar8 = iVar7 + 1;
      iVar2 = iVar7 + 2;
      iVar7 = iVar7 + 3;
      uVar5 = (uint)local_278[iVar8] * 0x100 + (uint)*pbVar6 * 0x10000 + (uint)local_278[iVar2];
      pcVar3[3] = ((byte)uVar5 & 0x3f) + 0x20;
      pcVar3[2] = ((byte)(uVar5 >> 6) & 0x3f) + 0x20;
      pcVar3[1] = ((byte)(uVar5 >> 0xc) & 0x3f) + 0x20;
      *pcVar3 = (char)(uVar5 >> 0x12) + ' ';
      pcVar3 = pcVar3 + 4;
    } while (iVar7 < local_27c);
  }
  *pcVar3 = '\0';
  (**(code **)(*param_1 + 0x29c))(param_1,local_174);
  return;
}


