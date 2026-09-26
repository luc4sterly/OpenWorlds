// 00401701 FUN_00401701 [Global]
// programa: gdkup.exe

undefined4 __thiscall FUN_00401701(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 extraout_ECX;
  
  bVar1 = FUN_004018f8(this,&DAT_0040a1b8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = FUN_004018f8(extraout_ECX,&DAT_0040a1f8);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      *param_3 = 0;
      return 0x80004002;
    }
    *param_3 = param_1;
  }
  else {
    *param_3 = param_1;
  }
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


