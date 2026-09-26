// 0040fa60 FUN_0040fa60 [Global]
// programa: sfmain.exe

void FUN_0040fa60(void)

{
  int in_EAX;
  
  if ((((*(byte *)(in_EAX + 2) & 2) != 0) && (0x10 < *(int *)(in_EAX + 0x14))) &&
     (DAT_00445b54 = DAT_00445b54 + 0x10, (*(byte *)(in_EAX + 2) & 4) != 0)) {
    *(byte *)(in_EAX + 2) = *(byte *)(in_EAX + 2) & 0xfb;
  }
  *(uint *)(in_EAX + 0x14) = *(uint *)(in_EAX + 0x14) & 0xfff;
  return;
}


