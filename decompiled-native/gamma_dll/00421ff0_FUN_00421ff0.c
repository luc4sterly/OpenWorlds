// 00421ff0 FUN_00421ff0 [Global]
// programa: gamma.dll

void __cdecl FUN_00421ff0(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 local_414 [1024];
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  FUN_004197a0(0,0x100,local_414);
  puVar2 = local_414;
  iVar3 = 0;
  do {
    *(undefined1 *)(param_1 + 2 + iVar3 * 4) = *puVar2;
    *(undefined1 *)(param_1 + 1 + iVar3 * 4) = puVar2[1];
    *(undefined1 *)(param_1 + iVar3 * 4) = puVar2[2];
    *(undefined1 *)(param_1 + 3 + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 6 + iVar3 * 4) = puVar2[4];
    *(undefined1 *)(param_1 + 5 + iVar3 * 4) = puVar2[5];
    *(undefined1 *)(param_1 + 4 + iVar3 * 4) = puVar2[6];
    *(undefined1 *)(param_1 + 7 + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 10 + iVar3 * 4) = puVar2[8];
    *(undefined1 *)(param_1 + 9 + iVar3 * 4) = puVar2[9];
    *(undefined1 *)(param_1 + 8 + iVar3 * 4) = puVar2[10];
    *(undefined1 *)(param_1 + 0xb + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 0xe + iVar3 * 4) = puVar2[0xc];
    *(undefined1 *)(param_1 + 0xd + iVar3 * 4) = puVar2[0xd];
    *(undefined1 *)(param_1 + 0xc + iVar3 * 4) = puVar2[0xe];
    *(undefined1 *)(param_1 + 0xf + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 0x12 + iVar3 * 4) = puVar2[0x10];
    *(undefined1 *)(param_1 + 0x11 + iVar3 * 4) = puVar2[0x11];
    *(undefined1 *)(param_1 + 0x10 + iVar3 * 4) = puVar2[0x12];
    *(undefined1 *)(param_1 + 0x13 + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 0x16 + iVar3 * 4) = puVar2[0x14];
    *(undefined1 *)(param_1 + 0x15 + iVar3 * 4) = puVar2[0x15];
    *(undefined1 *)(param_1 + 0x14 + iVar3 * 4) = puVar2[0x16];
    *(undefined1 *)(param_1 + 0x17 + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 0x1a + iVar3 * 4) = puVar2[0x18];
    *(undefined1 *)(param_1 + 0x19 + iVar3 * 4) = puVar2[0x19];
    *(undefined1 *)(param_1 + 0x18 + iVar3 * 4) = puVar2[0x1a];
    *(undefined1 *)(param_1 + 0x1b + iVar3 * 4) = 0;
    *(undefined1 *)(param_1 + 0x1e + iVar3 * 4) = puVar2[0x1c];
    *(undefined1 *)(param_1 + 0x1d + iVar3 * 4) = puVar2[0x1d];
    *(undefined1 *)(param_1 + 0x1c + iVar3 * 4) = puVar2[0x1e];
    *(undefined1 *)(param_1 + 0x1f + iVar3 * 4) = 0;
    uVar1 = DAT_004714a8;
    iVar3 = iVar3 + 8;
    puVar2 = puVar2 + 0x20;
  } while (iVar3 < 0x100);
  if (iVar3 < 0x100) {
    uStack_13 = (undefined1)((uint)DAT_004714a8 >> 8);
    puVar2 = (undefined1 *)(iVar3 * 4 + param_1);
    uStack_12 = (undefined1)((uint)DAT_004714a8 >> 0x10);
    uStack_11 = (undefined1)((uint)DAT_004714a8 >> 0x18);
    do {
      iVar3 = iVar3 + 1;
      local_14 = (undefined1)uVar1;
      *puVar2 = local_14;
      puVar2[1] = uStack_13;
      puVar2[2] = uStack_12;
      puVar2[3] = uStack_11;
      puVar2 = puVar2 + 4;
    } while (iVar3 < 0x100);
  }
  return;
}


