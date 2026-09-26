// 00403208 FUN_00403208 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_00403208(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  
  puVar1 = (undefined4 *)FUN_004041e1(in_EAX,(int)auStack_28);
  local_20 = param_2;
  FUN_004043d8(extraout_ECX,(int)auStack_28);
  *puVar1 = *(undefined4 *)*puVar1;
  return extraout_ECX_00;
}


