// 00451a50 FUN_00451a50 [Global]
// program: gamma.dll

undefined2 * __thiscall
FUN_00451a50(int *param_1,undefined2 *param_2,undefined2 *param_3,undefined1 param_4,
            undefined1 *param_5)

{
  undefined1 uVar1;
  
  for (; param_2 < param_3; param_2 = param_2 + 1) {
    uVar1 = (**(code **)(*param_1 + 0x2c))(*param_2,param_4);
    *param_5 = uVar1;
    param_5 = param_5 + 1;
  }
  return param_3;
}


