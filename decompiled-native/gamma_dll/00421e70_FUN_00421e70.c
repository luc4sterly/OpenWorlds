// 00421e70 FUN_00421e70 [Global]
// program: gamma.dll

void __cdecl FUN_00421e70(int param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  iVar2 = 0;
  if (0 < param_1) {
    if (8 < param_1) {
      do {
        *(undefined1 *)(param_3 + 2 + iVar2 * 4) = *param_2;
        *(undefined1 *)(param_3 + 1 + iVar2 * 4) = param_2[1];
        *(undefined1 *)(param_3 + iVar2 * 4) = param_2[2];
        *(undefined1 *)(param_3 + 3 + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 6 + iVar2 * 4) = param_2[4];
        *(undefined1 *)(param_3 + 5 + iVar2 * 4) = param_2[5];
        *(undefined1 *)(param_3 + 4 + iVar2 * 4) = param_2[6];
        *(undefined1 *)(param_3 + 7 + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 10 + iVar2 * 4) = param_2[8];
        *(undefined1 *)(param_3 + 9 + iVar2 * 4) = param_2[9];
        *(undefined1 *)(param_3 + 8 + iVar2 * 4) = param_2[10];
        *(undefined1 *)(param_3 + 0xb + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 0xe + iVar2 * 4) = param_2[0xc];
        *(undefined1 *)(param_3 + 0xd + iVar2 * 4) = param_2[0xd];
        *(undefined1 *)(param_3 + 0xc + iVar2 * 4) = param_2[0xe];
        *(undefined1 *)(param_3 + 0xf + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 0x12 + iVar2 * 4) = param_2[0x10];
        *(undefined1 *)(param_3 + 0x11 + iVar2 * 4) = param_2[0x11];
        *(undefined1 *)(param_3 + 0x10 + iVar2 * 4) = param_2[0x12];
        *(undefined1 *)(param_3 + 0x13 + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 0x16 + iVar2 * 4) = param_2[0x14];
        *(undefined1 *)(param_3 + 0x15 + iVar2 * 4) = param_2[0x15];
        *(undefined1 *)(param_3 + 0x14 + iVar2 * 4) = param_2[0x16];
        *(undefined1 *)(param_3 + 0x17 + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 0x1a + iVar2 * 4) = param_2[0x18];
        *(undefined1 *)(param_3 + 0x19 + iVar2 * 4) = param_2[0x19];
        *(undefined1 *)(param_3 + 0x18 + iVar2 * 4) = param_2[0x1a];
        *(undefined1 *)(param_3 + 0x1b + iVar2 * 4) = 0;
        *(undefined1 *)(param_3 + 0x1e + iVar2 * 4) = param_2[0x1c];
        *(undefined1 *)(param_3 + 0x1d + iVar2 * 4) = param_2[0x1d];
        *(undefined1 *)(param_3 + 0x1c + iVar2 * 4) = param_2[0x1e];
        *(undefined1 *)(param_3 + 0x1f + iVar2 * 4) = 0;
        iVar2 = iVar2 + 8;
        param_2 = param_2 + 0x20;
      } while (iVar2 < param_1 + -8);
    }
    for (; iVar2 < param_1; iVar2 = iVar2 + 1) {
      *(undefined1 *)(param_3 + 2 + iVar2 * 4) = *param_2;
      *(undefined1 *)(param_3 + 1 + iVar2 * 4) = param_2[1];
      *(undefined1 *)(param_3 + iVar2 * 4) = param_2[2];
      *(undefined1 *)(param_3 + 3 + iVar2 * 4) = 0;
      param_2 = param_2 + 4;
    }
  }
  uVar1 = DAT_004714a8;
  if (iVar2 < 0x100) {
    uStack_11 = (undefined1)((uint)DAT_004714a8 >> 0x18);
    uStack_13 = (undefined1)((uint)DAT_004714a8 >> 8);
    uStack_12 = (undefined1)((uint)DAT_004714a8 >> 0x10);
    do {
      local_14 = (undefined1)uVar1;
      *(undefined1 *)(param_3 + iVar2 * 4) = local_14;
      *(undefined1 *)(param_3 + 1 + iVar2 * 4) = uStack_13;
      *(undefined1 *)(param_3 + 2 + iVar2 * 4) = uStack_12;
      *(undefined1 *)(param_3 + 3 + iVar2 * 4) = uStack_11;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
  }
  return;
}


