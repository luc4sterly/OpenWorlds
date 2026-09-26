// 00432f62 FUN_00432f62 [Global]
// programa: sfmain.exe

int __fastcall FUN_00432f62(undefined4 param_1,int param_2)

{
  uint uVar1;
  char *extraout_ECX;
  char *extraout_ECX_00;
  char *pcVar2;
  char *extraout_ECX_01;
  char *extraout_ECX_02;
  char *pcVar3;
  undefined1 uVar4;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint uVar5;
  uint extraout_EDX_01;
  int iVar6;
  bool bVar7;
  undefined8 uVar8;
  
  (*(code *)PTR_FUN_0043e7f0)();
  pcVar2 = extraout_ECX;
  uVar5 = extraout_EDX;
  if (*(int *)(extraout_EDX + 8) == 0) {
    FUN_0042d8e0(extraout_ECX);
    pcVar2 = extraout_ECX_00;
    uVar5 = extraout_EDX_00;
  }
  bVar7 = (*(byte *)(param_2 + 0xd) & 4) != 0;
  if (bVar7) {
    uVar5 = CONCAT31((int3)(uVar5 >> 8),*(byte *)(param_2 + 0xd)) & 0xfffffff9;
    uVar4 = (undefined1)uVar5;
    uVar5 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(uVar4,uVar4)) | 0x200;
    *(char *)(param_2 + 0xd) = (char)(uVar5 >> 8);
  }
  iVar6 = 0;
  pcVar3 = pcVar2;
  do {
    if (*pcVar3 == '\0') goto LAB_00432fb8;
    uVar1 = FUN_0042bb35();
    pcVar3 = extraout_ECX_01;
    uVar5 = extraout_EDX_01;
  } while (uVar1 != 0xffffffff);
  iVar6 = -1;
LAB_00432fb8:
  if ((bVar7) && (*(byte *)(param_2 + 0xd) = *(byte *)(param_2 + 0xd) & 0xf9 | 4, iVar6 == 0)) {
    uVar8 = FUN_0042d957(pcVar3,uVar5);
    iVar6 = (int)uVar8;
    pcVar3 = extraout_ECX_02;
  }
  if (iVar6 == 0) {
    iVar6 = (int)pcVar3 - (int)pcVar2;
  }
  (*(code *)PTR_FUN_0043e7f4)();
  return iVar6;
}


