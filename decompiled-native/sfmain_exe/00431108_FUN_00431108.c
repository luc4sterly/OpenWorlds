// 00431108 FUN_00431108 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00431108(undefined4 param_1,undefined4 param_2)

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
  
  uVar4 = (*(code *)PTR_FUN_0043e7ec)();
  uVar3 = (uint)(uVar4 >> 0x20);
  pcVar5 = *(code **)((int)uVar4 + 0x58 + in_EAX * 8);
  if (uVar4 < 0x200000000) {
    if (uVar3 == 1) {
      if (pcVar5 == (code *)0x2) {
        FUN_0042d4dd(extraout_ECX);
        uVar3 = extraout_EDX;
      }
LAB_0043122f:
      if (((pcVar5 != (code *)0x1) && (pcVar5 != (code *)0x2)) && (pcVar5 != (code *)0x3)) {
        iVar2 = (*(code *)PTR_FUN_0043e7ec)(pcVar5,param_2,param_1);
        *(undefined4 *)(iVar2 + 0x58 + uVar3 * 8) = 2;
        (*pcVar5)();
      }
      iVar2 = FUN_00431061();
      if (iVar2 == 0) {
        FUN_004310cc(extraout_ECX_00,extraout_EDX_00);
      }
      goto LAB_00431264;
    }
  }
  else {
    if (uVar4 < 0x300000000) {
      FUN_00431141(extraout_ECX,uVar3);
LAB_00431264:
      uVar1 = 0;
      goto LAB_00431266;
    }
    if (uVar4 < 0xd00000000) goto LAB_0043122f;
  }
  uVar1 = 0xffffffff;
LAB_00431266:
  return CONCAT44(param_2,uVar1);
}


