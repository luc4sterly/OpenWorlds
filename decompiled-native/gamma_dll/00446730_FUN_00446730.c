// 00446730 FUN_00446730 [Global]
// program: gamma.dll

undefined4 FUN_00446730(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = 0;
    *param_2 = 1;
  }
  return uVar1;
}


