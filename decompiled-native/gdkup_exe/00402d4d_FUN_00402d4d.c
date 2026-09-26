// 00402d4d FUN_00402d4d [Global]
// programa: gdkup.exe

undefined4 FUN_00402d4d(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  LPCSTR in_EAX;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar4;
  undefined4 extraout_ECX_02;
  undefined4 uVar5;
  uint unaff_EBX;
  undefined8 uVar6;
  uint uVar7;
  
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfc;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | unaff_EBX;
  uVar6 = FUN_0040387b();
  uVar5 = (undefined4)((ulonglong)uVar6 >> 0x20);
  if (((uint)uVar6 & 0xff) == 0x72) {
    uVar1 = 0;
    if ((unaff_EBX & 2) != 0) {
      uVar1 = 2;
    }
    if ((unaff_EBX & 0x40) == 0) {
      uVar3 = CONCAT11(1,uVar1);
    }
    else {
      uVar3 = CONCAT11(2,uVar1);
    }
    uVar7 = 0;
  }
  else {
    bVar2 = ((unaff_EBX & 1) != 0) + 0x21;
    if ((unaff_EBX & 0x80) == 0) {
      bVar2 = bVar2 | 0x40;
    }
    else {
      bVar2 = bVar2 | 0x10;
    }
    if ((unaff_EBX & 0x40) == 0) {
      uVar3 = CONCAT11(1,bVar2);
    }
    else {
      uVar3 = CONCAT11(2,bVar2);
    }
    uVar7 = 0x180;
  }
  uVar6 = FUN_004038ad(extraout_ECX,uVar5,in_EAX,(uint)uVar3,uVar5,uVar7);
  *(int *)(extraout_ECX_00 + 0x10) = (int)uVar6;
  if (*(int *)(extraout_ECX_00 + 0x10) == -1) {
    FUN_00403b1c();
    return 0;
  }
  *(undefined4 *)(extraout_ECX_00 + 4) = 0;
  *(undefined4 *)(extraout_ECX_00 + 8) = 0;
  *(undefined4 *)(extraout_ECX_00 + 0x14) = 0;
  iVar4 = extraout_ECX_00;
  if ((unaff_EBX & 0x80) != 0) {
    FUN_00403bb5(extraout_ECX_00,0);
    iVar4 = extraout_ECX_01;
  }
  FUN_00403ca9(iVar4);
  return extraout_ECX_02;
}


