// 00404833 FUN_00404833 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00404833(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_EDX;
  uint uVar3;
  undefined4 extraout_EDX_00;
  ulonglong uVar4;
  code *pcVar5;
  
  uVar4 = (*(code *)PTR_FUN_00408b38)();
  uVar3 = (uint)(uVar4 >> 0x20);
  pcVar5 = *(code **)((int)uVar4 + 0x58 + in_EAX * 8);
  if (uVar4 < 0x200000000) {
    if (uVar3 == 1) {
      if (pcVar5 == (code *)0x2) {
        FUN_004065df(extraout_ECX);
        uVar3 = extraout_EDX;
      }
LAB_0040495a:
      if (((pcVar5 != (code *)0x1) && (pcVar5 != (code *)0x2)) && (pcVar5 != (code *)0x3)) {
        iVar2 = (*(code *)PTR_FUN_00408b38)(pcVar5,param_2,param_1);
        *(undefined4 *)(iVar2 + 0x58 + uVar3 * 8) = 2;
        (*pcVar5)();
      }
      iVar2 = FUN_0040478c();
      if (iVar2 == 0) {
        FUN_004047f7(extraout_ECX_00,extraout_EDX_00);
      }
      goto LAB_0040498f;
    }
  }
  else {
    if (uVar4 < 0x300000000) {
      FUN_0040486c(extraout_ECX,uVar3);
LAB_0040498f:
      uVar1 = 0;
      goto LAB_00404991;
    }
    if (uVar4 < 0xd00000000) goto LAB_0040495a;
  }
  uVar1 = 0xffffffff;
LAB_00404991:
  return CONCAT44(param_2,uVar1);
}


