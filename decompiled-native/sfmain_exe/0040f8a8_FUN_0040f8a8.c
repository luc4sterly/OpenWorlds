// 0040f8a8 FUN_0040f8a8 [Global]
// programa: sfmain.exe

void __fastcall FUN_0040f8a8(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  
  *(byte *)(in_EAX + 2) = *(byte *)(in_EAX + 2) | 2;
  iVar1 = FUN_0040a952(param_1,in_EAX + 0x1c);
  *(int *)(in_EAX + 0x14) = iVar1;
  return;
}


