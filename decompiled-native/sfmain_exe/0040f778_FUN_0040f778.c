// 0040f778 FUN_0040f778 [Global]
// programa: sfmain.exe

void FUN_0040f778(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  int in_EAX;
  byte local_1c;
  byte bStack_1a;
  
  uVar2 = DAT_00445b50;
  FUN_00401010((short *)&DAT_00445b50,(byte *)(in_EAX + 0x1c));
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) - (*(int *)(in_EAX + 0x14) >> 0x1f) >> 1;
  pbVar1 = (byte *)(in_EAX + 0x1c) + *(int *)(in_EAX + 0x14);
  *pbVar1 = (byte)((uint)uVar2 >> 8);
  local_1c = (byte)uVar2;
  pbVar1[1] = local_1c;
  bStack_1a = (byte)((uint)uVar2 >> 0x10);
  pbVar1[2] = bStack_1a;
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 3;
  return;
}


