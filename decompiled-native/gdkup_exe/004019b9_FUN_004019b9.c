// 004019b9 FUN_004019b9 [Global]
// programa: gdkup.exe

undefined4 __thiscall FUN_004019b9(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 extraout_ECX;
  
  bVar1 = FUN_004018f8(this,&DAT_0040a1b8);
  if ((CONCAT31(extraout_var,bVar1) == 0) &&
     (bVar1 = FUN_004018f8(extraout_ECX,&DAT_0040a1c8), CONCAT31(extraout_var_00,bVar1) == 0)) {
    *param_3 = 0;
    return 0x80004002;
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


