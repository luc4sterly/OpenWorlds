// 00430d9e FUN_00430d9e [Global]
// programa: sfmain.exe

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00430d9e(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  HMODULE pHVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined4 uStack_1c;
  undefined1 local_18 [8];
  
  uStack_1c = 0x430db1;
  FUN_00431cf6();
  iVar1 = -(DAT_0043eac8 + 3U & 0xfffffffc);
  puVar6 = local_18 + iVar1;
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x430dce;
  FUN_00408098(local_18 + iVar1,0);
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x430dd8;
  FUN_0042d3c8(extraout_ECX,extraout_ECX);
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x430de9;
  uVar8 = FUN_00432432(extraout_ECX_00,DAT_0043e854 + 3U & 0xfffffffc);
  uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
  if (uVar5 < (uint)uVar8) {
    iVar2 = -uVar5;
    puVar6 = local_18 + iVar2 + iVar1;
    _DAT_0043e858 = local_18 + iVar2 + iVar1;
  }
  else {
    _DAT_0043e858 = (undefined1 *)0x0;
  }
  _DAT_0043e858 = _DAT_0043e858 + DAT_0043e854;
  *(undefined4 *)(puVar6 + -4) = 0x430e0b;
  FUN_00432461();
  *(undefined4 *)(puVar6 + -4) = 0x430e10;
  GetCommandLineA();
  *(undefined4 *)(puVar6 + -4) = 0x430e15;
  uVar8 = FUN_0042cd01(extraout_ECX_01,extraout_EDX);
  pcVar3 = (char *)uVar8;
  if (*pcVar3 != '\"') {
    do {
      if (((&DAT_00437bd8)[(byte)(*pcVar3 + 1)] & 2) != 0) goto LAB_00430e57;
      if (*pcVar3 == '\0') goto LAB_00430e57;
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  do {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\"') break;
  } while (*pcVar3 != '\0');
  if (*pcVar3 == '\0') goto LAB_00430e57;
  do {
    pcVar3 = pcVar3 + 1;
LAB_00430e57:
  } while (((&DAT_00437bd8)[(byte)(*pcVar3 + 1)] & 2) != 0);
  *(undefined4 *)(puVar6 + -4) = 10;
  *(char **)(puVar6 + -8) = pcVar3;
  *(undefined4 *)(puVar6 + -0xc) = 0;
  *(undefined4 *)(puVar6 + -0x10) = 0;
  *(undefined4 *)(puVar6 + -0x14) = 0x430e7c;
  pHVar4 = GetModuleHandleA(*(LPCSTR *)(puVar6 + -0x10));
  *(HMODULE *)(puVar6 + -0x10) = pHVar4;
  puVar7 = puVar6 + -0x14;
  *(undefined4 *)(puVar6 + -0x14) = 0x430e83;
  (*_DAT_004e57bc)();
  *(undefined4 *)(puVar7 + -4) = 0x430e88;
  FUN_0042bd7e(extraout_ECX_02,extraout_EDX_00);
  return;
}


