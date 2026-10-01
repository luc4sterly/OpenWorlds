// 0042d500 FUN_0042d500 [Global]
// program: sfmain.exe

undefined4 FUN_0042d500(void)

{
  uint uVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  byte *extraout_EDX;
  byte *extraout_EDX_00;
  byte *pbVar3;
  undefined4 extraout_EDX_01;
  bool bVar4;
  
  (*(code *)PTR_FUN_0043e7f0)();
  uVar1 = *(uint *)(in_EAX + 0xc);
  *(byte *)(in_EAX + 0xc) = *(byte *)(in_EAX + 0xc) & 0xcf;
  pbVar3 = extraout_EDX;
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_0042d8e0(0);
    pbVar3 = extraout_EDX_00;
  }
  bVar4 = (*(byte *)(in_EAX + 0xd) & 4) != 0;
  if (bVar4) {
    *(byte *)(in_EAX + 0xd) = *(byte *)(in_EAX + 0xd) & 0xfa | 1;
  }
  uVar2 = FUN_00430155(&LAB_0042d4ef,pbVar3);
  if (bVar4) {
    *(byte *)(in_EAX + 0xd) = *(byte *)(in_EAX + 0xd) & 0xfa | 4;
    FUN_0042d957(extraout_ECX,uVar2);
  }
  (*(code *)PTR_FUN_0043e7f4)();
  uVar2 = extraout_EDX_01;
  if ((*(byte *)(in_EAX + 0xc) & 0x20) != 0) {
    uVar2 = 0xffffffff;
  }
  *(uint *)(in_EAX + 0xc) = *(uint *)(in_EAX + 0xc) | uVar1 & 0x30;
  return uVar2;
}


