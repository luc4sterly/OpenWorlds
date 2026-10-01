// 00404046 FUN_00404046 [Global]
// program: gdkup.exe

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00404046(void)

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
  
  uStack_1c = 0x404059;
  FUN_00405466();
  iVar1 = -(DAT_00408eac + 3U & 0xfffffffc);
  puVar6 = local_18 + iVar1;
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x404076;
  FUN_00402980(local_18 + iVar1,0);
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x404080;
  FUN_004034f5(extraout_ECX,extraout_ECX);
  *(undefined4 *)(local_18 + iVar1 + -4) = 0x404091;
  uVar8 = FUN_004059fc(extraout_ECX_00,DAT_00408e84 + 3U & 0xfffffffc);
  uVar5 = (uint)((ulonglong)uVar8 >> 0x20);
  if (uVar5 < (uint)uVar8) {
    iVar2 = -uVar5;
    puVar6 = local_18 + iVar2 + iVar1;
    _DAT_00408e88 = local_18 + iVar2 + iVar1;
  }
  else {
    _DAT_00408e88 = (undefined1 *)0x0;
  }
  _DAT_00408e88 = _DAT_00408e88 + DAT_00408e84;
  *(undefined4 *)(puVar6 + -4) = 0x4040b3;
  FUN_00405a2b();
  *(undefined4 *)(puVar6 + -4) = 0x4040b8;
  GetCommandLineA();
  *(undefined4 *)(puVar6 + -4) = 0x4040bd;
  uVar8 = FUN_00405421(extraout_ECX_01,extraout_EDX);
  pcVar3 = (char *)uVar8;
  if (*pcVar3 != '\"') {
    do {
      if (((&DAT_00408958)[(byte)(*pcVar3 + 1)] & 2) != 0) goto LAB_004040ff;
      if (*pcVar3 == '\0') goto LAB_004040ff;
      pcVar3 = pcVar3 + 1;
    } while( true );
  }
  do {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\"') break;
  } while (*pcVar3 != '\0');
  if (*pcVar3 == '\0') goto LAB_004040ff;
  do {
    pcVar3 = pcVar3 + 1;
LAB_004040ff:
  } while (((&DAT_00408958)[(byte)(*pcVar3 + 1)] & 2) != 0);
  *(undefined4 *)(puVar6 + -4) = 10;
  *(char **)(puVar6 + -8) = pcVar3;
  *(undefined4 *)(puVar6 + -0xc) = 0;
  *(undefined4 *)(puVar6 + -0x10) = 0;
  *(undefined4 *)(puVar6 + -0x14) = 0x404124;
  pHVar4 = GetModuleHandleA(*(LPCSTR *)(puVar6 + -0x10));
  *(HMODULE *)(puVar6 + -0x10) = pHVar4;
  puVar7 = puVar6 + -0x14;
  *(undefined4 *)(puVar6 + -0x14) = 0x40412b;
  (*DAT_0040b468)();
  *(undefined4 *)(puVar7 + -4) = 0x404130;
  FUN_004027eb(extraout_ECX_02,extraout_EDX_00);
  return;
}


