// 00433a81 FUN_00433a81 [Global]
// program: sfmain.exe

uint __fastcall FUN_00433a81(undefined4 param_1,int param_2)

{
  ulonglong uVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  int *in_EAX;
  uint uVar5;
  int iVar6;
  short sVar8;
  uint uVar9;
  int unaff_EBX;
  undefined1 *puVar10;
  uint uStack_14;
  byte bVar7;
  
  iVar6 = *in_EAX;
  uStack_14 = in_EAX[1];
  *(undefined1 *)(param_2 + unaff_EBX) = 0;
  puVar10 = (undefined1 *)(param_2 + unaff_EBX);
  do {
    uVar9 = 0;
    if (uStack_14 == 0) {
      uVar5 = uStack_14;
      if (iVar6 != 0) goto LAB_00433aab;
      sVar4 = 0;
    }
    else {
      uVar5 = uStack_14 / 10000;
      uVar9 = uStack_14 % 10000;
LAB_00433aab:
      uVar1 = CONCAT44(uVar9,iVar6);
      iVar6 = (int)(uVar1 / 10000);
      uVar3 = (ushort)(uVar1 % 10000);
      bVar7 = (byte)(uVar3 % 100);
      bVar2 = (byte)(uVar3 / 100);
      uVar9 = (uint)CONCAT11(bVar2 / 10,bVar2 % 10);
      sVar4 = CONCAT11(bVar7 / 10,bVar7 % 10);
      uStack_14 = uVar5;
    }
    sVar8 = (short)uVar9 + 0x3030;
    puVar10[-1] = (char)(sVar4 + 0x3030);
    if (unaff_EBX == 1) {
      return uStack_14;
    }
    puVar10[-2] = (char)((ushort)(sVar4 + 0x3030) >> 8);
    if (unaff_EBX == 2) {
      return uStack_14;
    }
    puVar10[-3] = (char)sVar8;
    if (unaff_EBX == 3) {
      return uStack_14;
    }
    puVar10[-4] = (char)((ushort)sVar8 >> 8);
    unaff_EBX = unaff_EBX + -4;
    puVar10 = puVar10 + -4;
    if (unaff_EBX == 0) {
      return uStack_14;
    }
  } while( true );
}


