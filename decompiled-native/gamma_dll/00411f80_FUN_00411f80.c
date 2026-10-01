// 00411f80 FUN_00411f80 [Global]
// program: gamma.dll

undefined1 __thiscall FUN_00411f80(void *this,undefined4 param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int local_2c [2];
  undefined1 local_21;
  
  FUN_004049b0(this,local_2c);
  local_21 = DAT_00489371;
  piVar2 = (int *)FUN_00404a00(local_2c);
  uVar1 = (**(code **)(*piVar2 + 0x14))(param_1);
  FUN_00404dc0(local_2c);
  return uVar1;
}


