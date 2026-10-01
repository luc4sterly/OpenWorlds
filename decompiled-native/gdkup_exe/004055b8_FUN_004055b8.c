// 004055b8 FUN_004055b8 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_004055b8(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  uint extraout_EDX;
  uint uVar1;
  
  FUN_0040386d(param_1,in_EAX);
  uVar1 = extraout_EDX;
  if ((((extraout_EDX != 0x7b) && (extraout_EDX != 0xce)) && (extraout_EDX != 0xb7)) &&
     (0x13 < extraout_EDX)) {
    uVar1 = 0x13;
  }
  FUN_00403848(extraout_ECX,uVar1);
  return CONCAT44(param_2,0xffffffff);
}


