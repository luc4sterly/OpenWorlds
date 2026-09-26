// 00402f36 FUN_00402f36 [Global]
// programa: gdkup.exe

undefined1 * FUN_00402f36(void)

{
  uint uVar1;
  undefined1 *in_EAX;
  int iVar2;
  int extraout_ECX;
  int iVar3;
  int extraout_ECX_00;
  char *extraout_EDX;
  char *pcVar4;
  undefined1 *puVar5;
  int unaff_EBX;
  bool bVar6;
  undefined8 uVar7;
  int iStack_14;
  
  (*(code *)PTR_FUN_00408b3c)();
  uVar1 = *(uint *)(unaff_EBX + 0xc);
  *(byte *)(unaff_EBX + 0xc) = *(byte *)(unaff_EBX + 0xc) & 0xcf;
  iVar3 = extraout_ECX;
  pcVar4 = extraout_EDX;
  do {
    uVar7 = CONCAT44(pcVar4,iStack_14);
    if (iVar3 + -1 < 1) break;
    uVar7 = FUN_00403cda(iVar3 + -1,pcVar4);
    pcVar4 = (char *)((ulonglong)uVar7 >> 0x20);
    iVar2 = (int)uVar7;
    if (iVar2 == -1) break;
    iStack_14._0_1_ = (char)uVar7;
    *pcVar4 = (char)iStack_14;
    pcVar4 = pcVar4 + 1;
    uVar7 = CONCAT44(pcVar4,iVar2);
    bVar6 = (char)iStack_14 != '\n';
    iVar3 = extraout_ECX_00;
    iStack_14 = iVar2;
  } while (bVar6);
  puVar5 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
  iStack_14 = (int)uVar7;
  if ((iStack_14 == -1) && ((puVar5 == in_EAX || ((*(byte *)(unaff_EBX + 0xc) & 0x20) != 0)))) {
    in_EAX = (undefined1 *)0x0;
  }
  else {
    *puVar5 = 0;
  }
  *(uint *)(unaff_EBX + 0xc) = *(uint *)(unaff_EBX + 0xc) | uVar1 & 0x30;
  (*(code *)PTR_FUN_00408b40)();
  return in_EAX;
}


