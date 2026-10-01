// 0042d849 FUN_0042d849 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042d849(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  undefined4 extraout_ECX;
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_00431f96(param_1,in_EAX);
  uVar2 = FUN_0042d7b9(extraout_ECX,(uint)((ulonglong)lVar1 >> 0x20));
  return CONCAT44(param_2,(int)uVar2);
}


