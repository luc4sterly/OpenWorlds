// 004046d5 FUN_004046d5 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_004046d5(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00406514(param_1,in_EAX);
  uVar2 = FUN_00404645(extraout_ECX,(uint)((ulonglong)lVar1 >> 0x20));
  return CONCAT44(param_2,(int)uVar2);
}


