// 004041b8 FUN_004041b8 [Global]
// programa: gdkup.exe

int __fastcall FUN_004041b8(undefined4 param_1,int param_2)

{
  int in_EAX;
  undefined8 uVar1;
  
  uVar1 = FUN_00405a5c(param_1,param_2 + -1);
  return *(int *)(in_EAX + 0xc) + (int)((ulonglong)uVar1 >> 0x20) * (int)uVar1;
}


