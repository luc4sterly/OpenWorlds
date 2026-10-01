// 0042bb35 FUN_0042bb35 [Global]
// program: sfmain.exe

uint FUN_0042bb35(void)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  undefined4 extraout_ECX;
  uint extraout_ECX_00;
  int *extraout_EDX;
  int extraout_EDX_00;
  int *extraout_EDX_01;
  int *piVar3;
  undefined8 uVar4;
  
  (*(code *)PTR_FUN_0043e7f0)();
  if ((*(byte *)(extraout_EDX + 3) & 2) == 0) {
    FUN_0042d8ad(extraout_ECX,extraout_EDX);
    *(byte *)(extraout_EDX_00 + 0xc) = *(byte *)(extraout_EDX_00 + 0xc) | 0x20;
LAB_0042bb59:
    (*(code *)PTR_FUN_0043e7f4)();
    uVar2 = 0xffffffff;
  }
  else {
    piVar3 = extraout_EDX;
    if (extraout_EDX[2] == 0) {
      FUN_0042d8e0(extraout_ECX);
      piVar3 = extraout_EDX_01;
    }
    uVar2 = 0x400;
    if ((in_EAX == 10) && (uVar2 = 0x600, (*(byte *)(piVar3 + 3) & 0x40) == 0)) {
      *(byte *)((int)piVar3 + 0xd) = *(byte *)((int)piVar3 + 0xd) | 0x10;
      *(undefined1 *)*piVar3 = 0xd;
      iVar1 = piVar3[1];
      *piVar3 = *piVar3 + 1;
      piVar3[1] = iVar1 + 1;
      if (iVar1 + 1 == piVar3[5]) {
        uVar4 = FUN_0042d957(0x600,piVar3);
        piVar3 = (int *)((ulonglong)uVar4 >> 0x20);
        uVar2 = extraout_ECX_00;
        if ((int)uVar4 != 0) goto LAB_0042bb59;
      }
    }
    *(byte *)((int)piVar3 + 0xd) = *(byte *)((int)piVar3 + 0xd) | 0x10;
    *(char *)*piVar3 = (char)in_EAX;
    iVar1 = piVar3[1];
    *piVar3 = *piVar3 + 1;
    piVar3[1] = iVar1 + 1;
    if (((uVar2 & piVar3[3]) != 0) || (iVar1 + 1 == piVar3[5])) {
      uVar4 = FUN_0042d957(uVar2,piVar3);
      if ((int)uVar4 != 0) goto LAB_0042bb59;
    }
    (*(code *)PTR_FUN_0043e7f4)();
    uVar2 = in_EAX & 0xff;
  }
  return uVar2;
}


