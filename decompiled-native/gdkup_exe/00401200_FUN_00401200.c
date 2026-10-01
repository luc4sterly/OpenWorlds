// 00401200 FUN_00401200 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00401200(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_004011d4(param_1,param_2);
  *(undefined4 *)uVar1 = &PTR_LAB_004088bc;
  return CONCAT44(param_2,(undefined4 *)uVar1);
}


