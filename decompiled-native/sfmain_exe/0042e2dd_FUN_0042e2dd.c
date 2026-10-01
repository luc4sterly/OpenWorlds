// 0042e2dd FUN_0042e2dd [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042e2dd(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *in_EAX;
  DWORD DVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *extraout_ECX_02;
  undefined4 *puVar3;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar4 = param_2;
  if (in_EAX[2] == 0) {
    FUN_0042d8e0(in_EAX);
    in_EAX = extraout_ECX;
    uVar4 = extraout_EDX;
  }
  if (((*(byte *)((int)in_EAX + 0xd) & 0x20) != 0) && ((*(byte *)((int)in_EAX + 0xd) & 6) != 0)) {
    FUN_0042f659(in_EAX,uVar4);
    in_EAX = extraout_ECX_00;
  }
  uVar4 = in_EAX[2];
  *in_EAX = uVar4;
  uVar1 = in_EAX[3];
  uVar5 = CONCAT22((short)((uint)uVar4 >> 0x10),CONCAT11(*(undefined1 *)(in_EAX + 3),(char)uVar4)) &
          0xfffffbff;
  *(char *)(in_EAX + 3) = (char)(uVar5 >> 8);
  if (((uVar1 & 0x2400) == 0x2400) && (in_EAX[4] == 0)) {
    in_EAX[1] = 0;
    uVar6 = FUN_0043213b(in_EAX,uVar5);
    puVar3 = extraout_ECX_01;
    if ((int)uVar6 != -1) {
      *(char *)*extraout_ECX_01 = (char)uVar6;
      extraout_ECX_01[1] = 1;
    }
  }
  else {
    DVar2 = FUN_0042e19c();
    extraout_ECX_02[1] = DVar2;
    puVar3 = extraout_ECX_02;
  }
  if ((int)puVar3[1] < 1) {
    if (puVar3[1] == 0) {
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 0x10;
    }
    else {
      puVar3[1] = 0;
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 0x20;
    }
  }
  return CONCAT44(param_2,puVar3[1]);
}


