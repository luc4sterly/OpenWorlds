// 0042c5e5 FUN_0042c5e5 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0042c5e5(uint param_1,int param_2)

{
  uint uVar1;
  int *in_EAX;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_EDX;
  uint unaff_EBX;
  bool bVar2;
  
  if (0x7fffffff < param_1) {
    return 0xffffffff;
  }
  if (unaff_EBX < 0x200) {
    bVar2 = unaff_EBX == 0x100;
  }
  else {
    if (unaff_EBX < 0x201) goto LAB_0042c611;
    bVar2 = unaff_EBX == 0x400;
  }
  if (!bVar2) {
    return 0xffffffff;
  }
LAB_0042c611:
  if ((param_2 != 0) && (param_1 == 0)) {
    return 0xffffffff;
  }
  (*(code *)PTR_FUN_0043e7f0)();
  FUN_0042e727(extraout_ECX);
  if (extraout_ECX_00 != 0) {
    in_EAX[5] = extraout_ECX_00;
  }
  in_EAX[2] = extraout_EDX;
  *(byte *)((int)in_EAX + 0xd) = *(byte *)((int)in_EAX + 0xd) & 0xf8;
  uVar1 = in_EAX[3];
  *in_EAX = extraout_EDX;
  in_EAX[3] = uVar1 | unaff_EBX;
  if (extraout_EDX == 0) {
    FUN_0042d8e0(uVar1 | unaff_EBX);
  }
  (*(code *)PTR_FUN_0043e7f4)();
  return 0;
}


